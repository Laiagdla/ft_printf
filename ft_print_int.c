/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:41:01 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/16 12:11:54 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putint(int nb)
{
	char	c;

	c = nb + '0';
	return (write(1, &c, 1));
}

static int	ft_putnbr(long n)
{
	int	len;

	len = 0;
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

int	ft_print_int(va_list *ap)
{
	return (ft_putnbr((long)va_arg(*ap, int)));
}
