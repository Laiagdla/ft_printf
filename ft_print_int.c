/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:41:01 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/15 14:28:42 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_putint(int nb)
{
	char	c;

	c = nb + '0';
	return (write(1, &c, 1));
}

static ssize_t	ft_putnbr(int n)
{
	ssize_t	len;

	len = 0;
	if (n == -2147483648)
		return (len += write(1, "-2147483648", 11));
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	len += ft_putint(n % 10);
	return (len);
}

ssize_t	ft_print_int(va_list *ap)
{
	return (ft_putnbr(va_arg(*ap, int)));
}

ssize_t	ft_print_uint(va_list *ap)
{
	return (ft_putnbr((unsigned int)va_arg(*ap, int)));
}
