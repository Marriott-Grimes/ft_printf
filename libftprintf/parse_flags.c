/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:55:19 by mgrimes           #+#    #+#             */
/*   Updated: 2016/11/18 15:55:28 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag			parser2(char *str, t_flag flags)
{
	if (is_length_flag(str))
		flags.length = get_length_flag(str);
	while (is_length_flag(str))
		str++;
	if (is_type(str))
		flags.type = *str;
	else
		flags.precision = 0xFFFFFBAD;
	return (flags);
}

t_flag			parser(char *str, t_flag flags)
{
	flags = clear_flags(flags);
	if (is_intial_flag(str))
	{
		flags = get_initial_flags(str, flags);
		while (is_intial_flag(str))
			str++;
	}
	if (*str >= '1' && *str <= '9')
	{
		flags.width = ft_atoi(str);
		str += (*str >= '1' && *str <= '9' ? 1 : 0);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	if (*str == '.')
	{
		str++;
		flags.precision = ft_atoi(str);
		str += (*str >= '1' && *str <= '9' ? 1 : 0);
		while (*str >= '0' && *str <= '9')
			str++;
	}
	flags = parser2(str, flags);
	return (flags);
}
