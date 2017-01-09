/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_padding.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 16:55:59 by mgrimes           #+#    #+#             */
/*   Updated: 2016/12/19 16:56:02 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*pad_and_free(char *str, int len, char c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = str;
	str = ft_strnew(len);
	while (i < len - ft_strlen(temp))
		str[i++] = c;
	str = ft_strcat(str, temp);
	return (str);
}

char		*pad_on_right(char *str, int len, char c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = str;
	str = ft_strnew(len);
	while (temp[i] && i < len)
	{
		str[i] = temp[i];
		i++;
	}
	while (i < len)
		str[i++] = c;
	return (str);
}
