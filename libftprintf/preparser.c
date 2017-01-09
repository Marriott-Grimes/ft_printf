/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 15:11:28 by mgrimes           #+#    #+#             */
/*   Updated: 2017/01/04 15:11:29 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*strdup_until_car(const char *str, char c)
{
	char	*answer;
	int		len;

	len = 0;
	if (str)
	{
		while (str[len] && str[len] != c)
			len++;
	}
	answer = ft_strnew(len);
	if (!answer)
		return (NULL);
	answer = ft_strncpy(answer, str, len);
	return (answer);
}

int		get_varcount(char *str)
{
	int varcount;
	int i;

	varcount = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			varcount++;
			while (!is_type(str + i) && str[i])
				i++;
			if (str[i])
				i++;
		}
		else
			i++;
	}
	return (varcount);
}

char	**parse_strings(char *str, int varcount, va_list deez_args)
{
	char	**ans;
	int		i;
	t_flag	flags;

	i = 0;
	ans = (char **)malloc(sizeof(char *) * 2 * (varcount + 1));
	while (i < 2 * varcount)
	{
		ans[i] = strdup_until_car(str, '%');
		str = ft_strchr((const char *)str, '%') + 1;
		flags = parser(str, flags);
		ans[i + 1] = print_argument(deez_args, flags);
		while (!is_type(str))
			str++;
		str++;
		i += 2;
	}
	ans[i] = ft_strdup(str);
	ans[i + 1] = NULL;
	return(ans);
}
