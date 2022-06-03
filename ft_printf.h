/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 13:45:29 by sebonie           #+#    #+#             */
/*   Updated: 2021/11/25 14:19:51 by sebonie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);

int		write_s(char *s);
int		write_di(int di);
int		write_u(unsigned int u);
int		write_xX(unsigned int xX, char *base);
int		write_p(unsigned long p);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_unsigned_putnbr_fd(unsigned int n, int fd);
char	*aux_base(unsigned long xX, const char *base);
size_t	ft_strlen(const char *s);

#endif