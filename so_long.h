/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:22:07 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/05/12 17:22:09 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//	***********		Includes	*********** :
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "./libft/libft.h"

//	***********		Functions	*********** :
//	***********	Errors : 
void	error_usage(void);
void	error_name(void);

//	***********	Checks :
void	check_name(char *name);

#endif