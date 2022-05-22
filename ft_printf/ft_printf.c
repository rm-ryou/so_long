/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:06:40 by rmoriya           #+#    #+#             */
/*   Updated: 2022/03/28 16:14:40 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(va_list args, const char format)
{
	int	n;

	n = 0;
	if (format == 'c')
		n = ft_printf_char(va_arg(args, int));
	else if (format == 's')
		n = ft_printf_string(va_arg(args, char *));
	else if (format == 'p')
		n = ft_printf_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		n = ft_printf_int(va_arg(args, int));
	else if (format == 'u')
		n = ft_printf_uint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		n = ft_printf_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		n = ft_printf_char('%');
	return (n);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_printf_format(args, format[i]);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
