/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expande_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 06:58:44 by abellakr          #+#    #+#             */
/*   Updated: 2022/07/03 16:36:40 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//---------------------------------------------------- exapande dollar signe
int	dollar_var(char **str, t_env *env)
{
	char	*before_var;
	char	*after_var;
	char	*var;
	char	*tmp;
	int		i ;

	after_var = after(*str);
	before_var = before(*str);
	var = in_var(*str, env);
	free(*str);
	tmp = ft_strjoin (before_var, var);
	i = ft_strlen(tmp) - 1;
	*str = ft_strjoin(tmp, after_var);
	free(before_var);
	free(var);
	free(tmp);
	free(after_var);
	return (i);
}

//---------------------------- return str before variable --> fixed segfault
char	*before(char *str)
{
	int		i;
	char	*before_var;

	i = 0;
	while (str[i] != '$' && str[i])
		i++;
	before_var = (char *)malloc((sizeof(char ) * i) + 1);
	i = 0;
	while (str[i] != '$' && str[i])
	{
		before_var[i] = str[i];
		i++;
	}
	before_var[i] = 0;
	return (before_var);
}

//--------------- return str after variable --> in progress
char	*after(char *str)
{
	char	*backup;

	backup = str;
	while (*backup && *backup != '$')
		backup++;
	backup++;
	while (*backup && *backup != ' ' && *backup != '"' && \
	*backup != '\'' && *backup != '$')
	{
		if (ft_is_operator(*backup) == 1 || export_special_char(*backup) == 1)
			break ;
		backup++;
	}
	return (ft_strdup(backup));
}

//------------------------------------------------------- return variable value
char	*in_var(char *str, t_env *env)
{
	char	*var1;
	char	*var2;
	char	*value;
	int		i;

	var1 = NULL;
	var2 = NULL;
	i = 0;
	while (*str != '$')
		str++;
	str++;
	if(*str == '\0')
		return (ft_strdup("$"));
	var1 = ft_strdup(str);
	while (*str && *str != '$' && *str && *str != ' ' && *str != '"' \
	&& *str != '\'' && ft_is_operator(*str) == 0 && !export_special_char(*str))
	{
		i++;
		str++;
	}
	var2 = ft_substr(var1, 0, i);
	free(var1);
	value = var_finder(var2, env);
	free(var2);
	return (value);
}
