/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:48:49 by emoman            #+#    #+#             */
/*   Updated: 2025/07/04 10:09:44 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	handle_chr(va_list *args)
{
	char	c;

	c = va_arg(*args, int);
	return (print_char(c));
}

int	handle_ptc(va_list *args)
{
	(void)args;
	return (print_char('%'));
}
