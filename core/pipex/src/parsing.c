#include "pipex.h"

static int get_cmd_start_index(t_pipex *px)
{
    if (px->here_doc)
        return (3);
    return (2);
}

static char **split_command(char *cmd, char **envp)
{
    char    **split;
    char    *path;

    split = ft_split(cmd, ' ');
    if (!split || !split[0])
    {
        free_split(split);
        return (NULL);
    }
    path = resolve_cmd_path(split[0], envp);
    if (path)
    {
        free(split[0]);
        split[0] = path;
    }
    return (split);
}

static void fill_cmds_array(t_pipex *px, int start)
{
    int i;

    i = 0;
    while (i < px->cmd_count)
    {
        px->cmds[i] = split_command(px->argv[start + i], px->envp);
        i++;
    }
}

void parse_commands(t_pipex *px)
{
    //debug
    printf("step 3: parsing commands\n");
    int start;

    start = get_cmd_start_index(px);
    fill_cmds_array(px, start);
    
    for (int i = 0; i < px->cmd_count; i++ ){
        printf("cmd%d path: %s\n", i, px->cmds[i][0]); //debugger
    }

}
