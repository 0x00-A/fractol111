/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:30:55 by aigounad          #+#    #+#             */
/*   Updated: 2022/11/05 02:30:57 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr)
{
	unsigned int	n;
	int				len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_printchar('-');
		n = nbr * -1;
	}
	else
		n = nbr;
	if (n < 10)
		len += ft_printchar(n + '0');
	else
	{
		len += ft_printnbr(n / 10);
		len += ft_printchar((n % 10) + '0');
	}
	return (len);
}
