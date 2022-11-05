/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:20:30 by vaguilar          #+#    #+#             */
/*   Updated: 2022/02/09 12:20:32 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_p(unsigned long long temp)
{
	int	count;

	count = 2;
	write(1, "0x", count);
	count += ft_putp((unsigned long long)temp, "0123456789abcdef");
	return (count);
}

int	ft_print_s(char *str)
{
	if (str == NULL)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}

int	ft_printargs(const char *s, va_list args)
{
	if (*(s + 1) == '%')
		return (ft_putchar('%'));
	else if (*(s + 1) == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (*(s + 1) == 's')
		return (ft_print_s(va_arg(args, char *)));
	else if (*(s + 1) == 'p')
		return (ft_print_p(va_arg(args, unsigned long long)));
	else if (*(s + 1) == 'd' || *(s + 1) == 'i')
		return (ft_putnbr_base(va_arg(args, int), "0123456789", 1));
	else if (*(s + 1) == 'u')
		return (ft_putp(va_arg(args, unsigned int), "0123456789"));
	else if (*(s + 1) == 'x')
		return (ft_putnbr_base(va_arg(args, int), "0123456789abcdef", 0));
	else if (*(s + 1) == 'X')
		return (ft_putnbr_base(va_arg(args, int), "0123456789ABCDEF", 0));
	else
		return (ft_putchar(*(s + 1)));
	return (0);
}
