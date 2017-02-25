/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:10:09 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/04 17:10:11 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*type_convert_xxou(va_list deez_args, t_flag flags, int base)
{
	unsigned char	c;
	unsigned short	s;
	char			*ans;

	if (!ft_strcmp(flags.length, "hh"))
	{
		c = (unsigned char)va_arg(deez_args, unsigned int);
		ans = ft_llutoa_base(c, base);
	}
	else if (!ft_strcmp(flags.length, "h") && flags.type != 'U')
	{
		s = (unsigned short)va_arg(deez_args, unsigned int);
		ans = ft_llutoa_base(s, base);
	}
	else if (!ft_strcmp(flags.length, "l") || flags.type == 'U')
		ans = ft_llutoa_base(va_arg(deez_args, unsigned long), base);
	else if (!ft_strcmp(flags.length, "ll"))
		ans = ft_llutoa_base(va_arg(deez_args, unsigned long long), base);
	else if (!ft_strcmp(flags.length, "j"))
		ans = ft_utoa_base(va_arg(deez_args, uintmax_t), base);
	else if (!ft_strcmp(flags.length, "z"))
		ans = ft_utoa_base(va_arg(deez_args, size_t), base);
	else
		ans = ft_utoa_base(va_arg(deez_args, unsigned int), base);
	return (ans);
}

t_string		print_argument_xxou(va_list deez_args, t_flag flags)
{
	int			base;
	t_string	str;

	base = 0;
	if (flags.type == 'x' || flags.type == 'X')
		base = 16;
	else if (flags.type == 'o' || flags.type == 'O')
		base = 8;
	else if (flags.type == 'u' || flags.type == 'U')
		base = 10;
	str.ptr = type_convert_xxou(deez_args, flags, base);
	str.ptr = format_unsigned(str.ptr, flags);
	str.bytes = ft_strlen(str.ptr);
	return (str);
}
