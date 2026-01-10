#include "pipex.h"

static char *get_env_path(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
            return (envp[i] + 5);
        i++;
    }
    return (NULL);
}

static char **split_paths(char **envp)
{
    char *path;

    path = get_env_path(envp);
    if (!path)
        return (NULL);
    return (ft_split(path, ':'));
}

static char *join_path_cmd(char *dir, char *cmd)
{
    char    *tmp;
    char    *full;

    tmp = ft_strjoin(dir, "/");
    if (!tmp)
        return (NULL);
    full = ft_strjoin(tmp, cmd);
    free(tmp);
    return (full);
}

static char *find_cmd_path(char *cmd, char **paths)
{
    int     i;
    char    *full;

    i = 0;
    while (paths && paths[i])
    {
        full = join_path_cmd(paths[i], cmd);
        if (!full)
            return (NULL);
        if (access(full, X_OK) == 0)
            return (full);
        free(full);
        i++;
    }
    return (NULL);
}

char *resolve_cmd_path(char *cmd, char **envp)
{
    char    **paths;
    char    *full;

    if (!cmd || !*cmd)
        return (NULL);
    if (ft_strchr(cmd, '/'))
        return (ft_strdup(cmd));
    paths = split_paths(envp);
    full = find_cmd_path(cmd, paths);
    free_split(paths);
    return (full);
}
