#include "get_next_line.h"

char	*extract_line(char *stash)
{
    int		i;
    char	*line;

    if (!stash || !*stash)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] == '\n')
        i++;
    line = ft_substr(stash, 0, i);
    return (line);
}

char	*clean_stash(char *stash)
{
    int		i;
    char	*new_stash;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    new_stash = ft_strdup(&stash[i + 1]);
    free(stash);
    return (new_stash);
}

char	*get_next_line(int fd)
{
    static char	*stash;
    char		*line;
    char		*buf;
    ssize_t		bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(stash, '\n') && bytes_read != 0)
    {
        bytes_read = read(fd, buf, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free(buf);
            return (NULL);
        }
        buf[bytes_read] = '\0';
        stash = ft_strjoin(stash, buf);
    }
    free(buf);
    line = extract_line(stash);
    stash = clean_stash(stash);
    return (line);
}
