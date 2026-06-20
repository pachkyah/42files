#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

/* Helper: Custom string concatenation and duplication */
char	*ft_strjoin(char const *s1, char const *s2)
{
    // Standard implementation: allocate (len1 + len2 + 1), copy s1 then s2
	size_t	len1;
	size_t	len2;
	char	*joined;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	ft_memcpy(joined, s1, len1);
	ft_memcpy(joined + len1, s2, len2);
	joined[len1 + len2] = '\0';
	return (joined);
}

/* Helper: Find newline position */
static int ft_find_nl(char *s) {
    int i = 0;
    if (!s) return -1;
    while (s[i]) {
        if (s[i] == '\n') return i;
        i++;
    }
    return -1;
}

char *get_next_line(int fd) {
    static char *leftover;
    char buffer[BUFFER_SIZE + 1];
    int bytes_read;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0) return NULL;

    // 1. Read until we find a newline or EOF
    while (ft_find_nl(leftover) == -1 && (bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
        buffer[bytes_read] = '\0';
        leftover = ft_strjoin(leftover, buffer);
    }

    // 2. If nothing was read and nothing in leftover, return NULL
    if (!leftover || *leftover == '\0') {
        free(leftover);
        leftover = NULL;
        return NULL;
    }

    // 3. Extract the line
    int nl_pos = ft_find_nl(leftover);
    if (nl_pos != -1) {
        line = /* Copy from start to nl_pos + 1 */;
        char *new_leftover = /* Copy from nl_pos + 1 to end */;
        free(leftover);
        leftover = new_leftover;
    } else {
        line = leftover;
        leftover = NULL;
    }
    return line;
}