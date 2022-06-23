/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:03:28 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/22 21:42:14 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef STRUCTS_H
# define STRUCTS_H
//---------------------------- lexer  data
typedef struct data
{
	struct data	*prev;
	char		*str;
	int			token;
	struct data	*next;
}t_data;
//---------------------------- private env data
typedef struct env
{
	struct env	*prev;
	char		*var;
	char		*value;
	struct env	*next;
}t_env;
//------------------------------- cmd data
typedef struct cmd
{
	char **cmd_flags;
	struct cmd *next;
}t_cmd;
//--------------------------- shell data
typedef struct shell
{
	t_data	*data;
	t_env	*env;
	t_cmd	*cmd;
}t_shell;

//-------------------------------------------------- afarraji ideas
// typedef struct redirect
// {
// 	int type;
// 	char	*filename;
// 	t_redirct	*next;
// }t_redirct;

// typedef struct simple_cmd
// {
// 	t_redirct	*redirection; 
// 	char		**cmd;
// 	t_s_cmd 	*next;
// }t_s_cmd;


# endif