/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyyo <hyungyyo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:56:38 by hyungyyo          #+#    #+#             */
/*   Updated: 2021/01/21 14:38:40 by hyungyyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_flag
{
	int			neg;
	int			zero;
	int			dot;
	int			precision;
	int			width;
}				t_flag;

typedef char	t_bool;
# define TRUE 1
# define FALSE 0

int				put_int(long num, t_flag flag);
int				put_char(char c, t_flag flag);
int				put_str(char *str, t_flag flag);
int				put_hex(unsigned int num, t_flag flag, char b);
int				put_mem(unsigned long n, t_flag flag);
int				put_none(char c, t_flag flag);

int				ft_nbrlen(long n);
int				ft_putnbr(long n);
int				ft_putnbr_prewidth(long n, t_flag flag);
int				ft_putnbr_pre(long n, t_flag flag);
int				ft_putnbr_width(long n, t_flag flag);

int				ft_putchar(char c);
int				ft_putchar_minwidth(char c, int width);
int				ft_putchar_zerowidth(char c, int width);
int				ft_putchar_width(char c, int width);

int				ft_strlen(char *str);
int				ft_putstr(char *str);
int				ft_putstr_prewidth(char *str, t_flag flag);
int				ft_putstr_width(char *str, t_flag flag);
int				ft_putstr_pre(char *str, int precision);

int				ft_hexlen(unsigned int n);
int				ft_puthex(unsigned int n, int b);
int				ft_puthex_prewidth(unsigned int n, t_flag flag, int b);
int				ft_puthex_pre(unsigned int n, t_flag flag, int b);
int				ft_puthex_width(unsigned int n, t_flag flag, int b);

int				ft_memlen(unsigned long n);
int				ft_putmem(unsigned long n, int start);
int				ft_putmem_prewidth(unsigned long n, t_flag flag);
int				ft_putmem_width(unsigned long n, t_flag flag);
int				ft_putmem_pre(unsigned long n, t_flag flag);

void			flag_init(const char *str, int *i, t_flag *flag,
va_list args_list);

int				ft_printf(const char *string, ...);

#endif
