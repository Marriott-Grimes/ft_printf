/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper_funs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 17:07:13 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/21 17:07:21 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_flag	get_initial_flags(char *str, t_flag flags)
{
	while (is_intial_flag(str))
	{
		if (*str == '-')
			flags.minus = 1;
		if (*str == '+')
			flags.plus = 1;
		if (*str == ' ')
			flags.space = 1;
		if (*str == '0')
			flags.zero = 1;
		if (*str == '#')
			flags.hash = 1;
		str++;
	}
	return (flags);
}

char	*get_length_flag(char *str)
{
	char *ans;

	if (*str == 'h')
	{
		if (*(str + 1) == 'h')
			ans = "hh";
		else
			ans = "h";
	}
	if (*str == 'l')
	{
		if (*(str + 1) == 'l')
			ans = "ll";
		else
			ans = "l";
	}
	if (*str == 'L')
		ans = "L";
	if (*str == 'j')
		ans = "j";
	if (*str == 'z')
		ans = "z";
	return (ans);
}

t_flag	clear_flags(t_flag flags)
{
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.hash = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.length = "";
	flags.type = 0;
	return (flags);
}
