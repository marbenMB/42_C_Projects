/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenbajj <mbenbajj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:58:20 by abellakr          #+#    #+#             */
/*   Updated: 2022/07/06 13:08:16 by mbenbajj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MINISHELL_H
# define MINISHELL_H
// ********************************************** includes
# include "headers/includes.h"
# include "headers/macros.h"
# include "headers/structs.h"
# include "execution/headers/execution.h"
// *********************************************************

void	loop(t_shell *shell, int in, int out);
void	exec_lunch(t_shell *shell, int in, int out);
// ********************************************************* lexer 

//------------------ utils
t_data	*ft_lstnew_lexer(char *data, int token);
void	ft_lstadd_back_lexer(t_data **lst, t_data *new);
t_data	*ft_lstlast_lexer(t_data **lst);
void	free_data(t_data **data);
//---------- syntax error
int		check_syntax_error(char *buffer);
int		ft_is_operator(char c);
int		ft_special_char(char c);
int		operator_error(char *buffer, int i);
//--------- token and save data
t_data	*analyse_buffer(char *buffer);
int		data_reconization1(char *buffer, t_data **data);
int		word_token(char **buffer, t_data **data, char *quote);
int		pipe_data(char **buffer, t_data **data);
t_data	*simple_command_analyser(t_data **data);
int		simple_command_check(t_data **new_data, char *simple_command);
int		data_reconization2(char *simple_command, t_data **simple_command_list);
int		cmd_token(char **simple_command, \
t_data **simple_command_list, char *quote);
int		operator_type(char **simple_command, t_data **simple_command_list);
int		save_operator_data(char **simple_command, \
t_data **simple_command_list, int flag);
void	check_flag(char **simple_command, int flag);
int		files_lim_len(char **simple_command);
t_data	*oranize_simple_command_list(t_data **simple_command_list);
void	look_for_heredoc(t_data *backup, t_data **new_list);
void	look_for_rop(t_data *backup, t_data **new_list);
void	look_for_cmd(t_data *backup, t_data **new_list);
t_data	*join_cmds(t_data **new_list_cmd);
char	*join_cmds_string(t_data *list);
//*************************************************** expander
//--------------------------- utils
t_env	*ft_lstnew_expander(char *var, char *value);
void	ft_lstadd_back_expander(t_env **lst, t_env *new);
t_env	*ft_lstlast_expander(t_env **lst);
void	free_data2(t_env **env);
//---------------------------- get env
t_env	*get_env(char **env);
char	*get_var(char *line);
char	*get_value(char *line);
char	*var_finder(char *var, t_env *env);
//-----------------------------------------
void	quotes_checker(char quote, char *quote_type);
char	*expande_str_data(char *str, t_env *env, int token);
void	expander(t_shell *data_shell);
int		dollar_var(char **str, t_env *env);
char	*before(char *str);
char	*after(char *str);
char	*in_var(char *str, t_env *env);
char	**command_filler(char *str, t_env *env);
int		words_counter(char *cmd);
void	count_words_witout_quotes(char **cmd, int *count);
void	count_words_with_quotes(char **cmd, int *count, char *quote_type);
char	*word_finder(char *string, t_env *env);
char	*rest_finder(char **string);
void	free_twod_tab(char **tab);
t_cmd	*ft_lstnew_cmd(char **cmd_flags);
void	ft_lstadd_back_cmd(t_cmd **lst, t_cmd *new);
t_cmd	*ft_lstlast_cmd(t_cmd **lst);
void	free_data3(t_cmd **cmd);
void	exapnde_dollar(char	**str, t_env *env);
//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ new
void	finish_heredoc(char *str, int fd);
int		heredoc_first(t_shell *shell);
int		file_number(t_data *data);
char	**create_files(int number);
int		start_here_doc(char *file_name, char *limiter);
void	delete_here_doc_files(char **file_names);
#endif
