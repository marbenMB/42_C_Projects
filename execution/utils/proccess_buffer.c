#include "../headers/execution.h"

int	proccess_cmd(t_shell *shell, char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		ft_cd(shell);
	// else if (!ft_strcmp(cmd, "echo"))
	// 	ft_echo(shell);
	// else if (!ft_strcmp(cmd, "env"))
	// 	ft_env(shell);
	// else if (!ft_strcmp(cmd, "exit"))
	// 	ft_exit(shell);
	// else if (!ft_strcmp(cmd, "export"))
	// 	ft_export(shell);
	// else if (!ft_strcmp(cmd, "pwd"))
	// 	ft_pwd(shell);
	// else if (!ft_strcmp(cmd, "unset"))
	// 	ft_unset(shell);
	else
	{
		//	execve -> execution
		return (1);
	}
	return (0);
}

int	proccess_buff(t_shell *shell)
{
	if (shell->data->token == 6)
		proccess_cmd(shell, shell->cmd->cmd_flags[0]);
	return (0);
}
