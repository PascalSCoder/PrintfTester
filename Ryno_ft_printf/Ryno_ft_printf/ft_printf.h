/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 19:31:32 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/01/08 17:19:14 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define TYPES "csdixXpu%"
# define FORMATS "0123456789.-*"
# define ALL_FLAGS "0123456789.-*csdixXpu%"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


typedef struct 	s_printf_flags
{
	char 	*format;
	int		write_count;
	
	int		is_minus; // '-'
	int 	is_zero; // '0'
	int 	width; // 0 - 9
	
	int 	is_precision; // '.'
	int 	prec_len; // '.#'

	int		is_neg;

	char	type;
}				t_flags;

int		ft_printf(const char *format, ...);
void	write_width_zero_space(t_flags *fmtg, int len);
int 	handle_type(va_list ap, t_flags *flags);
int 	handle_flags(va_list ap, t_flags *flags);
void 	bzerostruct(t_flags *list);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	ft_bzero(void *str, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char 	*num_converter(long long nbr, int base, char c);
int		write_zero(int len);
int		write_space(int len);
char	*ft_strdup(const char *s1);
int		print_num(int num, t_flags *fmtg);
int		print_char(int c, t_flags *fmtg);
int		print_address(void *ptr, t_flags *fmtg);
int		print_hexa(long long num, t_flags *fmtg, char c);
int		print_unsigned(unsigned int num, t_flags *fmtg);
int		print_string(char *str, t_flags *fmtg);
int 	nbr_right_align(char *str, t_flags *fmtg);
int 	nbr_left_align(char *str, t_flags *fmtg);
int		handle_num(char *str, t_flags *fmtg);

#endif