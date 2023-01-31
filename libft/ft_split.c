/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:53:54 by aigounad          #+#    #+#             */
/*   Updated: 2022/10/20 03:35:04 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c && flag == 0)
		{
			i++;
			flag = 1;
		}
		else if (*s == c && flag == 1)
		{
			flag = 0;
		}
		s++;
	}
	return (i);
}

static char	**ft_free_tab(char **pp, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(pp[i]);
		i++;
	}
	free(pp);
	return (NULL);
}

static int	ft_count_char(char const *s, int i, char c)
{
	int	len;

	len = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**pp;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	pp = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!pp)
		return (NULL);
	while (j < ft_count_word(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		pp[j] = ft_substr(s, i, ft_count_char(s, i, c));
		if (!pp[j])
			return (ft_free_tab(pp, j));
		i += ft_count_char(s, i, c);
		j++;
	}
	pp[j] = 0;
	return (pp);
}
