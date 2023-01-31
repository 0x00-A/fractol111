/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aigounad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 02:30:14 by aigounad          #+#    #+#             */
/*   Updated: 2022/11/05 02:30:16 by aigounad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_printnbr(int nbr);
int	ft_printchar(char c);
int	ft_printhex(unsigned int nbr);
int	ft_printhex2(unsigned int nbr);
int	ft_printnbr_base(unsigned int nbr, char *base);
int	ft_printstr(char *s);
int	ft_printunsigned(unsigned int nbr);
int	ft_printptr(void *p);

#endif
