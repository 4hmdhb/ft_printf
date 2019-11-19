/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:30 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/11 13:33:36 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FIELDS int	prec; int width; char *zero; char *s;
# define FIELDS2 int i; int d; va_list arguments; t_params *element;
# define ALLSUMBL "cspdDiouUxXfZ%"
# define MINUS_H 1
# define PLUS_HH 1 << 1
# define SPACE_L 1 << 2
# define HASH_LL 1 << 3
# define ZERO_LB 1 << 4
# define SIZE_T 1 << 5
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef	struct		s_params
{
	int				flags;
	int				width;
	int				precision;
	int				length;
	char			specifier;
}					t_params;

typedef	int			t_specifiers(t_params *element, va_list arguments);

void				handle_flags(t_params *element, char *format);
void				handle_length(t_params *element, char *format);
void				handle_width(t_params *element, char *format);
void				handle_precision(t_params *element, char *format);
void				handle_specifier(t_params *element, char *format);
void				create_list(t_params **begin_list, char *format);

t_params			*create_elem(char *format, int *i);
int					ft_printf(const char *format, ...);
int					di_specifier(t_params *element, int64_t n);
int					uoxx_specifier(t_params *element, uint64_t digit);
int					uoxx_cast(t_params *element, va_list arguments);
int					di_cast(t_params *element, va_list arguments);
int					c_specifier(t_params *element, va_list arguments);
int					s_specifier(t_params *element, va_list arguments);
int					p_specifier(t_params *element, va_list arguments);
int					f_specifier(t_params *element, va_list arguments);
int					percent_specifier(t_params *element);

int					width_apply(char *s, int width, char *c);
char				*hash_apply(t_params *element, char *s);
int					print_apply(char *s);
char				*space_apply(int sign, int space, char *s);
#endif
