/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:33:59 by shhuang           #+#    #+#             */
/*   Updated: 2022/11/25 02:58:15 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	find(const char *s1, const char *set, size_t start)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0' && *s1)
	{
		if (!(set[i] == s1[start]))
			i++;
		else if (set[i] == s1[start++])
			i = 0;
	}
	return (start);
}

size_t	findend(const char *s1, const char *set, size_t end)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0' && *s1)
	{
		if (!(set[i] == s1[end]))
			i++;
		else if (set[i] == s1[end--])
			i = 0;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	end = ft_strlen(s1) - 1;
	start = find(s1, set, start);
	end = findend(s1, set, end);
	result = (char *)malloc(sizeof(*s1) * (end - start + 2));
	i = 0;
	while (start <= end)
	{
		result[i] = s1[start++];
		i++;
	}
	if (!result)
		return (NULL);
	result[i] = '\0';
	return (result);
}
