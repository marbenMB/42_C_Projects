#include "../headers/execution.h"

int	ft_pwd(t_shell *shell)
{
	t_env	*env;
	char	*path;
	char	cwd[PATH_MAX];

	env = shell->env;
	while (env)
	{
		if (!ft_strcmp("PWD", env->var))
			break ;
		env = env->next;
	}
	if (env)
		path = env->value;
	else
		path = getcwd(cwd, sizeof(cwd));
	printf("%s\n", path);
	return (0);
}