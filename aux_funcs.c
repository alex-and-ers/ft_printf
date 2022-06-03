/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 16:05:48 by sebonie           #+#    #+#             */
/*   Updated: 2021/11/25 14:18:23 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void	ft_unsigned_putnbr_fd(unsigned int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

char	*aux_base(unsigned long xX, const char *base)
{
	int				base_len;
	int				len;
	unsigned long	temp;
	char			*xX_base;

	base_len = ft_strlen(base);
	len = 0;
	temp = xX;
	if (xX == 0)
		len = 1;
	while (temp)
	{
		temp /= base_len;
		len++;
	}
	xX_base = malloc(sizeof(xX_base) * (len + 1));
	if (!xX_base)
		return (NULL);
	xX_base[len] = '\0';
	while (len--)
	{
		xX_base[len] = base[xX % base_len];
		xX /= base_len;
	}
	return (xX_base);
}
