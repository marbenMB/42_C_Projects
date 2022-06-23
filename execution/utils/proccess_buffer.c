#include "../headers/execution.h"

t_cmd	*lstnew(char	**cmd)
{
	t_cmd	*new_list;

	new_list = (t_cmd *)malloc(sizeof(*new_list));
	if (new_list == NULL)
		return (NULL);
	new_list -> cmd_flags =  cmd;
	new_list -> next = NULL;
	return (new_list);
}

void	add_back(t_cmd **lst, t_cmd *cmd)
{
	if (!*lst)
		*lst = cmd;
	else
		(*lst)->next = cmd;
}

int	fill_cmd(t_shell *shell)
{
	t_data		*head;
	t_cmd		*cmd;

	head = shell->data;
	while (head)
	{
		if (head->token == 8)
			add_back(&cmd, lstnew(ft_split(head->str, ' ')));
		head = head->next;
	}
	shell->cmd = cmd;
	proccess_buff(shell);
	return (0);
}

int	proccess_cmd(t_shell *shell, char *cmd)
{
	if (!ft_strcmp(cmd, "cd"))
		ft_cd(shell);
	else if (!ft_strcmp(cmd, "echo"))
		ft_echo(shell);
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
	if (shell->data->token == 8)
		proccess_cmd(shell, shell->cmd->cmd_flags[0]);
	return (0);
}
