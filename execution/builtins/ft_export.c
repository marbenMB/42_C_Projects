#include "../headers/execution.h"

size_t	lst_size(t_env *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

char	**sort_tab(char **tab)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
		}
		i++;
	}
	return (tab);
}

char	**get_var_tab(t_env *env)
{
	char	**tab_var;
	int		i;

	tab_var = (char **)malloc(sizeof(char *) * lst_size(env));
	i = 0;
	env = env ->next;
	while (env)
	{
		tab_var[i] = ft_strdup(env->var);
		env = env->next;
		i++;
	}
	tab_var[i] = NULL;
	tab_var = sort_tab(tab_var);
	return (tab_var);
}

int	print_sorted_env(t_env *env)
{
	char	**tab_var;
	t_env	*head;
	int		i;

	tab_var = get_var_tab(env);
	head = env->next;
	i = 0;
	while (tab_var[i])
	{
		head = env->next;
		while (head)
		{
			if (!ft_strcmp(tab_var[i], head->var))
				printf("declare -x %s=\"%s\"\n", head->var, head->value);
			head = head->next;
		}
		i++;
	}
	free_tab(tab_var);
	return (0);
}

int	ft_export(t_shell *shell)
{
	if (!shell->cmd->cmd_flags[1])
		print_sorted_env(shell->env);
	return (0);
}
