/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 02:41:00 by abellakr          #+#    #+#             */
/*   Updated: 2022/07/04 06:57:08 by mbenbajj         ###   ########.fr       */
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

//--------------------------------------------------------- main
int	main(void)
{
	char	*buffer;
	t_shell	shell;
	extern char **environ; // test this system var 

	shell.env = get_env(environ);
	check_in_env(&shell);
	while (1)
	{
		buffer = readline ("minishell$ ");
		add_history(buffer);
		if (ft_strcmp(buffer, "exit") == 0)
			exit(0);
		shell.data = analyse_buffer(buffer);
		// check exit status in syntax error messages
		if(shell.data == NULL)
		{
			free(shell.env->value);
			shell.env->value = ft_strdup("-1");
		}
		expander(&shell);
		heredoc_first(&shell);
		// //----------------------------- print data
		// t_data	*head_data = shell.data;
		// t_cmd	*head_cmd = shell.cmd;
		// printf("\n........................................................list of data\n");
		// while(shell.data)
		// {
		// 	printf("[%s]\t%d\n", shell.data->str, shell.data->token);
		// 	shell.data = shell.data->next;
		// }
		// printf("\n........................................................table of cmds\n");

		// while(shell.cmd)
		// {
		// 	int i = 0;
		// 	while(shell.cmd->cmd_flags[i])
		// 	{
		// 		printf("(%s)\t", shell.cmd->cmd_flags[i]);
		// 		i++;	
		// 	}
		// 	printf("\n");
		// 	shell.cmd = shell.cmd->next;
			
		// }
		// shell.data = head_data;
		// shell.cmd = head_cmd;
		// //----------------------------------------- print data 
		if (shell.data)
			proccess_buff(&shell);  // hadi rah kadir segfault f syntax error o chi cmd makhdamach
		free_data(&(shell.data));
		free_data3(&(shell.cmd));
		delete_here_doc_files(shell.heredoc_files);
		free_tab((shell.heredoc_files));
		// -------------------------------------------------------------- check leaks
		// printf("\033[0;33m----------------------------\n");
		// system("leaks minishell");
		// printf("\n----------------------------\n\033[0m");
	}
	free_data2(&(shell.env));
	return (0);
}
