/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:27:27 by aigounad          #+#    #+#             */
/*   Updated: 2022/10/08 21:03:08 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;

	i = 0;
	if (src && !dstsize)
		return (ft_strlen(src));
	dstlen = ft_strlen(dst);
	if (dstlen >= dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[i] && i < (dstsize - dstlen - 1))
	{
		dst[i + dstlen] = src[i];
		i++;
	}
	dst[i + dstlen] = '\0';
	return (dstlen + ft_strlen(src));
}
// #include <stdio.h>
// #include <string.h>
// int	main()
// {
// 	char *s = "AAA";
// 	printf("ft_strlcat :: %zu\n", ft_strlcat(0, s, 0));	//srclen
// 	printf("ft_strlcat :: %zu\n", ft_strlcat(s, 0, 0));	//segf
// 	printf("ft_strlcat :: %zu\n", ft_strlcat(0, 0, 0));	//segf
// 	printf("ft_strlcat :: %zu\n", ft_strlcat(s, s, 0));	//srclen

// 	printf("ft_strlcat :: %zu\n", ft_strlcat(0, s, 1));	//segf
// 	printf("ft_strlcat :: %zu\n", ft_strlcat(s, 0, 1));	//segf
// 	printf("ft_strlcat :: %zu\n", ft_strlcat(0, 0, 1));	//segf
// 	printf("ft_strlcat :: %zu\n", ft_strlcat("A", s, 1));	//srclen + dstsize
// }
