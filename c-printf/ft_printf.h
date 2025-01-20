/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunlee <eunlee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 13:46:31 by eunlee            #+#    #+#             */
/*   Updated: 2020/12/13 10:45:31 by eunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct	s_tag
{
	int		ret;
	int		error;
	int		flag_minus;
	int		flag_zero;
	int		width_wildcard;
	int		width;
	int		precision_wildcard;
	int		precision_point;
	int		precision;
	int		no_precision;
	char	specifier;
	int		print_len;

}				t_tag;

int				ft_strlen(char *str);
int				ft_intlen(long long int n, int base);
void			put_space(int n);
void			put_zero(int n);
void			ft_itoa(long long int n, int base, int lower);

void			tag_init(t_tag *tag);
void			check_flag(const char **format, t_tag *tag);
void			check_width(const char **format, t_tag *tag);
void			check_precision(const char **format, t_tag *tag);
void			check_specifier(const char **format, t_tag *tag);

void			c_process(t_tag *tag);
void			c_print(int c, t_tag *tag);

int				error_check(t_tag *tag);
void			s_process(char *s, t_tag *tag);
void			s_print(char *s, t_tag *tag);

void			p_process(t_tag *tag);
void			null_print(t_tag *tag);
void			p_print(long long int p, t_tag *tag);

void			num_process(t_tag *tag);
void			num_int_print(long long int num, int base, t_tag *tag);
void			num_print(long long int num, int base, t_tag *tag);

void			percent_process(t_tag *tag);
void			percent_print(t_tag *tag);

void			make_tag(const char **format, t_tag *tag, va_list ap);
void			decide_arg(t_tag *tag, va_list ap);
int				ft_printf(const char *format, ...);

#endif
