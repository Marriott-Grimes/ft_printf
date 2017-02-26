/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 18:38:16 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/12 18:38:19 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*str_toupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

char		*save_prefix(t_flag flags, char *n)
{
	char	*ans;
	int		len;

	len = 0;
	if (!ft_strcmp(n, "0") || !flags.hash)
		return ("");
	if (flags.type == 'o' || flags.type == 'O' || flags.type == 'x' ||
		flags.type == 'X')
		len++;
	if (flags.type == 'x' || flags.type == 'X')
		len++;
	ans = ft_strnew(len);
	if (flags.type == 'o' || flags.type == 'O' || flags.type == 'x' ||
		flags.type == 'X')
		ans[0] = '0';
	if (flags.type == 'x')
		ans[1] = 'x';
	if (flags.type == 'X')
		ans[1] = 'X';
	return (ans);
}

char		*format_unsigned_2(char *str, t_flag flags, char *prefix)
{
	if (flags.zero && !flags.minus)
		str = pad_and_free(str, flags.width - ft_strlen(prefix), '0');
	str = ft_strjoin(prefix, str);
	if (!flags.zero || flags.minus)
	{
		if (!flags.minus)
			str = pad_and_free(str, flags.width, ' ');
		else
			str = pad_on_right(str, flags.width, ' ');
	}
	return (str);
}

char		*format_unsigned(char *str, t_flag flags)
{
	char	*prefix;

	prefix = save_prefix(flags, str);
	if (flags.precision == 0 && !ft_strcmp(str, "0") &&
		((flags.type != 'o' && flags.type != 'O') || !flags.hash))
		str = "";
	if (flags.precision > ft_strlen(str))
		str = pad_and_free(str, flags.precision, '0');
	if (flags.width > ft_strlen(str))
		str = format_unsigned_2(str, flags, prefix);
	else
		str = ft_strjoin(prefix, str);
	if (flags.type == 'X')
		str_toupper(str);
	return (str);
}
