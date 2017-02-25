/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_s.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:13:53 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/14 14:13:55 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_string		print_argument_s(va_list deez_args, t_flag flags)
{
	t_string	str;
	char		*temp;

	str.ptr = va_arg(deez_args, char*);
	if (!str.ptr)
		return ((t_string){"(null)", 6, 0});
	if (flags.precision != -1)
	{
		temp = str.ptr;
		str.ptr = ft_strnew(flags.precision);
		ft_strncpy(str.ptr, temp, flags.precision);
	}
	if (flags.width)
	{
		if (flags.minus)
			str.ptr = pad_on_right(str.ptr, flags.width, ' ');
		else
			str.ptr = pad_and_free(str.ptr, flags.width, ' ');
	}
	str.bytes = ft_strlen(str.ptr);
	return (str);
}
