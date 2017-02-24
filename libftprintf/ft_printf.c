/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:43:51 by mgrimes           #+#    #+#             */
/*   Updated: 2016/11/16 18:43:53 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**  (\ __/)
**  ( ^-^ )
**  (() (()
** *(_(")(")
*/

int g_nullcharoffset;

int	twenny_five_lines(char *str, va_list deez_args)
{
	int		ans;
	int		i;
	int		varcount;
	char	**arr;

	g_nullcharoffset = 0;
	ans = 0;
	i = 0;
	varcount = get_varcount(str);
	arr = parse_strings(str, varcount, deez_args);
	while (i < 2 * varcount + 1)
	{
		if (arr[i++] == NULL)
			return (-1);
	}
	i = 0;
	while (i < 2 * varcount + 1)
	{
		ft_putstr(arr[i]);	
		ans += ft_strlen(arr[i]);
		i++;
	}
	return (ans + g_nullcharoffset);
}

int	ft_printf(const char *format, ...)
{
	int		ans;
	char	*str;
	va_list	deez_args;

	str = (char *)format;
	va_start(deez_args, format);
	ans = twenny_five_lines(str, deez_args);
	va_end(deez_args);
	return (ans);
}
