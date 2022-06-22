#include "../headers/execution.h"

int	ft_cd(t_shell *shell)
{
	char	*path;

	path = shell->cmd->cmd_flags[1];	
	if (!path || ft_strcmp(path, "~"))
	{
		//	cd -> HOME
		/* 	set -> NEW_ENV
		{
				set -> NEW_PWD
				set -> NEW_OLDPWD
		} */
	}
	else if (!ft_strcmp(path, "~-") || !ft_strcmp(path, "-"))
	{
		//	cd -> OLDPWD
		/* 	set -> NEW_ENV
		{
				set -> NEW_PWD
				set -> NEW_OLDPWD
		} */
	}
	else if (path && *path)
	{
		chdir(path);
		/* 	set -> NEW_ENV
		{
				set -> NEW_PWD
				set -> NEW_OLDPWD
		} */
	}

	return (0);
}