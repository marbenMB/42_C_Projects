/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:41:50 by abellakr          #+#    #+#             */
/*   Updated: 2022/06/17 21:07:58 by abellakr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../minishell.h"

//----------------------------------------------- get env variable
t_env	*get_env(char **env)
{
	int i;
	char *var;
	char *value;
	t_env *my_env;

	i = 0;
	my_env = NULL;
	var = NULL;
	value = NULL;
	ft_lstadd_back_expander(&my_env, ft_lstnew_expander("?", "0")); // first node hia exit status
	while (env[i])
	{
		var = get_var(env[i]);
		value = get_value(env[i]);
		ft_lstadd_back_expander(&my_env, ft_lstnew_expander(var, value));
		free(var);
		free(value);
		i++;
	}
	return(my_env);
}
//------------------------------------------------ get var
char *get_var(char *line)
{
	int k;
	char *var;

	k = 0;
	while(line[k] != '=')
		k++;
	var = ft_substr(line, 0, k);
	return(var);
}
//------------------------------------------------ get value
char *get_value(char *line)
{
	int k;
	int l;
	int j;
	char *value;

	k = 0;
	j = 0;
	while(line[k] != '=')
		k++;
	k++;
	l = k;
	while(line[k])
	{
		k++;
		j++;
	}
	value = ft_substr(line, l, j);
	return(value);
}