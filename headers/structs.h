/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:03:28 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/29 14:41:36 by mbenbajj         ###   ########.fr       */
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
	int			if_in_env;
	struct env	*next;
}t_env;
//------------------------------- cmd data
typedef struct cmd
{
	struct cmd	*prev;
	char		**cmd_flags;
	struct cmd	*next;
}t_cmd;
//--------------------------- shell data
typedef struct shell
{
	t_data	*data;
	t_env	*env;
	t_cmd	*cmd;
}t_shell;
#	endif