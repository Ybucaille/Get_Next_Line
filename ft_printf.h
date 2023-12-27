/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybucaill <ybucaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:36:58 by ybucaill          #+#    #+#             */
/*   Updated: 2023/12/20 19:36:58 by ybucaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char		*ft_uitoa(unsigned int n);
int			ft_putnbr(int nb);
int			ft_int_len(int n);
int			ft_print_str(char *s);
int			ft_print_percent(void);
int			ft_printf(const char *str, ...);
int			ft_ptr_len(unsigned long long n);
int			ft_print_unsigned(unsigned int n);
int			ft_unsigned_int_len(unsigned int n);
int			ft_print_ptr(unsigned long long ptr);
int			ft_format(va_list args, const char format);
int			ft_print_hexa(unsigned int n, const char format);
void		ft_putstr(char *str);
void		ft_putchar(char c);
void		ft_put_ptr(unsigned long long n);
void		ft_put_hexa(unsigned int n, const char format);

#endif