/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:41:34 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/16 12:14:26 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(va_list *ap)
{
	char	*str;
	int		len;

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
