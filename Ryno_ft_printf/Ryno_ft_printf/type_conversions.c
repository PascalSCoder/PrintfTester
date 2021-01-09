/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   type_conversions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/03 13:47:35 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/01/09 15:49:03 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(int num, t_flags *fmtg)
{
	char *str;
	int ret;
	long long nbr;

	ret = 0;
	nbr = num;
	if (nbr < 0 && (fmtg->is_zero || fmtg->is_precision))
	{
		fmtg->is_neg = 1;
		nbr *= -1;
		fmtg->width -= 1;
	}	
	str = num_converter(nbr, 10, 'x');
	if (fmtg->is_precision && fmtg->prec_len == 0 && num == 0)
		ret += print_string("", fmtg);
	else
		ret += handle_num(str, fmtg);
	return (ret);
}

int	print_char(int c, t_flags *fmtg)
{
	int	ret;

	ret = 0;
	if (fmtg->is_minus)
		ret += write(1, &c, 1);
	if (fmtg->width > 1 && !fmtg->is_zero)
		ret += write_space(fmtg->width - 1);
	if (!fmtg->is_minus)
		ret += write(1, &c, 1);
	return (ret);
}

int	print_address(void *ptr, t_flags *fmtg)
{
	unsigned long long	address;
	char				*pointer;

	if (ptr == NULL)
		return(print_string("0x", fmtg));
	address = (unsigned long long)ptr;
	pointer = num_converter(address, 16, 'x');
	pointer--;
	*pointer = 'x';
	pointer--;
	*pointer = '0';
	return (print_string(pointer, fmtg));
}

int	print_hexa(long long num, t_flags *fmtg, char c)
{
	int ret;
	char *str;

	ret = 0;
	str = num_converter(num, 16, c);
	if (fmtg->is_precision && fmtg->prec_len == 0 && num == 0)
		ret += print_string("", fmtg);
	else
		ret += print_string(str, fmtg);
	return (ret);
}

int	print_unsigned(unsigned int num, t_flags *fmtg)
{
	int		ret;
	char	*str;

	ret = 0;
	str = num_converter(num, 10, 'x');
	if (fmtg->is_precision && fmtg->prec_len == 0 && num == 0)
		ret += print_string("", fmtg);
	else
		ret += print_string(str, fmtg);
	return (ret);
}
