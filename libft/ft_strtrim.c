/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:14:05 by emoman            #+#    #+#             */
/*   Updated: 2025/06/17 14:10:51 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	lenstr;
	size_t	i;
	size_t	j;
	char	*trim;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	lenstr = ft_strlen(s1);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
		i++;
	j = 0;
	while (lenstr > j && ft_strchr(set, s1[lenstr - j - 1]))
		j++;
	trim = ft_substr(s1, i, lenstr - i - j);
	return (trim);
}
