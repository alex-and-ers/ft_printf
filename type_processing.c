/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_processing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:59:13 by sebonie           #+#    #+#             */
/*   Updated: 2021/11/25 14:20:53 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_s(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (4);
	}
	ft_putstr_fd(s, 1);
	return (ft_strlen(s) - 2);
}

int	write_di(int di)
{
	int		len;

	len = -1;
	ft_putnbr_fd(di, 1);
	while (di <= -10 || di >= 10)
	{
		len++;
		di /= 10;
	}
	if (di < 0)
		len++;
	return (len);
}

int	write_u(unsigned int u)
{
	int		len;

	len = -1;
	ft_unsigned_putnbr_fd(u, 1);
	while (u >= 10)
	{
		len++;
		u /= 10;
	}
	if (u < 0)
		len++;
	return (len);
}

int	write_xX(unsigned int xX, char *base)
{
	int		len;
	char	*ch;

	ch = aux_base(xX, base);
	len = write(1, ch, ft_strlen(ch));
	free(ch);
	return (len - 2);
}

int	write_p(unsigned long p)
{
	int		len;
	char	*ch;

	ch = aux_base(p, "0123456789abcdef");
	len = write(1, "0x", 2);
	len += write(1, ch, ft_strlen(ch));
	free(ch);
	return (len - 2);
}
