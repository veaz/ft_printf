/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:18:14 by vaguilar          #+#    #+#             */
/*   Updated: 2022/02/09 12:18:22 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (*(s + 1) == '%')
				count += ft_putchar('%');
			else
				count += ft_printargs(s, args);
			s = s + 2;
		}
		else
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	va_end(args);
	return (count);
}
int test;

test = 1000;
printf ("prueba = %i, %c\n", test, 't')

args == 48, 20, 50, 't'

va_arg(args, int) = 48

args == 20, 50, 't'

va_arg(args, int)
va_arg(args, int)
va_arg(args, char)
