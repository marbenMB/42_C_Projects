/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:03:28 by abellakr          #+#    #+#             */
/*   Updated: 2022/07/06 10:58:46 by mbenbajj         ###   ########.fr       */
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
	char	**heredoc_files;
	t_data	*data;
	t_env	*env;
	t_cmd	*cmd;
	int		in_fd;
	int		out_fd;
	int		pipe_p;
}	t_shell;
#	endif
