/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:13:47 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/14 14:13:49 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_string	format_car(unsigned char c, t_flag flags)
{
	int			i;
	t_string	str;

	i = 0;
	str.bytes = ft_max(1, flags.width);
	str.ptr = ft_strnew(str.bytes);
	if (flags.minus)
	{
		str.ptr[i++] = c;
		while (i < str.bytes)
			str.ptr[i++] = ' ';
	}
	else
	{
		while (i < str.bytes - 1)
			str.ptr[i++] = ' ';
		str.ptr[i] = c;
	}
	return (str);
}

t_string	print_argument_percent_c(va_list deez_args, t_flag flags)
{
	unsigned char	c;
	t_string		ans;

	if (flags.type == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(deez_args, unsigned int);
	ans = format_car(c, flags);
	return (ans);
}
