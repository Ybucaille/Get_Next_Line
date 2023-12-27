/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybucaill <ybucaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:37:17 by ybucaill          #+#    #+#             */
/*   Updated: 2023/12/20 19:37:17 by ybucaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int		length;
	char	c;

	length = 0;
	if (format == 'c')
	{
		c = (char)va_arg(args, int);
		write(1, &c, 1);
		length++;
	}
	else if (format == 's')
		length += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (format == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += ft_print_hexa(va_arg(args, unsigned int), format);
	else if (format == '%')
		length = ft_print_percent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_format(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}
