#ifndef EXEC_H
# define EXEC_H

//	***********		Includes	*********** :
#include "../../minishell.h"

//	***********		Functions	*********** :

//	********		 UTILS		******** :
int		proccess_cmd(t_shell *shell, char	*cmd);
int		proccess_buff(t_shell *shell);
//	********		BUILTINS	******** :
	//	->	ft_cd :
int		ft_cd(t_shell *shell);
	//	->	ft_echo :
int		ft_echo(t_shell *shell);
	//	->	ft_env :
int		ft_env(t_shell *shell);
	//	->	ft_exit :
int		ft_exit(t_shell *shell);
	//	->	ft_export :
int		ft_export(t_shell *shell);
	//	->	ft_pwd :
int		ft_pwd(t_shell *shell);
	//	->	ft_unset :
int		ft_unset(t_shell *shell);
#endif
