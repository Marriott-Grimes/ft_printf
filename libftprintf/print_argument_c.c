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

char			*format_car(unsigned char c, t_flag flags)
{
	int i;
	int len;
	char *str;

	i = 0;
	len = ft_max(1, flags.width);
	str = ft_strnew(len);
	if (flags.minus)
	{
		str[i++] = c;
		while (i < len)
			str[i++] = ' ';
	}
	else
	{
		while (i < len - 1)
			str[i++] = ' ';
		str[i] = c;
	}
	return (str);
}

char			*print_argument_percent_c(va_list deez_args, t_flag flags)
{
	unsigned char	c;
	char			*ans;

	if (flags.type == '%')
		c = '%';
	else
		c = (unsigned char)va_arg(deez_args, unsigned int);
	ans = format_car(c, flags);
	return (ans);
}
