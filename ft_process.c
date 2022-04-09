
#include "pipex.h"

void    process_cmd(int fd[2], int ac, char **av, char **env)
{
    t_cmd_pack  *cmd_pack;

    cmd_pack = (t_cmd_pack *)malloc(sizeof(t_cmd_pack));
    if (!cmd_pack)
        exit(-1);
    cmd_pack = get_cmd_pack(cmd_pack, ac, av, env);
}

void    process_args(int ac, char **av, char **env)
{
    int idx;
    int fd[2];

    idx = -1;
    while (++idx < ac)
    {
        if (!av[idx] || av[idx][0] == 0)
            error_fill_arg(av[idx]);
        if (!ft_strncmp(av[idx], " ", 2))
            error_fill_arg(av[idx]);
    }
    fd[0] = open(av[1], O_RDONLY, 0666);
    if (fd[0] < 0)
        error_files();
    fd[1] = open(av[ac - 1], O_WRONLY, O_CREAT, O_TRUNC, 0666);
    if (fd[1] < 0)
        exit(-1);
    process_cmd(fd, ac, av, env);
}