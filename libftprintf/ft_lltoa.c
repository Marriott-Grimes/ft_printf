/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 16:40:03 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/20 16:40:05 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char			*digit_copy_ll(char *temp, long long n)
{
	if (n > 0)
	{
		while (n != 0)
		{
			temp--;
			*temp = '0' + n % 10;
			n /= 10;
		}
	}
	else
	{
		while (n != 0)
		{
			temp--;
			*temp = '0' - n % 10;
			n /= 10;
		}
	}
	return (temp);
}

t_signed_string		ft_lltoa(long long n)
{
	char			*temp;
	t_signed_string	ans;

	ans.sign = 0;
	if (n == 0)
	{
		ans.str = "0";
		return (ans);
	}
	if (n < 0)
		ans.sign = 1;
	temp = ft_strnew(22);
	if (!temp)
		ans.str = NULL;
	ans.str = digit_copy_ll(temp + 22, n);
	ans.str = ft_strdup(ans.str);
	free(temp);
	return (ans);
}
