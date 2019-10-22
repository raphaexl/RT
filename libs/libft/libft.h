/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 01:15:41 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 12:43:40 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# define ABS(n) ((n) < (0) ? (-n) : (n))
# define U_MAX 2147483647
# define N_MAX 99
# define I(nbr)  (nbr - '0')
# define C(nbr) (nbr % 10) + '0'
# define VECTOR_INIT_CAPACITY 4
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>
# include <wchar.h>
# include "structs.h"
# include "color.h"

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alast, t_list *ne);
void				ft_lstadd2(t_list **alast, t_list *ne);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstreverse(t_list **lst);
void				ft_lstswap(t_list **lst1, t_list **lst2);
int					ft_lstlen(t_list *lst);
t_list				*ft_lstdup(t_list *src);
t_list				*ft_lstjoin(t_list *lst1, t_list *lst2);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_strns(char const *s, char c);
char				*ft_strnew(size_t size);
char				*ft_newstr(char c, int size);
void				ft_strdel(char **as);
char				*ft_strupr(const char *str);
char				*ft_strlwr(const char *str);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int i, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_ftoa(float n);
int					ft_putchar(int c);
void				ft_putstr(char const *str);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

double				ft_pow(double base, int n);

int					ft_atoi(const char *str);
float				ft_atof(const char *str);
void				ft_bzero(void *s, size_t n);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(const void *tampon, int c, size_t n);

char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strdup(const char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);
char				*ft_strstr(const char *str, const char *find);
char				*ft_strnstr(const char *str, const char *find, size_t n);
char				*ft_strrchr(const char *str, int c);

int					ft_get_next_line(const int fd, char **line);
int					ft_new_line(t_list **lst, char **line);
int					ft_fill_list(t_list **lst, char **line, int *ret);
int					ft_find_fd(t_list *lst, const int fd);
char				*ft_process_str(char *str, int *ret);

int					ft_size_base(long long n, int base);
char				*ft_strcapitalize(char *str);
char				*ft_itoa_base(long long n, int base);
int					ft_printf(const char *format, ...);

char				*ft_get_exponent(long bin_expo, int bias);
char				*ft_mantissa(long mantissa, short flag, int bias);
char				*ft_rmz(char *str, short flag);
long				ft_intex(long bin_expo, int bias);
long				ft_intma(long bin_mant, int bias);
char				*ft_mvfrc(char *str, int frac_len);
char				*ft_lk(char *str1, char *str2);
size_t				ft_is_frac(char *str);

char				*ft_pre_cal(t_double *d);
char				*ft_l_pre_cal(t_l_double *d);

char				*ft_strmulti(char *num1, char *num2);
char				*ft_exposant(int a, int n);
char				*ft_stradd(char *str1, char *str2);

char				*ft_strleftjoin(char *str, char *buffer, int width);
char				*ft_strrightjoin(char *str, char *buffer, int width);
char				*ft_handle_precision(char *buffer, int prec);

t_conv				*ft_new_conversion(char *str);
char				*ft_parse_conversion(char *str, t_conv *conv);
char				*ft_print_conversion(char *str, va_list ap);
void				ft_print_float_conv(t_conv *conv, va_list ap);
char				*ft_get_float_signed(t_conv *conv, va_list ap);
intmax_t			ft_get_conv_signed(t_conv *conv, va_list ap);
uintmax_t			ft_get_conv_unsigned(t_conv *conv, va_list ap);
void				ft_del_conversion(t_conv *conv);

void				ft_print_u(t_conv *conv, uintmax_t num);
void				ft_print_o(t_conv *conv, uintmax_t num);
void				ft_print_x(t_conv *conv, uintmax_t num);
void				ft_print_x_caps(t_conv *conv, uintmax_t num);
void				ft_print_wint(wint_t wint);
void				ft_print_wstr(t_conv *conv, wchar_t *wstr);
void				ft_print_wchar(t_conv *conv, wint_t wint);
void				ft_print_char(t_conv *conv, char c);
void				ft_print_str(t_conv *conv, char *str);
void				ft_print_spacing(int len, int min, char c);
void				ft_print_num_spaced(t_conv *conv, char *str);
int					ft_tally_get(int size, int add);
int					ft_tally_print(void *mem, int size);
void				ft_tally_str(char *str);
uintmax_t			ft_digitc(uintmax_t n);
int					ft_print_color(char *str);

void				ft_printf_error(char *str);

void				ft_vector_init(t_vector *vec, int size);
int					ft_vector_size(t_vector *vec);
void				ft_vector_push_back(t_vector *vec, void *value);
void				ft_vector_set(t_vector *vec, int id, void *value);
void				*ft_vector_get(t_vector	*vec, int id);
void				ft_vector_delete(t_vector *vec, void *value);
void				ft_vector_remove(t_vector *vec, int id);
void				ft_vector_free(t_vector *vec);

void				*ft_realloc(void *ptr, size_t prev_len, size_t next_len);

void				ft_split_free(char ***tab);
int					ft_split_len(char **tab);
#endif
