#ifndef PIPEX_H
# define PIPEX_H


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>

# include "libft.h"

/* Main structure */
typedef struct s_pipex
{
    int     argc;
    char    **argv;
    char    **envp;

    int     infile;
    int     outfile;

    int     **pipes;        // array of pipes (bonus)
    int     pipe_count;     // number of pipes = cmd_count - 1

    int     cmd_count;      // number of commands
    char    ***cmds;        // cmds[i] = split command

    char    **paths;        // PATH split

    int     here_doc;
    char    *limiter;

    pid_t   *pids;
}   t_pipex;

/* init */
void    init_pipex(t_pipex *px, int argc, char **argv, char **envp);

/* parsing */
void    parse_commands(t_pipex *px);

/* files */
void    open_files(t_pipex *px);

/* path */
char *resolve_cmd_path(char *cmd, char **envp);

/* pipes */
void    create_pipes(t_pipex *px);
void    close_pipes(t_pipex *px);

/* exec */
void    execute_commands(t_pipex *px);

/* heredoc */
void    handle_heredoc(t_pipex *px);

/* cleanup */
void    cleanup_pipex(t_pipex *px);

/* utils */
void    error_exit(char *msg);
void    free_split(char **split);

#endif