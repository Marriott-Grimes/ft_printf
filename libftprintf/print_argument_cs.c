/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_cs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 21:33:19 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/20 21:33:21 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static t_string	format_wcar(wchar_t c, t_flag flags)
{
	t_string	str;
	int			len;
	int			i;

	i = 0;
	str.bytes = wcar_bytes(c);
	len = ft_max(str.bytes, flags.width - str.bytes + 1);
	str.ptr = ft_strnew(len);
	if (flags.minus)
	{
		copy_wcar(c, str.ptr);
		i += str.bytes;
		while (i < len - str.bytes + 1)
			str.ptr[i++] = ' ';
	}
	else
	{
		while (i < len - str.bytes)
			str.ptr[i++] = ' ';
		copy_wcar(c, str.ptr + i);
	}
	str.bytes = len;
	return (str);
}

static t_string	format_wstr(wchar_t *wstr, t_flag flags)
{
	t_string	str;

	if (!wstr)
		return ((t_string){"(null)", 6, 0});
	str.ptr = utf_convert(wstr, flags.precision);
	str.bytes = ft_strlen(str.ptr);
	if (flags.width > str.bytes)
	{
		str.bytes = flags.width;
		if (flags.minus)
			str.ptr = pad_on_right(str.ptr, flags.width, ' ');
		else
			str.ptr = pad_and_free(str.ptr, flags.width, ' ');
	}
	return (str);
}

t_string		print_argument_cs(va_list deez_args, t_flag flags)
{
	wchar_t		c;
	wchar_t		*wstr;
	t_string	ans;

	// if (MB_CUR_MAX == 1)
	// 	return ((t_string){NULL, 0, 0});
	if (flags.type == 'C' || flags.type == 'c')
	{
		c = va_arg(deez_args, wchar_t);
		ans = format_wcar(c, flags);
	}
	else if (flags.type == 'S' || flags.type == 's')
	{
		wstr = va_arg(deez_args, wchar_t *);
		ans = format_wstr(wstr, flags);
	}
	else
		return ((t_string){NULL, 0, 0});
	return (ans);
}
