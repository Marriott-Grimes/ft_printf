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

int		wstrlen(wchar_t *wstr)
{
	int i;

	i = 0;
	while (wstr[i])
		i++;
	return (i);
}

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

char	*utf_convert(wchar_t *wstr)
{
	char	*str;
	char	*ans;
	int		i;

	ans = ft_strnew(wstr_bytes(wstr));
	str = ans;
	i = 0;
	while (wstr[i])
	{
		str = copy_wcar(wstr[i], str);
		i++;
	}
	return (ans);
}
