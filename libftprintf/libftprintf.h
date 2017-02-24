/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:18:13 by mgrimes           #+#    #+#             */
/*   Updated: 2016/09/29 21:12:53 by mgrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

# define WHITE(c) (c==' '||c == '\n'||c == '\t'||c == '\v'||c =='\f'||c=='\r')
# define ISWHITESPACE(c) (c == ' ' || c == '\n' || c == '\t')

typedef	struct	s_flag
{
	char		minus;
	char		plus;
	char		space;
	char		zero;
	char		hash;
	int			width;
	int			precision;
	char		*length;
	char		type;
}				t_flag;

typedef	struct	s_signed_string
{
	char		*str;
	int			sign;
}				t_signed_string;

char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putchar(char c);
void			ft_putstr(const char *s);
int				ft_strlen(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t length);
int				ft_toupper(int c);
int				ft_atoi(char *str);
char			*ft_strdup(const char *str);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
int				ft_max(int a, int b);
int				ft_min(int a, int b);
int				is_type(char *str);
t_flag			parser(char *str, t_flag flags);
t_flag			clear_flags(t_flag flags);
int				is_intial_flag(char *s);
int				is_length_flag(char *s);
t_flag			get_initial_flags(char *str, t_flag flags);
char			*get_length_flag(char *str);
t_signed_string	ft_lltoa(long long n);
char			*ft_utoa_base(uintmax_t n, int base);
char			*ft_llutoa_base(unsigned long long n, int base);
char			*pad_and_free(char *str, int len, char c);
char			*pad_on_right(char *str, int len, char c);
char			*format_unsigned(char *tr, t_flag flags);
char			*print_argument(va_list deez_args, t_flag flags);
char			*print_argument_xxou(va_list deez_args, t_flag flags);
char			*print_argument_p(va_list deez_args, t_flag flags);
char			*print_argument_s(va_list deez_args, t_flag flags);
char			*print_argument_percent_c(va_list deez_args, t_flag flags);
char			*print_argument_di(va_list deez_args, t_flag flags);
char			*print_argument_cs(va_list deez_args, t_flag flags);
void			ft_putchar_xxou(char c, t_flag flags);
int				get_varcount(char *str);
char			**parse_strings(char *str, int varcount, va_list deez_args);
int				ft_printf(const char *format, ...);
int				wstrlen(wchar_t *wstr);
int				wcar_bytes(wchar_t wc);
int				wstr_bytes(wchar_t *wstr);
char			*copy_wcar(wchar_t wc, char *str);
char			*utf_convert(wchar_t *wstr);


#endif
