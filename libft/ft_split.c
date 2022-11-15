/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabel <aabel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:24:40 by aabel             #+#    #+#             */
/*   Updated: 2022/11/15 18:33:10 by aabel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **pointer)
{
	int	i;

	i = 0;
	if (!pointer)
		return (NULL);
	while (pointer[i])
	{
		free(pointer[i]);
		i++;
	}
	free(pointer);
	return (NULL);
}

static size_t	ft_sizetab(char *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	if (!s || !s[i])
		return (word);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			word++;
			while ((s[i] && s[i] == c))
				i++;
		}
		else
			i++;
	}
	if (i - 1 >= 0 && s[i - 1] != c)
	word++;
	return (word);
}

static char	*ft_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		index;
	size_t	i;
	size_t	j;

	j = 0;
	index = -1;
	i = -1;
	tab = malloc(sizeof(char *) * (ft_sizetab((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			tab[j++] = ft_word(s, index, i);
			if (!tab[j - 1])
				return (ft_free(tab));
			index = -1;
		}
	}
	tab[j] = 0;
	return (tab);
}
