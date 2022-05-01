/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongcho <seongcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:17:26 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/05/09 13:16:49 by seongcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <dirent.h>
# include <signal.h>
# include <termcap.h>
# include "typedef.h"
# include "../libft/libft.h"
# include "../srcs/get_next_line/get_next_line.h"
# include "../srcs/non_canonical/non_canonical.h"

# ifdef __linux__
#  include <sys/types.h>
#  include <sys/wait.h>
#  include <sys/ioctl.h>
# endif

/*
**Util
*/
void	free_ppchar(char **ppchar);
char	*ft_strndup(char *str, int n);
void	error(char *msg);
char	**split_cmdraw(char *cmdraw);
t_bool	isnotsent(char *str, int i);

char	*ft_strchr2(char *str, char c1, char c2, int *is_pipe);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup2(const char *s1);
char	**ft_split2(char const *str, char *set, int *ac);
char	**ft_split3(char const *s, char *sep, int *ac);
t_bool	is_valid_env_str(char *str, t_bool num_start, t_bool key_only);
t_bool	is_numeric_argument(char *arg);
char	*ft_strjoin2(char const *s1, char const *s2);

t_bool	iscap(char *str, int i, int type);
t_bool	need_replace_del(char *str, int i);
char	*need_replace(char *str);
char	*replace_sent(char *str, char *remove_i);
t_bool	replace_lock(char *str);
int		ft_str_quotation_i(char *str, int n);

/*
**Preprocess input
*/
int		check_basic_syntax_error(char *input);
void	replace_dolr_str(t_pars *pars, char *str, int stype, int slen);
void	replace_bsla_str(t_pars *pars, char *str, int stype, int slen);
int		add_pars(t_tag *tag, char *str, int type);
void	clear_pars(t_tag *tag);
void	print_pars(t_tag *tag, int i);
char	*get_parsed_input(t_tag *tag);
int		is_empty_operation(t_pars *pars, int stype);

int		add_pars_sub(t_tag *tag, char *str, int type);
void	clear_pars_sub(t_tag *tag);
void	print_pars_sub(t_tag *tag, int i);
char	*get_parsed_sub_input(t_tag *tag, int no_quote);
char	*get_parsed_sub_input_douq(t_tag *tag, int flag);

int		get_pars(char *input, int sub);
int		get_pars_type(char *s, int i);
int		get_pars_len(char *s, int i, int type);

t_bool	basic_split_istoken(char *input);
int		set_cmd(char **inputstr, t_tag *tag);
int		set_cmd2(t_tag *tag);
void	clear_cmd(t_cmd **cmd_head);
void	print_cmd(t_cmd *cmd);

t_env	*create_env(t_env *prev_env, char *keystr, char *valstr);
int		set_env(char **envp, t_tag *tag);
void	clear_env(t_env **env_head);
void	print_env(t_env *env);
char	*get_envstr(t_env *env);

int		get_num_of_env(t_env *env);
char	*get_env_value(t_env *env, char *key);
int		set_env_value(t_env *env, char *key, char *value);
int		del_env_key(t_env *env, char *key);
int		check_cmd_path(t_cmd *cmd, t_env *env);

/*
**Command control
*/
void	operate_pipe(t_tag *tag, t_cmd *cmd, int flag);
int		redirect_cmd(t_tag *tag, t_cmd *cmd, t_env *env);
void	init_redirect(t_tag *tag);
int		get_redirect_fd(t_tag *tag, char *arg1, char *arg2);
int		get_arg_type(char *arg);

int		exec_builtin(t_tag *tag, t_cmd *cmd, t_env *env);
void	execution(t_tag *tag, t_cmd *cmd, t_env *env);
t_cmd	*new_cmdlist(int len);
void	raw_to_cmdlist(t_cmd *cmd_list, char **cmd_raw);
void	delete_cmdlist(t_cmd *cmd_list, int len);

char	*replace_env(t_tag *tag, char *cmd);
char	*replace_dollar(t_tag *tag, char *cmd);
void	replace_null(void);
void	cmd_replace(t_tag *tag);

/*
**Term Input Mode
*/

void	set_input_mode(t_tag *tag);
void	reset_input_mode(t_tag *tag);

/*
**History process
*/
void	history_init(t_hist *hist);
void	history_destory(t_hist *hist);
int		history_add(t_hist *hist, char *input);
int		history_up(t_hist *hist);
int		history_down(t_hist *hist);

/*
**Signal process
*/

void	init_signal();

/*
**Builtin
*/
int		ft_cd(t_tag *tag, t_cmd *cmd, t_env *env);
int		ft_echo(t_tag *tag, t_cmd *cmd, t_env *env);
int		ft_env(t_tag *tag, t_cmd *cmd, t_env *env);
int		ft_export(t_tag *tag, t_cmd *cmd, t_env *env);
int		ft_pwd(t_tag *tag, t_cmd *cmd, t_env *env);
int		ft_unset(t_tag *tag, t_cmd *cmd, t_env *env);
int		ft_exit(t_tag *tag, t_cmd *cmd, t_env *env);
int		ft_help(t_tag *tag, t_cmd *cmd, t_env *env);
int		num_builtins(t_builtin *builtin);
void	set_builtin(t_builtin *builtin);

int		update_status(int status);
int		exitf(char *s, int putcolon, char *e, int status);
int		exitf_exec(char *cmd, char *e, int errnum);
int		returnf(char *s, int putcolon, char *e, int status);
int		returnf2(int status, char *str);

#endif
