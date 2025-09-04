/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:04:26 by emoman            #+#    #+#             */
/*   Updated: 2025/07/04 10:09:24 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_formatter(char c, va_list *var)
{
	int							i;
	static const t_formatter	formatters[] = {
	{'c', handle_chr},
	{'%', handle_ptc},
	{'s', handle_str},
	{'d', handle_int},
	{'i', handle_int},
	{'u', handle_uint},
	{'f', handle_float},
	{'p', handle_vptr},
	{'x', handle_hexl},
	{'X', handle_hexu},
	{0, NULL},
	};

	i = 0;
	while (formatters[i].handler)
	{
		if (formatters[i].specifier == c)
			return (formatters[i].handler(var));
		i++;
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	var;

	va_start(var, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += handle_formatter(*str, &var);
		}
		else
			count += print_char(*str);
		str++;
	}
	va_end(var);
	return (count);
}
