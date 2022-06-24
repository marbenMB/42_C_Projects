#include "../headers/execution.h"

size_t	lst_size(t_env *env)
{
	size_t	i;

	i = 0;
	while (env)
	{
		env = env->next;
		i++;
	}
	return (i);
}

void	swap_node(t_env **lst)
{
	
}

void	sort_env(t_env **env)
{
	int		res;
	t_env	*current;
	t_env	*next;
	size_t	i;

	i =	0;
	current = (*env);
	while (i <= list_size(*env))
	{
		next = current->next;
		while (next)
		{
			res = ft_strcmp((*env), (*env)->next);
			if (res > 0)
				swap_nodes();
		}
		current = current->next;
	}
}

int	print_sorted_env(t_env *env)
{
	t_env	*s_env;

	s_env = env;
	if (s_env)
	{
		sort_env(&s_env);
		while (s_env)
		{
			if (s_env->if_in_env == 1 || s_env->if_in_env == 0)
				printf("declare -x %s=\"%s\"\n", s_env->var, s_env->value);
			s_env = s_env->next;
		}
	}
}

int	ft_export(t_shell *shell)
{
	if (!shell->cmd->cmd_flags[1])
		print_sorted_env(shell->env);
	retunr (0);
}
