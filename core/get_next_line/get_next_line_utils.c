#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
    size_t i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
    size_t	len1 = ft_strlen(s1);
    size_t	len2 = ft_strlen(s2);
    char	*res = malloc(len1 + len2 + 1);
    size_t	i = 0, j = 0;

    if (!res)
        return (NULL);
    while (s1 && s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2 && s2[j])
        res[i++] = s2[j++];
    res[i] = '\0';
    free(s1);
    return (res);
}

char	*ft_strdup(const char *s)
{
    size_t	len = ft_strlen(s);
    char	*copy = malloc(len + 1);
    size_t	i = 0;

    if (!copy)
        return (NULL);
    while (i < len)
    {
        copy[i] = s[i];
        i++;
    }
    copy[i] = '\0';
    return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t	i = 0;
    char	*sub;

    if (!s || start >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s + start))
        len = ft_strlen(s + start);
    sub = malloc(len + 1);
    if (!sub)
        return (NULL);
    while (i < len && s[start + i])
    {
        sub[i] = s[start + i];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}
