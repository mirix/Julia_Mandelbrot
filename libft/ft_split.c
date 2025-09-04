/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoman <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 14:34:22 by emoman            #+#    #+#             */
/*   Updated: 2025/06/17 17:51:37 by emoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	free_words(char **words, size_t i)
{
	while (i--)
		free(words[i]);
	free(words);
}

static inline size_t	skip_delimiters(char const *s, size_t i, char c)
{
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static inline unsigned int	word_count(char const *s, char c)
{
	size_t	i;
	size_t	w;

	if (!c)
		return (1);
	w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (w);
}

static inline char	*add_word(char const *s, char c)
{
	char	*word;
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	ft_strlcpy(word, s, i + 1);
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	words = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	j = 0;
	while (1)
	{
		i = skip_delimiters(s, i, c);
		if (!s[i])
			break ;
		words[j] = add_word(&s[i], c);
		if (!words[j++])
			return (free_words(words, j), NULL);
		while (s[i] && s[i] != c)
			i++;
	}
	words[j] = NULL;
	return (words);
}
