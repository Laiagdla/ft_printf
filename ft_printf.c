/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:34:29 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/08 16:46:05 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void	map_functions(t_format_ptr *format_map)
{
	ft_bzero(format_map, 127);
	format_map['c'] = ft_print_char;
	format_map['s'] = ft_print_str;
}

static ssize_t	format_selector(va_list *ap, char c)
{
	t_format_ptr	format_map[127];
	ssize_t			len;

	map_functions(format_map);
	len = 0;
	if (format_map[(int)c])
		len += format_map[(int)c](ap);
	return (len);
}

void	ft_printf(const char *str, ...)
{
	va_list		args;
	ssize_t		len;

	va_start(args, str);
	len = 0;
	while (*str != 0)
	{
		if (*str == '%')
			len += format_selector(&args, *(++str));
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
}
