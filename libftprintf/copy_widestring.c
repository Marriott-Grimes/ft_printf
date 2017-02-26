/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_widestring.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 22:29:15 by mgrimes           #+#    #+#             */
/*   Updated: 2017/02/22 22:29:20 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*copy_wcar_part_two(wchar_t wc, char *str)
{
	if (wc <= 0x7FF)
	{
		str[0] = (((wc & 0x07C0) >> 6) + 0xC0);
		str[1] = ((wc & 0x003F) + 0x80);
		str += 2;
	}
	else if (wc <= 0xFFFF)
	{
		str[0] = (((wc & 0xF000) >> 12) + 0xE0);
		str[1] = (((wc & 0x0FC0) >> 6) + 0x80);
		str[2] = ((wc & 0x003F) + 0x80);
		str += 3;
	}
	else if (wc <= 0x10FFFF)
	{
		str[0] = (((wc & 0x1C0000) >> 18) + 0xF0);
		str[1] = (((wc & 0x03F000) >> 12) + 0x80);
		str[2] = (((wc & 0x0FC0) >> 6) + 0x80);
		str[3] = ((wc & 0x003F) + 0x80);
		str += 4;
	}
	return (str);
}

char		*copy_wcar(wchar_t wc, char *str)
{
	if (wc <= 0xFF)
	{
		str[0] = wc;
		str++;
	}
	else
		str = copy_wcar_part_two(wc, str);
	return (str);
}
