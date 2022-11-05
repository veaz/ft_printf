/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaguilar <vaguilar@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:33:13 by vaguilar          #+#    #+#             */
/*   Updated: 2022/02/16 14:33:15 by vaguilar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	sum;
	int	x;

	x = 0;
	sum = 0;
	while (s[x] != '\0')
	{
		sum += ft_putchar(s[x]);
		x++;
	}
	return (sum);
}

int	ft_putnbr_base(int nbr, char *base, int use)
{
	unsigned int	size;
	unsigned int	nb;
	int				count;

	count = 0;
	size = ft_get_base(base);
	if (size == 0)
		return (0);
	if (nbr < 0 && use == 1)
	{
		count += ft_putchar('-');
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= size)
	{
		count += ft_putnbr_base(nb / size, base, use);
		count += ft_putchar(base[nb % size]);
	}
	else
		count += ft_putchar(base[nb % size]);
	return (count);
}

int	ft_putp(unsigned long long nbr, char *base)
{
	unsigned long long	size;
	unsigned long long	nb;
	int					count;

	count = 0;
	size = ft_get_base(base);
	if (size == 0)
		return (0);
	nb = nbr;
	if (nb >= size)
	{
		count += ft_putp(nb / size, base);
		count += ft_putchar(base[nb % size]);
	}
	else
		count += ft_putchar(base[nb % size]);
	return (count);
}

int	ft_get_base(char *base)
{
	int	x;
	int	j;

	x = 0;
	while (base[x] != '\0')
	{
		j = x + 1;
		if (base[x] == '+' || base[x] == '-')
			return (0);
		while (base[j] == '\0')
		{
			if (base[x] == base[j])
				return (0);
			j++;
		}
		x++;
	}
	if (x < 2)
		return (0);
	return (x);
}
