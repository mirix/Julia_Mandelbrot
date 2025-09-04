/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:40:19 by emoman            #+#    #+#             */
/*   Updated: 2025/07/04 10:29:43 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

// Structures
typedef struct formatter
{
	char	specifier;
	int		(*handler)(va_list *);
}	t_formatter;

// Function declarations
int	ft_printf(const char *str, ...);
int	handle_formatter(char c, va_list *var);
int	print_char(char c);
int	handle_chr(va_list *args);
int	handle_ptc(va_list *args);
int	print_str(const char *s);
int	handle_str(va_list *args);
int	print_nbr(int n);
int	print_unbr(unsigned int n);
int	handle_int(va_list *args);
int	handle_uint(va_list *args);
int	hex_buffer(unsigned long long addr, char *buffer, int i, char format);
int	print_hex(unsigned long long addr, char format);
int	handle_hexl(va_list *args);
int	handle_hexu(va_list *args);
int	print_vptr(unsigned long long addr);
int	handle_vptr(va_list *args);
int	print_float(double n);
int	handle_float(va_list *args);

#endif
