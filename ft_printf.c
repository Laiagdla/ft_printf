/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:34:29 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/16 12:29:27 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_selector(va_list *ap, char c);

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			len;

	va_start(args, str);
	len = 0;
	while (*str != 0)
	{
		if (*str == '%')
		{
			if (*(++str) == '%')
				len += write(1, "%", 1);
			else
				len += format_selector(&args, *str);
		}
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
	return ((int)len);
}

static int	format_selector(va_list *ap, char c)
{
	t_format_ptr	format_map[127];
	int				len;
	int				mapsize;

	mapsize = 127;
	while (mapsize)
		format_map[--mapsize] = NULL;
	format_map['c'] = ft_print_char;
	format_map['s'] = ft_print_str;
	format_map['p'] = ft_print_ptr;
	format_map['d'] = ft_print_int;
	format_map['i'] = ft_print_int;
	format_map['u'] = ft_print_uint;
	format_map['x'] = ft_print_hex;
	format_map['X'] = ft_print_hex_up;
	format_map['%'] = ft_print_char;
	len = 0;
	if (format_map[(int)c])
		len += format_map[(int)c](ap);
	return (len);
}
