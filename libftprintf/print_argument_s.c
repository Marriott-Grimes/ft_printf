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

char		*print_argument_s(va_list deez_args, t_flag flags)
{
	char	*str;
	char	*temp;

	str = va_arg(deez_args, char*);
	if (!str)
		return ("(null)");
	if (flags.precision != -1)
	{
		temp = str;
		str = ft_strnew(flags.precision);
		ft_strncpy(str, temp, flags.precision);
	}
	if (flags.width)
	{
		if (flags.minus)
			str = pad_on_right(str, flags.width, ' ');
		else
			str = pad_and_free(str, flags.width, ' ');
	}
	return (str);
}
