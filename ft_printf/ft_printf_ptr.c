/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:05:12 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/11 15:18:16 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_count_ptr(unsigned int num, int *len)
{
	if (num >= 16)
	{
		ft_count_ptr(num / 16, len);
		num %= 16;
	}
	if (num <= 9)
		*len += ft_printf_char(num + '0');
	else
		*len += ft_printf_char(num - 10 + 'a');
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	len;

	len = 2;
	ft_printf_string("0x");
	ft_count_ptr(ptr, &len);
	return (len);
}
