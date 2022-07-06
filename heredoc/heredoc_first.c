/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:19:00 by abellakr          #+#    #+#             */
/*   Updated: 2022/07/06 13:08:33 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//------------------------ heredoc main function creation
int	heredoc_first(t_shell *shell)
{
	int		number;
	t_data	*backup;
	int		i;

	i = 0;
	backup = shell->data;
	number = file_number(shell->data);
	shell->heredoc_files = create_files(number);
	while (backup)
	{
		if (backup->token == HEREDOC)
		{
			if (start_here_doc(shell->heredoc_files[i], backup->str))
				return (1);
			free(backup->str);
			backup->str = ft_strdup(shell->heredoc_files[i]);
			backup->token = RIP;
			i++;
		}
		backup = backup->next;
	}
	return (0);
}

//--------------------------------------- count number of files we have
int	file_number(t_data *data)
{
	t_data	*backup;
	int		count;

	count = 0;
	backup = data;
	while (backup)
	{
		if (backup->token == HEREDOC)
			count++;
			backup = backup->next;
	}
	return (count);
}

//-----------------------------------------------
char	**create_files(int number)
{
	int		i;
	char	*name;
	char	*num;
	int		fd;
	char	**heredoc_files;

	i = 0;
	name = NULL;
	num = NULL;
	heredoc_files = NULL;
	heredoc_files = (char **)malloc(sizeof(char *) * (number + 1));
	while (i < number)
	{
		num = ft_itoa(i);
		name = ft_strjoin("/tmp/.heredoc_", num);
		fd = open(name, O_RDWR | O_CREAT | O_TRUNC, 0666);
		heredoc_files[i] = ft_strdup(name);
		free(name);
		free(num);
		close(fd);
		i++;
	}
	heredoc_files[i] = NULL;
	return (heredoc_files);
}

//---------------------------------------------------------- only inspiration
int	start_here_doc(char *file_name, char *limiter)
{
	char	*trim;
	int		fd;
	int		pid;
	int		tmp;

	pid = fork();
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (pid == 0)
	{
		signal(SIGINT, SIG_DFL);
		while (1)
		{
			trim = readline (">>");
			if (ft_strcmp(limiter, trim) == 0 || trim == NULL)
				finish_heredoc(trim, fd);
			ft_putendl_fd(trim, fd);
			free(trim);
		}
	}
	signal(SIGINT, SIG_IGN);
	waitpid(pid, &tmp, 0);
	if (WIFSIGNALED(tmp))
		return (1);
	signal(SIGINT, &handler);
	return (0);
}

//-----------------------------------------------
void	delete_here_doc_files(char **file_names)
{
	int	i;

	i = 0;
	while (file_names[i])
	{
		unlink(file_names[i]);
		i++;
	}
}
