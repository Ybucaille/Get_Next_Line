/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybucaill <ybucaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:05:11 by ybucaill          #+#    #+#             */
/*   Updated: 2023/12/21 08:07:24 by ybucaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_put_ptr(unsigned long long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_put_ptr(n / 16);
		ft_putchar(base[n % 16]);
	}
	else if (n == 0)
		ft_putchar('0');
	else
		ft_putchar(base[n]);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	if (ptr == 0)
		length += write(1, "(nil)", 5);
	else
	{
		length += write(1, "0x", 2);
		ft_put_ptr(ptr);
		length += ft_ptr_len(ptr);
	}
	return (length);
}
