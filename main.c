/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:44:43 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/15 14:24:39 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	char	c;
	int		len;

	c = 'a';
	len = ft_printf("%d\n", 34567);
	ft_printf("%d\n", len);
	len = printf("%d\n", 34567);
	ft_printf("%d\n", len);

	len = ft_printf("%p\n", &c);
	ft_printf("%d\n", len);
	len = ft_printf("%p\n", &c);
	ft_printf("%d\n", len);

	len = ft_printf("%% Hi, %s%c, You have %i messages and %d new\n",
		"Laia", '!', 23, 3);
	ft_printf("%d\n", len);
	len = printf("%% Hi, %s%c, You have %i messages and %d new\n",
		"Laia", '!', 23, 3);
	ft_printf("%d\n", len);

	len = ft_printf("%% Hi, %s%c, You have %i messages and %d new %x, %X, %p,\n",
		"Laia", '!', 23, 3, 234, 432, &c);
	ft_printf("%d\n", len);
	len = printf("%% Hi, %s%c, You have %i messages and %d new %x, %X, %p,\n",
		"Laia", '!', 23, 3, 234, 432, &c);
	ft_printf("%d\n", len);
	// ft_printf("%p\n", -1);
	ft_printf("%d", 0);
	printf("%d", 0);
	return (0);
}
