/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:58:04 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/08 16:58:05 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*print_argument(va_list deez_args, t_flag flags)
{
	char	*ans;

	if (flags.precision == (int)0xFFFFFBAD)
		return (NULL);
	if (flags.type == 'x' || flags.type == 'X' || flags.type == 'o'
	|| flags.type == 'u' || flags.type == 'U')
		ans = print_argument_xxou(deez_args, flags);
	if (flags.type == 'p')
		ans = print_argument_p(deez_args, flags);
	if (flags.type == '%' || flags.type == 'c')
		ans = print_argument_percent_c(deez_args, flags);
	if (flags.type == 's')
		ans = print_argument_s(deez_args, flags);
	if (flags.type == 'd' || flags.type == 'i')
		ans = print_argument_di(deez_args, flags);
	if (flags.type == 'C' || flags.type == 'S' ||
	(!ft_strcmp(flags.length, "l") && (flags.type == 'c' || flags.type == 's')))
		ans = print_argument_cs(deez_args, flags);
	return (ans);
}
