/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:59:05 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/20 12:35:33 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	char	*buffer;
	t_shell	shell;

	if (!env || !env[0])
		return (write(2, "empty env\n", 10), 1);
	ac = 0;
	av = NULL;
	shell.env = get_env(env);
	while (1)
	{
		buffer = readline ("\nminishell$ ");
		add_history(buffer);
		if (ft_strcmp(buffer, "exit") == 0)
			exit(0);
		shell.data = analyse_buffer(buffer);
		if(shell.data == NULL)
		{
			free(shell.env->value);
			shell.env->value = ft_strdup("-1");
		}
		// 1: handle rio cases and 
		// redirection_organizer(&shell);
		// 2: save cmd data in list 
		// 3: then exapande data
			// expander(&shell);
		// while(shell.data)
		// {
		// 	printf("\n-------------------------- : node\n");
		// 	printf("%s\n%d", shell.data->str, shell.data->token);
		// 	shell.data = shell.data->next;
		// }
		free_data(&(shell.data));
	}
	free_data2(&(shell.env));
	return (0);
}
//-------------------------------------------------------------
void	redirection_organizer(t_shell *global_data)
{
	t_data *back_up;
	t_data *new_data;
	int check_number;

	back_up = global_data->data;
	new_data = NULL;
	check_number = 1;
	while(back_up)
	{
		if(back_up->token == PIPE)
			check_number++;
		back_up = back_up->next;
	}
	back_up = global_data->data;
	while(check_number)
	{
		if(check_number == 1)
			// handle no pipe case 
		{
			while(back_up)
			{
				if(back_up->token != CMD_WORD)
				{
					ft_lstadd_back_lexer(&new_data, ft_lstnew_lexer(back_up->str, back_up->token));
				}
				back_up = back_up->next;
			}
		}
		// else if(check_number > 1)
			// handle multi pipe cases
		check_number--;
	}
	while(new_data)
	{
		printf("\n-----------------------------------------\n");
		printf("%s\ntoken:%d", new_data->str, new_data->token);
		new_data = new_data->next;
	}
}
//---------------------------------------------------------------
