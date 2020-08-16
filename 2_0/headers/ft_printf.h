/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:38:25 by julboyer          #+#    #+#             */
/*   Updated: 2020/08/16 10:42:39 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <wchar.h>

typedef union			u_type
{
	void				*p;
	long long int		lli;
	unsigned long long	ulli;
	char				*s;
	wchar_t				*ls;
	double				lf;
	long double			llf;
	short int			*sn;
	int					*n;
	long int			*ln;
	long long int		*lln;
}						t_type;

typedef struct			s_flags
{
	char				convert;
	int					type;
	char				pref;
	int					prec;
	char				flag_width;
	int					width;
	t_type				u;
}						t_flags;

char					*ft_ulltoa_base(unsigned long long int n,
		char *base);
char					*ft_dot_flag(char *src, int i, t_flags flags);
char					*ft_width(char *src, unsigned int len, t_flags flag);
char					*ft_diese_flag(char *s, t_flags flags);
int						ft_printf(const char *s,
		...) __attribute__((format(printf,1,2)));
char					*ft_lltoa_abs(long long int n);
char					*ft_zero_flag(char *src, int len);
char					*ft_positive_flag(char *s, t_flags flags,
		long long int nbr);
int						ft_isprintflag(char c);
int						ft_isprintconvert(char c);
void					ft_putwc(wint_t c);
int						ft_putwstr(wchar_t *s);
int						ft_printarg(t_flags flags, va_list params, int res);
wchar_t					*ft_lwidth(wchar_t *src, unsigned int len,
		char flag);
int						ft_chandle(t_flags flags, va_list params);
int						ft_shandle(t_flags flags, va_list params);
size_t					ft_lstrlen(const wchar_t *str);
wchar_t					*ft_lstrdup(wchar_t *s1);
wchar_t					*ft_ldot_flag(wchar_t *src, int i);
int						ft_d_handle(t_flags flags, va_list params);
long long int			ft_atoll(const char *str);
int						ft_xhandle(t_flags flags, va_list params);
int						ft_p_handle(t_flags flags, va_list params);
void					ft_nhandle(t_flags flags, va_list params, int res);
int						ft_print(char *s, t_flags flags);

#endif
