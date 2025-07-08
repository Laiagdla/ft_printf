/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrobe-d <lgrobe-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:36:34 by lgrobe-d          #+#    #+#             */
/*   Updated: 2025/07/08 16:46:14 by lgrobe-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <sys/types.h>

typedef ssize_t	(*t_format_ptr)(va_list *ap);

void	ft_bzero(void *s, size_t n);
ssize_t	ft_print_char(va_list *ap);
ssize_t	ft_print_str(va_list *ap);
void	ft_printf(const char *str, ...);

#endif
