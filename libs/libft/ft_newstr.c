/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:50:28 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/13 18:55:15 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_newstr(char c, int size)
{
	char	*str;

	if ((str = (char *)malloc(size + 1)))
	{
		str[size] = '\0';
		while (--size >= 0)
			str[size] = c;
	}
	return (str);
}
