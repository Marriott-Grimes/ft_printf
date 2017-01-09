/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:19:41 by mgrimes           #+#    #+#             */
/*   Updated: 2016/11/21 16:19:43 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	is_type(char *str)
{
	if (*str == 's' || *str == 'S' || *str == 'p' || *str == 'd' || *str == 'D'
	|| *str == 'i' || *str == 'o' || *str == 'O' || *str == 'u' || *str == 'U'
	|| *str == 'x' || *str == 'X' || *str == 'c' || *str == 'C' || *str == '%')
		return (1);
	return (0);
}

int		is_intial_flag(char *s)
{
	if (*s == '-' || *s == '+' || *s == ' ' || *s == '0' || *s == '#')
		return (1);
	return (0);
}

int		is_length_flag(char *s)
{
	if (*s == 'h' || *s == 'l' || *s == 'L' || *s == 'j' || *s == 'z')
		return (1);
	return (0);
}
