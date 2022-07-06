/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:44:58 by mbenbajj          #+#    #+#             */
/*   Updated: 2022/07/06 13:02:42 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

//	***********		Includes	*********** :
# include "../../minishell.h"
# include "paths.h"
//	***********		DEFINES		*********** :
# define SUCC_STAT "0"
# define FAIL_STAT "1"
# define CNF_STAT "127"
# define ERROR_STAT "-1"
# define STDIN 0
# define STDOUT 1
# define STDERROR 2
# define NSFD "No such file or directory"
# define TMA "Too many arguments"
# define NVI "Not a valid identifier"
# define HNS "HOME not set"
# define ONS "OLDPWD not set"
# define NAR "Numeric argument required"
# define FIE "Failed in execution"
# define CNF "Command not found"

//	***********		Functions	*********** :
//	********		 ERRORS		******** :
void	error_cmd_arg(t_env **env, char *cmd, char *arg, char *msg);
void	error_cd(t_env **env, char *arg, char *msg);
void	error_cd_access(t_env **env);
void	error_internal_ft(t_env **env, char *ft, char *msg);
void	error_cmd_nf(t_env **env, char *cmd, char *msg);

//	********		 UTILS		******** :

//*		->	utils :		-----------------------------------------
void	ft_status(t_env **env, char *stats);
t_env	*get_env_var(t_env *env, char *var_name);
char	*get_cmd_path(t_env *env, char *cmd);
int		if_cmd_builtin(char *cmd);
char	*get_incubate_tab(t_env *env);

//*		->	Proccessing:-----------------------------------------
int		proccess_cmd(t_shell *shell, char *cmd, char *cmd_path, int *pip_fd);
int		proccess_buff(t_shell *shell);
void	check_exit_stat(t_shell *shell, int i_stat);

//*		->	Checking :	-----------------------------------------
void	check_in_env(t_shell *shell);
void	check_set_env(t_shell *shell);
void	check_complete_env(t_shell *shell);
char	*check_cmd_access(char **env_paths, char *cmd);

//*		->	Analyse Utils	: -----------------------------------
int		analyse_exec_buffer(t_shell *shell);
int		analyse_exec_cmd(t_shell *shell, t_data *elem);
int		analyse_red_io(t_shell *shell, t_data *elem);
int		get_red_fd(t_data *elem);
void	pipe_p(t_shell *shell);

//*		->	Execute Cmd	: ---------------------------------------
void	execute_builtin(t_shell *shell, char *cmd);
void	execute_non_builtin(t_shell *shell, char *cmd_path, int *pip_fd);
void	ft_dup_io(t_shell *shell, int *pip_fd);
void	execute_builtin_child(t_shell *shell, char *cmd, int *pip_fd);

//*		->	Execute Func: ---------------------------------------
char	**incubate_env(t_env *env);
void	dup_next(t_shell *shell, int *pip_fd);
void	dup_no_next(t_shell *shell, int *pip_fd);

//*		->	siganls func: ---------------------------------------
void	handler(int signal);
void	hide_ctrl_chars(void);
void	show_ctrl_chars(void);
void	ft_s_exit(int status);

//	********		BUILTINS	******** :
//*	->	ft_echo :		-----------------------------------------
int		ft_echo(t_shell *shell);
int		is_flag(char *word);

//*	->	ft_env :		-----------------------------------------
int		ft_env(t_shell *shell);

//*	->	ft_pwd :		-----------------------------------------
int		ft_pwd(t_shell *shell);

//*	->	ft_export :		-----------------------------------------
//*			sort_env :			-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
size_t	lst_size(t_env *lst);
size_t	tab_len(char **tab);
void	free_tab(char **tab);
char	**sort_tab(char **tab);
char	**get_var_tab(t_env *env);
void	print_env_var(char *var_name, char *value, int if_in);
int		print_sorted_env(t_env *env);
//*			add_env_var :		-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-
int		add_env_var(t_env **env, char *var, char *value, int _if);
int		join_env_value(t_env **env, char *var, char *value, int _if);
char	*get_var_name(char *var_str);
t_env	*get_existed_var(t_env **env, char *var);
int		existed_var(t_env *env, char *var);
void	parse_var_str(t_env **env, char *var_str);
int		export_special_char(char c);
int		valid_export_name(char *var_str);
int		env_var(t_shell *shell);
int		ft_export(t_shell *shell);

//*	->	ft_cd :			-----------------------------------------
int		ft_cd(t_shell *shell);
int		chdir_path(t_shell *shell, char *path);
int		chdir_old(t_shell *shell);
int		chdir_home(t_shell *shell);
char	*get_wd(void);
int		update_wd(t_env **env, char *old, char *current);
int		check_path(char *path);
void	dir_chr(t_shell *shell, char *path);
void	chdir_cases(t_shell *shell, char *path);
char	*path_join(char *old, char *path);

//*	->	ft_unset :		-----------------------------------------
int		ft_unset(t_shell *shell);
int		valid_unset_name(char *name);
void	unset_var(t_env **var);
void	free_env_node(t_env *node);

//*	->	ft_exit :		-----------------------------------------
void	ft_exit(t_shell *shell);
int		check_exit_args(char **cmd_flags);
int		ft_atoi_max(const char *str);
#endif
