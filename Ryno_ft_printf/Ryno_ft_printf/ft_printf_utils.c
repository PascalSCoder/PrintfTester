/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeiboom <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/28 19:31:12 by rmeiboom      #+#    #+#                 */
/*   Updated: 2021/01/08 17:26:26 by rmeiboom      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 		bzerostruct(t_flags *list)
{
	list->write_count = 0;
	list->is_minus = 0;
	list->is_zero = 0;
	list->is_precision = 0;
	list->width = 0;
	list->prec_len = 0;
	list->is_neg = 0;
}

void		write_width_zero_space(t_flags *fmtg, int len)
{
	if (len < fmtg->width)
	{
		if (fmtg->is_zero)
			write_zero(fmtg->width - len);
		else
			write_space(fmtg->width - len);
	}
}

int			ft_atoi(const char *str)
{
	int			i;
	int			negative;
	long int	digit;

	i = 0;
	digit = 0;
	negative = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		digit = (digit * 10) + (str[i] - '0');
		if ((digit * negative) < INT_MIN)
			return (0);
		else if ((digit * negative) > INT_MAX)
			return (-1);
		i++;
	}
	return (digit * negative);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

void	ft_bzero(void *str, size_t n)
{
	size_t	i;
	char	*string;

	i = 0;
	string = (char*)str;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*voidptr;
	size_t	true_size;

	true_size = count * size;
	voidptr = malloc(true_size);
	if (!voidptr)
		return (NULL);
	else
		ft_bzero(voidptr, true_size);
	return (voidptr);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, strlen(str));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	char		*substring;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char*)s;
	substring = (char*)ft_calloc((len + 1), sizeof(char));
	if (!substring)
		return (NULL);
	while (i < len && str[i] != '\0' && start < ft_strlen(s))
	{
		substring[i] = str[i + start];
		i++;
	}
	return (substring);
}

char *num_converter(long long nbr, int base, char c)
{
	static char upper_hexa_rep[] = "0123456789ABCDEF";
	static char lower_hexa_rep[] = "0123456789abcdef";
	static char buffer[25];
	long long n;
	char *ptr;
	bzero(buffer, 25);
	n = nbr;
	ptr = &buffer[24];
	*ptr = '\0';
	if (nbr == 0)
	{
		ptr--;
		*ptr = '0';
	}
	else if (nbr < 0)
		nbr *= -1;
	while (nbr != 0)
	{
		--ptr;
		if (c == 'X')
			*ptr = upper_hexa_rep[nbr%base];
		else
			*ptr = lower_hexa_rep[nbr%base];
		nbr /= base;
	}
	if (n < 0)
		*--ptr = '-';
	return (ptr);
}

int write_zero(int len)
{
	int ret;

	ret = 0;
	while (len > 0)
	{
		ret += write(1, "0", 1);
		len--;	
	}
	return (ret);
}

int write_space(int len)
{
	int ret;

	ret = 0;
	while (len > 0)
	{
		ret += write(1, " ", 1);
		len--;
	}
	return (ret);
}
