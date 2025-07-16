/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:36:34 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/16 12:17:29 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
// # include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

typedef int	(*t_format_ptr)(va_list *ap);

int		ft_print_char(va_list *ap);
int		ft_print_str(va_list *ap);
int		ft_print_int(va_list *ap);
int		ft_print_uint(va_list *ap);
int		ft_print_ptr(va_list *ap);
int		ft_print_hex(va_list *ap);
int		ft_print_hex_up(va_list *ap);
int		ft_printf(const char *str, ...);

#endif
