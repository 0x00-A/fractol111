/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:31:27 by aigounad          #+#    #+#             */
/*   Updated: 2022/11/05 02:31:29 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int nbr)
{
	int	len;

	len = 0;
	if (nbr < 10)
		len += ft_printchar(nbr + '0');
	else
	{
		len += ft_printnbr(nbr / 10);
		len += ft_printchar((nbr % 10) + '0');
	}
	return (len);
}
