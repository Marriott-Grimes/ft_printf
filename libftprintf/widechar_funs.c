/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widechar_funs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:29:02 by mgrimes           #+#    #+#             */
/*   Updated: 2017/02/22 22:29:03 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		wcar_bytes(wchar_t wc)
{
	int j;

	j = 0;
	if (wc <= 0xFF)
		j = 1;
	else if (wc <= 0x7FF)
		j = 2;
	else if (wc <= 0xFFFF)
		j = 3;
	else if (wc <= 0x10FFFF)
		j = 4;
	return (j);
}

int		wstr_bytes(wchar_t *wstr)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (wstr[i])
	{
		j += wcar_bytes(wstr[i]);
		i++;
	}
	return (j);
}

char	*utf_convert(wchar_t *wstr, int prec)
{
	char	*str;
	char	*ans;
	int		i;
	int		len;

	len = wstr_bytes(wstr);
	if (prec != -1)
		len = ft_min(len, prec);
	ans = ft_strnew(len);
	str = ans;
	i = 0;
	while (wstr[i] && wcar_bytes(wstr[i]) <= len)
	{
		len -= wcar_bytes(wstr[i]);
		str = copy_wcar(wstr[i], str);
		i++;
	}
	return (ans);
}
