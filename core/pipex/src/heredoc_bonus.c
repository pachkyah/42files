#include "pipex.h"

static char *read_line(void)
{
    char    *line;
    char    c;
    int     i;
    int     r;

    line = malloc(1024);
    if (!line)
        return (NULL);
    i = 0;
    while (i < 1023)
    {
        r = read(0, &c, 1);
        if (r <= 0)
            break;
        line[i++] = c;
        if (c == '\n')
            break;
    }
    line[i] = '\0';
    if (i == 0)
    {
        free(line);
        return (NULL);
    }
    return (line);
}

void handle_heredoc(t_pipex *px)
{
    int     pipefd[2];
    char    *line;
    size_t  len;

    if (!px->here_doc)
        return;
    if (pipe(pipefd) < 0)
        error_exit("pipe");
    len = ft_strlen(px->limiter);
    while (1)
    {
        write(1, "heredoc> ", 9);
        line = read_line();
        if (!line)
            break;
        if (ft_strncmp(line, px->limiter, len) == 0 && line[len] == '\n')
        {
            free(line);
            break;
        }
        write(pipefd[1], line, ft_strlen(line));
        free(line);
    }
    close(pipefd[1]);
    px->infile = pipefd[0];
}
