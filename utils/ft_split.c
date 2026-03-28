/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/28 16:38:30 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

static char	*extract_word(char *str, int start, int end)
{
	char	*word;
	int		k;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	k = 0;
	while (start < end)
		word[k++] = str[start++];
	word[k] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	result = malloc(sizeof(char *) * (count_words(str) + 2));
	if (!result)
		return (NULL);
	result[0] = NULL;
	i = 0;
	j = 1;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && str[i] != ' ')
			i++;
		result[j++] = extract_word(str, start, i);
	}
	result[j] = NULL;
	return (result);
}
