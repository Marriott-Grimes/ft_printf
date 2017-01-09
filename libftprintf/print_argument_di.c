/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_di.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:39:43 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/20 16:39:44 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*pad_check_minus(char *str, int len, char c)
{
	char sign;

	if (*str == '-' || *str == '+')
	{
		sign = *str;
		str = pad_and_free(str + 1, len, c);
		str = pad_and_free(str, ft_strlen(str) + 1, sign);
	}
	else
		str = pad_and_free(str, len, c);
	return (str);
}

char			*format_signed(char *str, t_flag flags, int minus_sign)
{
	int extra;

	extra = (flags.space || flags.plus || minus_sign);
	if (flags.precision == 0 && !ft_strcmp(str, "0"))
		str = "";
	if (flags.precision > ft_strlen(str))
		str = pad_and_free(str, flags.precision, '0');
	else if (flags.width > ft_strlen(str) && flags.zero &&
	!flags.minus && flags.precision == -1)
		str = pad_and_free(str, flags.width - extra, '0');
	if (flags.plus && !minus_sign)
		str = ft_strjoin("+", str);
	if (flags.space && !flags.plus && !minus_sign)
		str = ft_strjoin(" ", str);
	if (minus_sign)
		str = ft_strjoin("-", str);
	if (flags.width > ft_strlen(str))
	{
		if (flags.minus)
			str = pad_on_right(str, flags.width, ' ');
		else
			str = pad_and_free(str, flags.width, ' ');
	}
	return (str);
}

t_signed_string	convert_type_di(va_list deez_args, t_flag flags)
{
	t_signed_string	n;
	char			c;
	short			s;

	if (!ft_strcmp(flags.length, "ll"))
		n = ft_lltoa(va_arg(deez_args, long long));
	else if (!ft_strcmp(flags.length, "j"))
		n = ft_lltoa(va_arg(deez_args, intmax_t));
	else if (!ft_strcmp(flags.length, "z"))
		n = ft_lltoa(va_arg(deez_args, size_t));
	else if (!ft_strcmp(flags.length, "l"))
		n = ft_lltoa(va_arg(deez_args, long));
	else if (!ft_strcmp(flags.length, "h"))
	{
		s = (short)va_arg(deez_args, int);
		n = ft_lltoa(s);
	}
	else if (!ft_strcmp(flags.length, "hh"))
	{
		c = (char)va_arg(deez_args, int);
		n = ft_lltoa(c);
	}
	else
		n = ft_lltoa(va_arg(deez_args, int));
	return (n);
}

char				*print_argument_di(va_list deez_args, t_flag flags)
{
	t_signed_string	num;

	num = convert_type_di(deez_args, flags);
	num.str = format_signed(num.str, flags, num.sign);
	return (num.str);
}
