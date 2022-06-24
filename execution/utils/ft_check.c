#include "../headers/execution.h"

void	check_in_env(t_shell *shell)
{
	t_env	*back_up;

	shell->env->if_in_env = -1;
	back_up = shell->env->next;
	if (back_up)
	{
		while (back_up)
		{
			back_up->if_in_env = 1;
			back_up = back_up->next;
		}
	}
}