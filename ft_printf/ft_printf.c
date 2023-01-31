/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <aigounad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:29:56 by aigounad          #+#    #+#             */
/*   Updated: 2023/01/27 04:21:26 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpercent(void)
{
	return (write(1, "%%", 1));
}

int	ft_select(va_list ap, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_printchar(va_arg(ap, int));
	else if (c == 'd' || c == 'i')
		len += ft_printnbr(va_arg(ap, int));
	else if (c == 's')
		len += ft_printstr(va_arg(ap, char *));
	else if (c == 'p')
		len += ft_printptr(va_arg(ap, void *));
	else if (c == 'u')
		len += ft_printunsigned(va_arg(ap, unsigned int));
	else if (c == 'x')
		len += ft_printhex(va_arg(ap, unsigned int));
	else if (c == 'X')
		len += ft_printhex2(va_arg(ap, unsigned int));
	else if (c == '%')
		len += ft_printpercent();
	return (len);
}

int	ft_isfp(char c)
{
	if (c == 'd' || c == 'i' || c == 'u' || c == 'x' || \
		c == 'X' || c == 'p' || c == '%' || c == 's' || c == 'c')
		return (1);
	return (0);
}

int	ft_printf(const char	*s, ...)
{
	va_list	ap;
	int		len;

	len = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && ft_isfp(*(s + 1)))
		{
			len += ft_select(ap, *(s + 1));
			s += 2;
		}
		else if (*s == '%')
			s++;
		else
		{
			len += ft_printchar(*s);
			s++;
		}
	}	
	va_end(ap);
	return (len);
}
