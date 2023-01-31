/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:31:09 by aigounad          #+#    #+#             */
/*   Updated: 2022/11/05 02:31:11 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr_base(unsigned int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr >= 16)
	{
		len += ft_printnbr_base((nbr / 16), base);
		len += ft_printnbr_base((nbr % 16), base);
	}
	else
		len += ft_printchar(base[nbr]);
	return (len);
}
