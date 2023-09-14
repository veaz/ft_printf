/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:18:14 by vaguilar          #+#    #+#             */
/*   Updated: 2023/09/14 20:46:51 by vaguilar         ###   ########.fr       */
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
