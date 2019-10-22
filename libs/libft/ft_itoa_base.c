/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:22:45 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/19 10:09:12 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size_base(long long int n, int base)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		++i;
	}
	return (i);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] <= 'z' && str[i] >= 'a')
			str[i] = str[i] + 'A' - 'a';
	return (str);
}

char	*ft_itoa_base(long long int n, int base)
{
	char	*tab;
	int		len;

	len = ft_size_base(ABS(n), base);
	tab = (char *)malloc((len + 2) * sizeof(char));
	if ((n < 0) && (n = -n))
	{
		tab[0] = '-';
		tab[len + 1] = '\0';
	}
	else
	{
		tab[0] = '0';
		--len;
		tab[len--] = '\0';
	}
	while (n)
	{
		tab[len--] = n % base > 9 ? n % base - 10 + 'a' : n % base + '0';
		n /= base;
	}
	return (tab);
}
