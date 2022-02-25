/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:19:03 by vaguilar          #+#    #+#             */
/*   Updated: 2022/02/09 12:19:05 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_putchar(char c);

int			ft_putstr(char *s);

int			ft_get_base(char *base);

int			ft_print_p(unsigned long long temp);

int			ft_print_s(char *str);

int			ft_putnbr_base(int nbr, char *base, int use);

int			ft_putp(unsigned long long nbr, char *base);

int			ft_printargs(const char *s, va_list args);

int			ft_printf(const char *s, ...);

#endif