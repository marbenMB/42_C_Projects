#ifndef EXEC_H
# define EXEC_H

//	***********		Includes	*********** :
#include "../../minishell.h"

//	***********		Functions	*********** :

//	********		 UTILS		******** :
	//	->	utils :
size_t	lst_size(t_env *lst);
size_t	tab_len(char **tab);
void	free_tab(char **tab);
	//	->	Proccessing :
int		proccess_cmd(t_shell *shell, char	*cmd);
int		proccess_buff(t_shell *shell);
void	free_tab(char **tab);
int		fill_cmd(t_shell *shell);
	//	->	Checking :
void	check_in_env(t_shell *shell);
//	********		BUILTINS	******** :
	//	->	ft_echo :
int		ft_echo(t_shell *shell);
int		is_flag(char *word);
	//	->	ft_env :
int		ft_env(t_shell *shell);
	//	->	ft_pwd :
int		ft_pwd(t_shell *shell);
	//	->	ft_export :
int		ft_export(t_shell *shell);
	//	->	ft_cd :
int		ft_cd(t_shell *shell);
	//	->	ft_unset :
int		ft_unset(t_shell *shell);
	//	->	ft_exit :
int		ft_exit(t_shell *shell);
#endif
