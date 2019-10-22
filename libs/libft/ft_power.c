/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:45:41 by ebatchas          #+#    #+#             */
/*   Updated: 2019/08/07 13:49:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_pow(double base, int n)
{
	double		res;

	res = 1.0;
	if (n == 0)
		return (1);
	if (n == 1)
		return (base);
	if (n < 0)
	{
		n = -n;
		base = 1.0 / base;
	}
	while (n)
	{
		if (n & 1)
			res *= base;
		n >>= 1;
		base *= base;
	}
	return (res);
}
