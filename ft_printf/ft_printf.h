/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:29:42 by awhana            #+#    #+#             */
/*   Updated: 2021/04/29 13:32:23 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct s_flags
{
	int		zero;
	int		minus;
	int		dot;
	int		width;
	int		star;
	char	type;
}			t_flags;

int			ft_putchar(int c);
int			ft_putstr(char *s, int dot);
int			write_until_precision(char *string, int precision);
int			count_of_nums(long n);
int			length_of_u2(long num);
char		*str_to_lower(char *string);
char		*unsigned_itoa(unsigned int n);
t_flags		flag_minus(t_flags flags);
t_flags		flag_digit(char c, t_flags flags);
t_flags		flag_width(va_list arg, t_flags flags);
int			flag_dot(int start, char *form, t_flags *flags, va_list arg);
int			write_width(int width, int minus, int zero);
int			write_int(long int i, t_flags flags);
int			write_char(char c, t_flags flags);
int			write_string(char *string, t_flags flags);
int			length_of_u2(long n);
int			write_pointer(unsigned long long pointer, t_flags flags);
int			write_unsigned_int(unsigned int i, t_flags flags);
int			write_hex(unsigned int i, t_flags flags);
t_flags		init_flags(t_flags flags);
int			type_was_found(char s);
int			flag_was_found(char s);
int			write_percent(t_flags flags);
int			ft_printf(const char *format, ...);

#endif
