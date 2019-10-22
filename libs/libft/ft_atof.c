/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 13:38:05 by ebatchas          #+#    #+#             */
/*   Updated: 2019/08/07 14:39:47 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'\
			|| c == '\r' || c == '\f' || c == '\v');
}

float			ft_atof(const char *str)
{
	const char		*p;
	float			number;
	int				i;

	while (ft_isspace(*str))
		str++;
	p = str;
	if (*str == '+' || *str == '-')
		p++;
	number = 0.0;
	while (*p && *p <= '9' && *p >= '0')
	{
		number += *p - '0';
		if (*(p + 1) <= '9' && *(p + 1) >= '0')
			number *= 10.0;
		p++;
	}
	if (*p++ == '.')
	{
		i = 0;
		while (*p && *p <= '9' && *p >= '0' && ++i)
			number += ((float)(*p++ - '0') / ft_pow(10, i));
	}
	return ((*str == '-') ? (-number) : (number));
}
