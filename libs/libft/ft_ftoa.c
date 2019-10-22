/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:39:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/08/07 14:40:40 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoaf(long double nb, int precision)
{
	int				n;
	int				i;
	char			*temp;

	i = 0;
	n = nb;
	temp = ft_strdup(ft_itoa(n));
	nb = nb > 0 ? nb - n : -(nb - n);
	temp = ft_strjoin(temp, ".");
	while (nb < 0.1 && nb > -0.1 && i < precision - 1)
	{
		nb *= 10;
		i++;
	}
	n = nb * ft_pow(10, precision - i);
	n = (nb * ft_pow(10, precision - i) - n > 0.01) ? n + 1 : n;
	temp = ft_strjoin(temp, ft_itoa(n));
	return (temp);
}
