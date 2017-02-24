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

static char	*format_wcar(wchar_t c, t_flag flags)
{
	char *str;
	int len;
	int bytes;
	int i;

	i = 0;
	bytes = wcar_bytes(c);
	len = ft_max(bytes, flags.width - bytes + 1);
	str = ft_strnew(len);
	if (flags.minus)
	{
		copy_wcar(c, str);
		i += bytes;
		while (i < len - bytes + 1)
			str[i++] = ' ';
	}
	else
	{
		while (i < len - bytes)
			str[i++] = ' ';
		copy_wcar(c, str + i);
	}
	return (str);
}

static char	*format_wstr(wchar_t *wstr, t_flag flags)
{
	char *str;
	char *temp;

	str = utf_convert(wstr);
	if (!wstr)
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

char		*print_argument_cs(va_list deez_args, t_flag flags)
{
	wchar_t c;
	wchar_t *wstr;
	char	*ans;

	if (MB_CUR_MAX == 1)
		return (NULL);
	if (flags.type == 'C' || flags.type == 'c')
	{
		c = va_arg(deez_args, wchar_t);
		ans = format_wcar(c, flags);
	}
	else
	{
		wstr = va_arg(deez_args, wchar_t *);
		ans = format_wstr(wstr, flags);
	}
	return (ans);
}
