/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 19:28:10 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/01/08 17:49:03 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse(va_list ap, t_flags *fmtg)
{
	int count;

	count = 0;
	while (*(fmtg->format))
	{
		if (*(fmtg->format) == '%')
		{
			bzerostruct(fmtg);
			fmtg->format++;
			if (strchr(TYPES, *(fmtg->format)))
				count += handle_type(ap, fmtg);
			else if (strchr(FORMATS, *(fmtg->format)))
				count += handle_flags(ap, fmtg);
		}
		else
			count += write(1, fmtg->format, 1);
		fmtg->format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		write_count;
	va_list ap;
	t_flags *fmtg;

	if (!format)
		return (-1);
	else if (format[0] == '\0')
		return (0);
	write_count = 0;
	va_start(ap, format);
	fmtg = malloc(sizeof(t_flags));
	if (!fmtg)
		return (-1);
	bzerostruct(fmtg);
	fmtg->format = (char*)format;
	write_count = parse(ap, fmtg);
	va_end(ap);
	free(fmtg);
	return (write_count);
}
