/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julboyer <julboyer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:38:25 by julboyer          #+#    #+#             */
/*   Updated: 2020/09/12 14:49:05 by julboyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H
# include <string.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <wchar.h>
# include <unistd.h>
# ifndef MAXDIGIT
#  define MAXDIGIT 1080
# endif
# define LOG10_2 0.30102999566398119521373889472449
# define MSKMANTIS 4503599627370495UL

typedef struct			s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef union			u_type
{
	void				*p;
	long long int		lli;
	unsigned long long	ulli;
	char				*s;
	wchar_t				*ls;
	double				d;
	short int			*sn;
	int					*n;
	long int			*ln;
	long long int		*lln;
}						t_type;

typedef struct			s_flags
{
	char				conv;
	int					type;
	char				pref;
	char				sharp;
	int					prec;
	char				flag_width;
	int					width;
	int					s_conv;
	int					total_len;
	t_type				u;
}						t_flags;

typedef struct			s_double
{
	char				sign;
	short				exp;
	long				mantis;
	int					log_10;
	int					len_entier;
	int					len_e;
}						t_double;

typedef struct			s_bigint
{
	char				nbr[MAXDIGIT];
	int					lastdig;
	char				sign;
}						t_bigint;

int						get_next_line(int fd, char **line);
int						ft_isalpha(int c);
size_t					ft_strlen(const char *str);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_atoi(const char *str);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strnstr(const char *big,
						const char *little, size_t len);
size_t					ft_strlcpy(char *dst, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
void					*ft_bzero(void *s, size_t n);
void					*ft_memccpy(void *dest, const void *src, int c,
						size_t n);
void					*ft_memset(void *s, int c, size_t n);
char					*ft_strncpy(char *dest, char *src, unsigned int n);
char					*ft_strdup(char *str);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
void					*ft_calloc(size_t nmemb, size_t size);
char					*ft_substr(char const *s, unsigned int start,
						size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					**ft_split(char const *s, char c);
void					ft_putstr_fd(char *s, int fd);
void					ft_putchar_fd(char c, int fd);
char					*ft_itoa(int n);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
char					*ft_strmapi(char const *s, char (*f)(unsigned int,
						char));
char					*ft_strtrim(char const *s1, char const *set);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_isascii(int c);
int						ft_isprint(int c);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **alst, t_list *new_list);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **alst, t_list *new_list);
void					ft_lstdelone(t_list *llst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
int						ft_lstsize(t_list *lst);
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
char					*ft_strcat(char *dest, char *src);
char					*ft_strcpy(char *dest, char *src);
char					*ft_strncpy(char *dest, char *src, unsigned int n);
char					*ft_ltoa(long int n);
char					*ft_ulltoa_base(unsigned long long int n,
		char *base);
int						ft_strcmp(char *s1, char *s2);

int						ft_printf(const char *s,
		...) __attribute__((format(printf,1,2)));
char					*ft_width(char *s, t_flags flags);
long long int			ft_atoll(const char *str);
int						ft_isprintconvert(char c);
int						ft_isprintflag(char c);
int						ft_shandle(t_flags flags, va_list params);
size_t					ft_lstrlen(const wchar_t *str);
wchar_t					*ft_lstrncpy(wchar_t *dest, wchar_t *src,
						unsigned int n);
wchar_t					*ft_lwidth(wchar_t *s, t_flags flags);
void					ft_nhandle(t_flags flags, va_list params, int res);
int						ft_chandle(t_flags flags, va_list params);
size_t					ft_unbrlen_base(unsigned long long n,
						unsigned int base_len);
char					*ft_ulltoa_basep(unsigned long long n, char *base,
						int i, int base_len);
char					*ft_sharp_flag(char *s, t_flags *flags);
int						ft_phandle(t_flags flags, va_list params);
int						ft_xhandle(t_flags flags, va_list params);
int						ft_nbrlen(long long n);
char					*ft_lltoa_absp(long long int n, int i);
char					*ft_positive_flag(char *s, t_flags *flags);
int						ft_dhandle(t_flags flgs, va_list params);
int						ft_fhandle(t_flags flags, va_list params);
char					*ft_dtoaf(t_double flt, t_flags *flags);
int						ft_printarg(t_flags flags, va_list params, int res);
int						ft_ghandle(t_flags flgs, va_list params);
char					*ft_dtoag(t_double flt, t_flags *flgs);

void					ft_lltobigint(long long n, t_bigint *b);
int						ft_bigintcomp(t_bigint *a, t_bigint *b);
void					ft_bigint_pow10(int pow, t_bigint *b);
void					ft_zero_adjust(t_bigint *b);
void					ft_divbigint(t_bigint *a, t_bigint *b, t_bigint *res);
void					ft_multbigint(t_bigint *a, t_bigint *b, t_bigint *res);
void					ft_dtobigint(t_bigint *res, t_double flt);
t_double				ft_initflt(double n);
int						ft_ceil(double f);
int						ft_floor(double f);
double					ft_pow(double nb, int p);
void					ft_addbigint(t_bigint *a, t_bigint *b, t_bigint *res);
double					ft_fabs(double nb);

#endif
