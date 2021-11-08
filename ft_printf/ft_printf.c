/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awhana <awhana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:56:17 by awhana            #+#    #+#             */
/*   Updated: 2021/04/30 14:03:27 by awhana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

int	treat_the_type(int c, t_flags flags, va_list arg)
{
	int		length;

	length = 0;
	if (c == 'c')
		length = write_char(va_arg(arg, int), flags);
	else if (c == 's')
		length = write_string(va_arg(arg, char *), flags);
	else if (c == 'p')
		length = write_pointer(va_arg(arg, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		length = write_int(va_arg(arg, int), flags);
	else if (c == 'u')
		length += write_unsigned_int(va_arg(arg, unsigned int), flags);
	else if (c == 'x')
		length += write_hex(va_arg(arg, unsigned int), flags);
	else if (c == 'X')
		length += write_hex(va_arg(arg, unsigned int), flags);
	else if (c == '%')
		length += write_percent(flags);
	return (length);
}

int	parse_flag(char *format, int i, t_flags *flags, va_list arg)
{
	while (format[i])
	{
		if (!ft_isdigit(format[i]) && !type_was_found(format[i])
			&& !flag_was_found(format[i]))
			break ;
		if (format[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (format[i] == '.')
			i = flag_dot(i, format, flags, arg);
		if (format[i] == '-')
			*flags = flag_minus(*flags);
		if (format[i] == '*')
			*flags = flag_width(arg, *flags);
		if (ft_isdigit(format[i]))
			*flags = flag_digit(format[i], *flags);
		if (type_was_found(format[i]))
		{
			flags->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	parse_format(char *format, va_list arg)
{
	int		length;
	int		i;
	t_flags	flags;

	i = 0;
	length = 0;
	while (format[i])
	{
		flags = init_flags(flags);
		if (format[i] == '%' && format[i + 1])
		{
			i = parse_flag(format, ++i, &flags, arg);
			if (type_was_found(format[i]))
				length += treat_the_type((char)flags.type, flags, arg);
			else if (format[i])
				length += write(1, &format[i], 1);
		}
		else if (format[i] != '%')
			length += write(1, &format[i], 1);
		i++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			length;
	char		*form;

	form = ft_strdup(format);
	va_start(arg, format);
	length = parse_format(form, arg);
	va_end(arg);
	free((char *)form);
	return (length);
}
