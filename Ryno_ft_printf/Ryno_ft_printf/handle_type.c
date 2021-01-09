/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_type.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 19:58:08 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/01/08 17:56:59 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_string(char *str, t_flags *fmtg)
{
	int len;
	int ret;

	if (!str)
		return (print_string("(null)", fmtg));
	len = ft_strlen(str);
	if (fmtg->is_precision && fmtg->prec_len <= len && fmtg->type == 's')
		len = fmtg->prec_len;
	ret = 0;
	if (fmtg->is_minus)
		write(1, str, len);
	write_width_zero_space(fmtg, len);
	if (len < fmtg->width)
		ret += len + (fmtg->width - len);
	else
		ret += len;
	if (!fmtg->is_minus)
		write(1, str, len);
	return (ret);
}

int	handle_type(va_list ap, t_flags *fmtg)
{
	char	*frmt;
	int		count;

	frmt = fmtg->format;
	count = 0;
	if (*frmt == '%')
		count += write(1, "%", 1);
	else if (*frmt == 'c')
		count += print_char(va_arg(ap, int), fmtg);
	else if (*frmt == 's')
		count += print_string(va_arg(ap, char*), fmtg);
	else if (*frmt == 'd' || *frmt == 'i')
		count += print_num(va_arg(ap, int), fmtg);
	else if (*frmt == 'p')
		count += print_address(va_arg(ap, void *), fmtg);
	else if (*frmt == 'x' || *frmt == 'X')
		count += print_hexa(va_arg(ap, unsigned long long), fmtg, *frmt);
	else if (*frmt == 'u')
		count += print_unsigned(va_arg(ap, unsigned int), fmtg);
	return (count);
}
