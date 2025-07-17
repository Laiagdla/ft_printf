/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:41:01 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/17 11:04:00 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(long n)
{
	int		len;
	char	c;

	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_print_int(va_list *ap)
{
	return (ft_putnbr((long)va_arg(*ap, int)));
}
