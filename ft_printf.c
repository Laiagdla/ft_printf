/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 11:34:29 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/06/23 15:42:46 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>

typedef ssize_t	(*t_format_ptr)(va_list *ap);

ssize_t	print_char(va_list *ap)
{
	char	c;

	c = (char)va_arg(*ap, int);
	return (write(1, &c, 1));
}

ssize_t	print_str(va_list *ap)
{
	char	*str;
	ssize_t	len;

	str = va_arg(*ap, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	else
	{
		len = 0;
		while (*str)
			len += write(1, str++, 1);
		return (len);
	}
}

ssize_t	format_sel(va_list *ap, char c)
{
	t_format_ptr	format_map[127] = {NULL};
	ssize_t			len;

	len = 0;
	format_map['s'] = print_str;
	format_map['c'] = print_char;

	if (format_map[(int)c])
		len += format_map[(int)c](ap);
	return (len);
}

void	my_printf(const char *str, ...)
{
	va_list		args;
	ssize_t		len;

	va_start(args, str);
	len = 0;
	while (*str != 0)
	{
		if (*str == '%')
			len += format_sel(&args, *(++str));
		else
			len += write(1, str, 1);
		str++;
	}
	va_end(args);
}

int	main(void)
{
	my_printf("Hello, %s! You have new messages.\n", "Alice");
	return (0);
}
