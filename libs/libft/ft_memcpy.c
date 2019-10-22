/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:33:13 by ebatchas          #+#    #+#             */
/*   Updated: 2019/08/07 12:41:49 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*p;
	char	*q;

	q = (char *)src;
	p = (char *)dest;
	i = 0;
	while (i < n)
	{
		*p = *q;
		p++;
		q++;
		i++;
	}
	return (dest);
}
