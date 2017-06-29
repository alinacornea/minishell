/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcornea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 23:49:14 by alcornea          #+#    #+#             */
/*   Updated: 2017/01/11 16:48:26 by alcornea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>
# include <sys/types.h>

# define SPECIFIERS  "sSpdDioOuUxXcCfF"
# define FLAGS "#0-+ jzhl123456789.*"

long long		g_nb;

typedef struct	s_arg
{
	int			precision;
	int			width;
	int			flag_space;
	int			flag_zero;
	int			flag_minus;
	int			flag_plus;
	int			flag_hash;
	int			len_hh;
	int			len_h;
	int			len_l;
	int			len_ll;
	int			len_j;
	int			len_z;
	int			hex;
}				t_arg;

int				ft_printf(const char *format, ...);
int				my_strlen(const char *str);
char			*ft_ftoa(double val, int precision);
char			*ft_itoa_base(int value, int base);
char			*ft_itoa_hex_base(int value, int base);
void			choose_conversion(char *get, va_list arg, int len, int *value);
void			initialize_modifiers(t_arg *mod);
void			check_flags(t_arg *mod, char *get, va_list arg);
int				check_valid(const char *str);
void			check_length_modifiers(t_arg *mod, char *get);
void			invalid_conversion_type(int *value, char *get, t_arg mod);
void			handle_percent(int *value, t_arg mod);
void			handle_integers(va_list arg, int *value, char *get, t_arg mod);
void			convert_integers(va_list arg, int *value, char *get, t_arg mod);
char			*handle_int_precision(char *str, t_arg mod);
char			*handle_int_width(char *str, t_arg mod);
void			handle_all_flags(int *value, char **str, t_arg mod);
void			long_length_d(va_list arg, int *value, char *get, t_arg mod);

char			*convert_int_to_ascii(int num, int base);
char			*convert_long_long_to_ascii(long long num, int base);
char			*convert_long_to_ascii(long num, int base);
char			*convert_short_to_ascii(short num, int base);
char			*convert_u_to_ascii(unsigned int num, int base);
char			*convert_size_t_to_ascii(size_t num, int base);
char			*convert_int_ssize_t_to_ascii(ssize_t num, int base);
char			*convert_lu_to_ascii(unsigned long num, int base);
char			*convert_ushort_to_ascii(unsigned short num, int base);
char			*convert_llu_to_ascii(unsigned long long num, int base);
char			*convert_uintmax_t_to_ascii(uintmax_t num, int base);
char			*convert_upperhex_to_ascii(uintmax_t num, int base);

void			handle_uns_int(va_list arg, int *value, char *get, t_arg mod);
void			unsigned_l_len(va_list arg, int *value, char *get, t_arg mod);
void			handle_hex(va_list arg, int *value, char *get, t_arg mod);
void			handle_octal(va_list arg, int *value, char *get, t_arg mod);
void			octal_long_len(va_list arg, int *value, char *get, t_arg mod);
void			handle_pointers(va_list arg, int *value, char *get, t_arg mod);
void			handle_chars(va_list arg, int *value, t_arg mod);
void			handle_ls_string(va_list arg, int *value, char *get, t_arg mod);
void			handle_lc_char(va_list arg, int *value);

int				ft_wcharsize(wchar_t wc);
void			ft_putwchar(wchar_t wc);
void			function_hhu(va_list arg, int *value, char *get, t_arg mod);
void			handle_strings(va_list arg, int *value, char *get, t_arg mod);
void			handle_sign_char(va_list arg, int *value, char *get, t_arg mod);
void			unsign_char_len(va_list arg, int *value, char *get, t_arg mod);
void			hex_unchar_len(va_list arg, int *value, char *get, t_arg mod);
void			octal_unchar_len(va_list arg, int *value, char *get, t_arg mod);
void			handle_float(va_list arg, int *value, char *get, t_arg mod);
char			*ft_strjoinfree(char *s1, char *s2);

#endif
