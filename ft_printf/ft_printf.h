/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:20:07 by rmoriya           #+#    #+#             */
/*   Updated: 2022/03/28 16:15:18 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printf_format(va_list args, const char format);
int	ft_printf_char(char c);
int	ft_printf_string(char *s);
int	ft_printf_int(int i);
int	ft_printf_uint(unsigned int i);
int	ft_printf_ptr(unsigned long long ptr);
int	ft_printf_hexa(unsigned int num, const char format);

#endif
