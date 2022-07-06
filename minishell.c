/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 02:41:00 by abellakr          #+#    #+#             */
/*   Updated: 2022/07/06 03:24:53 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	**************************
//			TODO :
// norme this 
// check abort and segafault
// leaks
// signals of heredoc
//	**************************

//--------------------------------------------------------- loop

void	loop(t_shell *shell, int in, int out)
{
	char	*buffer;

	while (1)
	{
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
		heredoc_first(shell);
		if (shell->data)
			proccess_buff(shell);
		free_data(&(shell->data));
		free_data3(&shell->cmd);
		delete_here_doc_files(shell->heredoc_files);
		free_tab((shell->heredoc_files));
		dup2(in, STDIN_FILENO);
		dup2(out, STDOUT_FILENO);
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
