/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:45:38 by sebonie           #+#    #+#             */
/*   Updated: 2021/11/25 14:18:49 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	type_proc(va_list *ap, char type)
{
	if (type == 'c')
	{
		ft_putchar_fd(va_arg(*ap, int), 1);
		return (-1);
	}
	else if (type == 's')
		return (write_s(va_arg(*ap, char *)));
	else if (type == 'p')
		return (write_p(va_arg(*ap, unsigned long)));
	else if (type == 'i' || type == 'd')
		return (write_di(va_arg(*ap, int)));
	else if (type == 'u')
		return (write_u(va_arg(*ap, unsigned int)));
	else if (type == 'x')
		return (write_xX(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (write_xX(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (type == '%')
	{
		ft_putchar_fd('%', 1);
		return (-1);
	}
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		len;
	int		i;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && (str[i + 1] == '\0'))
			break ;
		if (str[i] == '%')
		{
			len += type_proc(&ap, str[i + 1]);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(ap);
	return (len + i);
}
