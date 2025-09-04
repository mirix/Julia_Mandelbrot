/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:15:27 by emoman            #+#    #+#             */
/*   Updated: 2025/06/24 10:28:47 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nl;
	char		c;

	nl = (long long)n;
	if (nl < 0)
	{
		write(fd, "-", 1);
		nl = -nl;
	}
	if (nl > 9)
		ft_putnbr_fd((int)(nl / 10), fd);
	c = (char)(nl % 10 + '0');
	write(fd, &c, 1);
}
