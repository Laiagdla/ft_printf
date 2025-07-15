/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:38:42 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/15 14:40:15 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	ft_putint(int nb)
{
	char	c;

	c = nb + '0';
	return (write(1, &c, 1));
}

static ssize_t	ft_putnbr_unsigned(unsigned int n)
{
	ssize_t	len;

	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		len += ft_putnbr_unsigned(n / 10);
	len += ft_putint(n % 10);
	return (len);
}

ssize_t	ft_print_uint(va_list *ap)
{
	return (ft_putnbr_unsigned((unsigned int)va_arg(*ap, int)));
}
