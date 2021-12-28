/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:39:16 by mbenbajj          #+#    #+#             */
/*   Updated: 2021/12/26 00:39:45 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_get_line(char *str)
{
	int		index;
	char	*line;

	if (!str[0] || !str)
		return (NULL);
	index = ft_strlen(str, '\n');
	line = (char *)ft_calloc(sizeof(char), (index + 2));
	if (!line)
		return (NULL);
	index = -1;
	while (str[++index] != '\n' && str[index] != '\0')
		line[index] = str[index];
	if (str[index] && str[index] == '\n')
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*get_stc_buff(int fd, char *stc_buff)
{
	char	*buff;
	int		byte;
	int		verf;

	if (!stc_buff)
		stc_buff = ft_calloc(1, 1);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	verf = 0;
	verf = ft_srh(stc_buff, verf);
	while (verf != -1)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
			return (free(buff), NULL);
		buff[byte] = 0;
		if (byte == 0)
			break ;
		else
			stc_buff = ft_join(stc_buff, buff);
		verf = ft_srh(stc_buff, verf);
	}
	return (free(buff), stc_buff);
}

char	*get_next_line(int fd)
{
	static char	*stc_buff[10240];
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stc_buff[fd] = get_stc_buff(fd, stc_buff[fd]);
	line = ft_get_line(stc_buff[fd]);
	stc_buff[fd] = ft_rest(stc_buff[fd]);
	return (line);
}
