/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_num.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/08 15:19:41 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/01/09 15:16:09 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_right_align(char *str, t_flags *fmtg)
{
	int ret;
	int len;

	ret = 0;
	len = ft_strlen(str);
	if (fmtg->is_zero || fmtg->is_precision || fmtg->is_neg)
	{
		if (fmtg->is_neg)
			ret += write(1, "-", 1);
		if (fmtg->is_zero)
			ret += write_zero(fmtg->width - len);
		else if (fmtg->prec_len > len)
			ret += write_zero(fmtg->prec_len - len);
	}
	ret += write(1, str, len);
	if (fmtg->is_precision && fmtg->width && len < fmtg->prec_len)
		ret += write_space(fmtg->width - fmtg->prec_len);
	else
		ret += write_space(fmtg->width - len);
	return (ret);
}

int	nbr_left_align(char *str, t_flags *fmtg)
{
	int ret;
	int len;

	ret = 0;
	len = ft_strlen(str);
	if (fmtg->is_precision && fmtg->width && len < fmtg->prec_len)
		ret += write_space(fmtg->width - fmtg->prec_len);
	else if (fmtg->width && !fmtg->is_zero)
		ret += write_space(fmtg->width - len);
	if (fmtg->is_neg)
		ret += write(1, "-", 1);
	if (fmtg->is_zero && fmtg->width > len)
		ret += write_zero(fmtg->width - len);
	else if (fmtg->is_precision && fmtg->prec_len > len)
		ret += write_zero(fmtg->prec_len - len);
	ret += write(1, str, len);
	return (ret);
}

int	handle_num(char *str, t_flags *fmtg)
{
	int ret;
	int len;

	ret = 0;
	len = ft_strlen(str);
	if (fmtg->is_minus)
		ret += nbr_right_align(str, fmtg);
	else
		ret += nbr_left_align(str, fmtg);
	return (ret);
}
