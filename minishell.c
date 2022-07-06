/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 02:41:00 by abellakr          #+#    #+#             */
/*   Updated: 2022/07/06 13:01:00 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//--------------------------------------------------------- exec
void	exec_lunch(t_shell *shell, int in, int out)
{
	if (heredoc_first(shell) != 1 && shell->data)
		proccess_buff(shell);
	free_data(&(shell->data));
	free_data3(&shell->cmd);
	delete_here_doc_files(shell->heredoc_files);
	free_tab((shell->heredoc_files));
	dup2(in, STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
}

//--------------------------------------------------------- loop

void	loop(t_shell *shell, int in, int out)
{
	char	*buffer;

	while (1)
	{
		signal(SIGINT, &handler);
		signal(SIGQUIT, SIG_IGN);
		hide_ctrl_chars();
		buffer = readline ("minishell-6.9$ ");
		add_history(buffer);
		if (!buffer)
			break ;
		shell->data = analyse_buffer(buffer);
		if (shell->data == NULL)
		{
			free(shell->env->value);
			shell->env->value = ft_strdup("-1");
		}
		expander(shell);
		exec_lunch(shell, in, out);
	}
}

//--------------------------------------------------------- main
int	main(void)
{
	t_shell		shell;
	extern char	**environ;
	int			in;
	int			out;

	shell.env = get_env(environ);
	check_in_env(&shell);
	in = dup(STDIN_FILENO);
	out = dup(STDOUT_FILENO);
	loop(&shell, in, out);
	free_data2(&(shell.env));
	return (0);
}
