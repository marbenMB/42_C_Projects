
#include "pipex.h"

int main(int ac, char **av, char **env)
{
    if (ac < 5)
        error_args();
    process_args(ac, av, env);
	system("leaks pipex");
}