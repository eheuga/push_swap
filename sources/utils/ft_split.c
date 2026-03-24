/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emheuga <emheuga@student.42angouleme.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 13:46:38 by emheuga           #+#    #+#             */
/*   Updated: 2026/03/24 16:05:38 by emheuga          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split_args(char *str)
{
	int		i;
	int		j;
	int		count;
	char	**result;
	int		start;
	int		k;

	i = 0;
	j = 0;
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
	result = malloc(sizeof(char *) * (count + 2));
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
		result[j] = malloc(sizeof(char) * (i - start + 1));
		k = 0;
		while (start < i)
			result[j][k++] = str[start++];
		result[j][k] = '\0';
		j++;
	}
	result[j] = NULL;
	return (result);
}
