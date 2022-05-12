/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:00:23 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/12 18:00:24 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name(char *name)
{
	char	*extension;

	if (ft_strlen(name) <= 4)
		error_name();
	extension = ft_substr(name, ft_strlen(name) - 4, 4);
	if (ft_strcmp(extension, ".ber"))
		error_name();
	free(extension);
}