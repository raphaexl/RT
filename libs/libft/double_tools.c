/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:08:32 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:08:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lk(char *old, char *cpy)
{
	char *p;

	p = old;
	old = ft_strdup(cpy);
	free(p);
	return (old);
}

long	ft_intex(long bin_expo, int bias)
{
	int		i;
	long	m;
	long	int_expo;

	int_expo = 0;
	if (bias == 1023)
	{
		i = 12;
		m = 1024;
	}
	else
	{
		i = 16;
		m = 16384;
	}
	while (i--)
	{
		if (bin_expo & m)
			int_expo += m;
		bin_expo -= m;
		m /= 2;
	}
	return (int_expo);
}

long	ft_intma(long bin_mant, int bias)
{
	int		i;
	long	m;
	long	int_mant;

	int_mant = 0;
	if (bias == 1023)
	{
		i = 53;
		m = 2251799813685248;
	}
	else
	{
		i = 64;
		m = 4611686018427387904;
	}
	while (i--)
	{
		if (bin_mant & m)
			int_mant += m;
		bin_mant -= m;
		m /= 2;
	}
	return (int_mant);
}

size_t	ft_is_frac(char *str)
{
	while (*str)
	{
		if (*str == '.')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_get_exponent(long bin_expo, int bias)
{
	int int_expo;

	int_expo = ft_intex(bin_expo, bias);
	if (int_expo - bias > 0)
		return (ft_exposant(2, int_expo - bias));
	else if (int_expo - bias < 0)
	{
		if (int_expo - bias == -bias)
			return (ft_exposant(5, bias - 1));
		else
			return (ft_exposant(5, -(int_expo - bias)));
	}
	return (ft_strdup("1"));
}
