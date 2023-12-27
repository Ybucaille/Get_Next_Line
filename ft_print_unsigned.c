/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybucaill <ybucaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 07:04:36 by ybucaill          #+#    #+#             */
/*   Updated: 2023/12/21 07:04:36 by ybucaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_int_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*nb;

	len = ft_unsigned_int_len(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	nb[len] = '\0';
	while (n != 0)
	{
		nb[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (nb);
}

int	ft_print_unsigned(unsigned int n)
{
	int		length;
	char	*nb;

	length = 0;
	if (n == 0)
		length += write(1, "0", 1);
	else
	{
		nb = ft_uitoa(n);
		length += ft_print_str(nb);
		free(nb);
	}
	return (length);
}
