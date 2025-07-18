/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:06:29 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/16 12:17:47 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_puthex(uintptr_t nb, const char format)
{
	int		len;
	char	style;

	len = 0;
	style = 'a';
	if (format == 'X')
		style = 'A';
	if (nb >= 16)
		len += ft_puthex(nb / 16, format);
	nb %= 16;
	if (nb <= 9)
		len += ft_putchar(nb + '0');
	else
		len += ft_putchar(nb - 10 + style);
	return (len);
}

int	ft_print_hex(va_list *ap)
{
	return (ft_puthex(va_arg(*ap, unsigned int), 'x'));
}

int	ft_print_hex_up(va_list *ap)
{
	return (ft_puthex(va_arg(*ap, unsigned int), 'X'));
}

int	ft_print_ptr(va_list *ap)
{
	uintptr_t	address;

	address = (uintptr_t)va_arg(*ap, void *);
	if (address == 0)
		return (write(1, "(nil)", 5));
	return (write(1, "0x", 2) + ft_puthex(address, 'x'));
}
