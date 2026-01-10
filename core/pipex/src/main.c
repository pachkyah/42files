#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    t_pipex px;

    if (argc < 5)
    {
        write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 41);
        return (1);
    }
    init_pipex(&px, argc, argv, envp);
    open_files(&px);
    parse_commands(&px);
    create_pipes(&px);
    execute_commands(&px);
    cleanup_pipex(&px);
    return (0);
}