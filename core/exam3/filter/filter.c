#define _GNU_SOURCE
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
** Prints:
** Error: <system error message>
**
** Example:
** Error: Cannot allocate memory
**
** perror() automatically appends the strerror(errno) message.
*/
static int	error(void)
{
	perror("Error");
	return (1);
}

/*
** Append n bytes from src to our dynamic buffer.
**
** buf = dynamic buffer containing data not yet processed
** len = current amount of valid data in buf
** cap = allocated size of buf
**
** Example:
**
** Before:
**     buf = "hello"
**     len = 5
**     cap = 8
**
** Append "abc"
**
** After:
**     buf = "helloabc"
**     len = 8
*/
static int	append(char **buf, size_t *len, size_t *cap,
				char *src, size_t n)
{
	char	*tmp;
	size_t	new_cap;

	/*
	** If there is already enough room,
	** simply copy the new data at the end.
	*/
	if (*len + n <= *cap)
	{
		memcpy(*buf + *len, src, n);
		*len += n;
		return (0);
	}

	/*
	** Need more memory.
	**
	** If cap == 0:
	** allocate exactly what we need initially.
	**
	** Otherwise start from current capacity
	** and grow it.
	*/
	new_cap = (*cap == 0) ? (*len + n) : *cap;

	/*
	** Classic dynamic-array growth:
	** double capacity until it fits.
	**
	** Example:
	** cap = 8
	** need = 20
	**
	** 8 -> 16 -> 32
	*/
	while (new_cap < *len + n)
		new_cap *= 2;

	tmp = realloc(*buf, new_cap);
	if (!tmp)
		return (1);

	*buf = tmp;
	*cap = new_cap;

	/*
	** Copy new bytes after existing bytes.
	*/
	memcpy(*buf + *len, src, n);

	/*
	** Update used size.
	*/
	*len += n;

	return (0);
}

int	main(int ac, char **av)
{
	/*
	** Temporary read buffer.
	**
	** The tester may replace read()
	** so we cannot assume we'll receive
	** complete matches in one read.
	*/
	char	buf_read[4096];

	/*
	** Dynamic buffer storing data
	** not yet written to stdout.
	*/
	char	*buf;

	/*
	** Position of a found match.
	*/
	char	*pos;

	/*
	** Current used length in buf.
	*/
	size_t	len;

	/*
	** Allocated size of buf.
	*/
	size_t	cap;

	/*
	** Length of search pattern.
	*/
	size_t	pat_len;

	/*
	** Number of bytes safe to write.
	*/
	size_t	safe;

	/*
	** Return value from read().
	*/
	ssize_t	r;

	/*
	** Must receive exactly one
	** non-empty argument.
	*/
	if (ac != 2 || !av[1][0])
		return (1);

	pat_len = strlen(av[1]);

	buf = NULL;
	len = 0;
	cap = 0;

	/*
	** Read until EOF.
	*/
	while ((r = read(0, buf_read, sizeof(buf_read))) > 0)
	{
		/*
		** Add newly read bytes to our
		** accumulated buffer.
		*/
		if (append(&buf, &len, &cap, buf_read, r))
		{
			free(buf);
			return (error());
		}

		/*
		** Replace every COMPLETE match
		** currently found in buffer.
		**
		** Example:
		** pattern = "abc"
		**
		** buffer:
		** "xxabcxxabc"
		**
		** first iteration:
		**     write "xx"
		**     write "*"
		**     buffer becomes "xxabc"
		**
		** second iteration:
		**     write "xx"
		**     write "*"
		**     buffer becomes ""
		*/
		while ((pos = memmem(buf, len, av[1], pat_len)))
		{
			/*
			** Write everything before match.
			*/
			write(1, buf, pos - buf);

			/*
			** Replace match with '*'.
			*/
			write(1, "*", 1);

			/*
			** Remove:
			** [everything before match]
			** + [the match itself]
			**
			** from the working buffer.
			*/
			len -= (pos - buf) + pat_len;

			/*
			** Move remaining bytes
			** to beginning.
			*/
			memmove(buf, pos + pat_len, len);
		}

		/*
		** IMPORTANT PART
		**
		** Keep last (pat_len - 1) bytes.
		**
		** Why?
		**
		** pattern = "abc"
		**
		** read #1 => "xxab"
		**
		** We cannot output "ab" yet because
		** next read may start with 'c'.
		**
		** So we keep:
		**     pat_len - 1 = 2 chars
		**
		** Keep "ab"
		** Output only safe prefix.
		*/
		if (len >= pat_len)
		{
			/*
			** Everything except the last
			** (pat_len - 1) bytes is safe.
			*/
			safe = len - (pat_len - 1);

			write(1, buf, safe);

			/*
			** Remove written bytes
			** from working buffer.
			*/
			len -= safe;

			memmove(buf, buf + safe, len);
		}
	}

	/*
	** Read error.
	*/
	if (r < 0)
	{
		free(buf);
		return (error());
	}

	/*
	** EOF reached.
	**
	** No future data can arrive,
	** so remaining bytes can be
	** processed completely.
	*/
	while ((pos = memmem(buf, len, av[1], pat_len)))
	{
		write(1, buf, pos - buf);
		write(1, "*", 1);

		len -= (pos - buf) + pat_len;

		memmove(buf, pos + pat_len, len);
	}

	/*
	** Output whatever remains.
	*/
	write(1, buf, len);

	free(buf);

	return (0);
}