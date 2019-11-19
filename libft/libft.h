/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basylbek <basylbek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:56:53 by basylbek          #+#    #+#             */
/*   Updated: 2019/11/11 14:22:14 by basylbek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 5

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

intmax_t			ft_atoi(const char *str);
int					ft_isspace(int c);
char				*ft_strncpy(char *dst, const char *src, size_t len);
void				ft_putstr(char const *s);
void				ft_putnbr(int64_t nb);
void				ft_putnbr_u(uint64_t nb);
void				ft_putchar(char c);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strnew(size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_toupper(char *s);
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
int					ft_numlen(uint64_t n, int base);
char				*ft_itoa(uint64_t num, int base);
char				*add_space(char *s, int prec, char *c);
char				*ft_itoa_float(long double n, int prec);
char				*ft_itoa_precision(int64_t n, int pres, char *c,
		int base);
char				*ft_itoa_precision_u(uint64_t n, int pres, char *c,
		int base);
uint64_t			ft_pow(int64_t n, int base);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_fr1(char *s1, char *s2);
char				*ft_strjoin_fr2(char *s1, char *s2);
char				*ft_strjoin_fr(char *s1, char *s2);

#endif
