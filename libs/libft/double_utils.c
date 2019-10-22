/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:08:50 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:09:00 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_strmulti1(char *num1, char *num2, int *k)
{
	int		len[2];
	int		*prod;
	int		i;
	int		j;

	len[0] = ft_strlen(num1);
	len[1] = ft_strlen(num2);
	prod = (int *)ft_strnew((len[0] + len[1] + 1) * sizeof(int));
	*k = 0;
	i = len[0];
	while (--i >= 0)
	{
		(*k) = len[0] - 1 - i;
		j = len[1];
		while (--j >= 0)
			prod[(*k)++] += (num1[i] - '0') * (num2[j] - '0');
	}
	(*k)++;
	return (prod);
}

char		*ft_strmulti(char *num1, char *num2)
{
	int		c;
	int		i;
	int		k;
	int		*prod;

	if (num1 == NULL || num2 == NULL)
		return (NULL);
	i = -1;
	prod = ft_strmulti1(num1, num2, &k);
	while (++i < k - 1)
	{
		c = prod[i] / 10;
		prod[i] = prod[i] % 10;
		prod[i + 1] += c;
	}
	while (k > 1 && prod[k - 1] == 0)
		k--;
	num1 = ft_strnew((k + 1));
	i = -1;
	while (++i < k)
		num1[i] = prod[k - 1 - i] + '0';
	num1[k] = '\0';
	free(prod);
	return (num1);
}

char		*ft_stradd(char *nbr1, char *nbr2)
{
	t_sum	a;
	char	*res;

	a.sm = 0;
	a.i = ft_strlen(nbr1);
	a.j = ft_strlen(nbr2) - 1;
	res = ft_strnew(a.i);
	ft_memset(res, '0', a.i + 1);
	while (--a.i >= 0)
	{
		if (a.j >= 0)
			a.sm = I(nbr1[a.i]) + I(nbr2[a.j--]) + a.sm;
		else
			a.sm = I(nbr1[a.i]) + a.sm;
		res[a.i + 1] = C(a.sm);
		a.sm /= 10;
	}
	res[a.i + 1] = C(a.sm);
	a.i = ft_strlen(nbr1);
	if (res[0] == '0')
	{
		ft_memmove(res, res + 1, a.i);
		res[a.i] = '\0';
	}
	return (res);
}
