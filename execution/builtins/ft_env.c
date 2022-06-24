#include "../headers/execution.h"

int	ft_env(t_shell *shell)
{
	t_env	*head;

	head = shell->env->next;
	while (head)
	{
		if (head->if_in_env == 1)
			printf("%s=%s\n", head->var, head->value);
		head = head->next;
	}
	return (0);
}