/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:38:42 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/17 11:04:17 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_unsigned(unsigned int n)
{
	int		len;
	char	c;

	len = 0;
	if (n > 9)
		len += ft_putnbr_unsigned(n / 10);
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_print_uint(va_list *ap)
{
	return (ft_putnbr_unsigned((unsigned int)va_arg(*ap, int)));
}
