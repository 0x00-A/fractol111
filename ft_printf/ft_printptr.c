/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:37:23 by aigounad          #+#    #+#             */
/*   Updated: 2022/11/05 02:37:26 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printaddress(size_t n, char *base)
{
	int				len;

	len = 0;
	if (n < 16)
		len += ft_printchar(base[n]);
	else
	{
		len += ft_printaddress((n / 16), base);
		len += ft_printchar(base[n % 16]);
	}
	return (len);
}

int	ft_printptr(void *p)
{
	int	len;

	len = 0;
	len += ft_printstr("0x");
	len += ft_printaddress((size_t)p, "0123456789abcdef");
	return (len);
}
