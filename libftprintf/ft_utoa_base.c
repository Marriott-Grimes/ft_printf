/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:09:48 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/04 17:09:59 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*digit_copy(char *temp, uintmax_t n, int base)
{
	char *tab;

	tab = "0123456789abcdef";
	while (n != 0)
	{
		temp--;
		*temp = tab[n % base];
		n /= base;
	}
	return (temp);
}

static char	*digit_copy_ull(char *temp, unsigned long long n, int base)
{
	char *tab;

	tab = "0123456789abcdef";
	while (n != 0)
	{
		temp--;
		*temp = tab[n % base];
		n /= base;
	}
	return (temp);
}

char		*add_prefix_xxou(char *str, t_flag flags)
{
	char	*temp;
	char	*ans;
	int		pref;

	pref = 0;
	pref += (flags.type == 'o') ? 1 : 0;
	pref += (flags.type == 'x' || flags.type == 'X') ? 1 : 0;
	ans = (char *)malloc(ft_strlen(str) + pref);
	temp = ans;
	*temp++ = '0';
	if (flags.type == 'x')
		*temp++ = 'x';
	else if (flags.type == 'X')
		*temp++ = 'X';
	temp = ft_strcpy(temp, str);
	return (ans);
}

char		*ft_utoa_base(uintmax_t n, int base)
{
	char	*temp;
	char	*ans;

	if (n == 0)
	{
		ans = "0";
		return (ans);
	}
	temp = ft_strnew(42);
	if (!temp)
		return (NULL);
	ans = temp + 42;
	ans = digit_copy(ans, n, base);
	ans = ft_strdup(ans);
	free(temp);
	return (ans);
}

char		*ft_llutoa_base(unsigned long long n, int base)
{
	char	*temp;
	char	*ans;

	if (n == 0)
	{
		ans = "0";
		return (ans);
	}
	temp = ft_strnew(42);
	if (!temp)
		return (NULL);
	ans = temp + 42;
	ans = digit_copy_ull(ans, n, base);
	ans = ft_strdup(ans);
	free(temp);
	return (ans);
}
