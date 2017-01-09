/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:59:02 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/09 16:59:03 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char			*print_argument_p(va_list deez_args, t_flag flags)
{
	char			*str;
	unsigned long	n;

	n = (unsigned long)va_arg(deez_args, void *);
	str = ft_llutoa_base(n, 16);
	flags.hash = 1;
	flags.type = 'X';
	str = format_unsigned(str, flags);
	return (str);
}