/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:17 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:08:25 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_mantissa_init(int *i)
{
	char	*res;

	res = ft_strdup("1");
	*i = 1;
	return (res);
}

char		*ft_exposant(int a, int n)
{
	char	*y;
	char	*x;
	int		n2;

	x = ft_itoa(a);
	y = (n % 2) ? x : "1";
	n2 = n / 2;
	while (n2)
	{
		x = ft_strmulti(x, x);
		if (n2 % 2)
			y = (ft_strcmp(y, "1") == 0) ? x : ft_strmulti(y, x);
		n2 /= 2;
	}
	return (y);
}

char		*ft_mantissa(long bin_mant, short flag, int bias)
{
	char			*res_mant;
	int				i;
	int				i_max;
	long			m;

	m = bias == 1023 ? 2251799813685248 : 4611686018427387904;
	i_max = bias == 1023 ? 52 : 63;
	res_mant = ft_mantissa_init(&i);
	while ((i++ <= i_max && bin_mant))
	{
		res_mant = ft_strmulti(res_mant, "10");
		if (bin_mant & m)
		{
			res_mant = ft_stradd(res_mant, ft_exposant(5, i - 1));
			bin_mant -= m;
		}
		m /= 2;
	}
	if (!flag)
	{
		res_mant[0] = '0';
		while (*res_mant == '0')
			res_mant++;
	}
	return (res_mant);
}
