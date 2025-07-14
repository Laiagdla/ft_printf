/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:44:43 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/14 16:04:36 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

int	main(void)
{
	char	c;

	c = 'a';
	ft_printf("%% Hi, %s%c, You have %i messages and %d new %x, %X, %p, %u \n",
		"Laia", '!', 23, 3, 234, 432, &c, -23);
	printf("%% Hi, %s%c, You have %i messages and %d new %x, %X, %p, %u \n",
		"Laia", '!', 23, 3, 234, 432, &c, -23);
	return (0);
}
