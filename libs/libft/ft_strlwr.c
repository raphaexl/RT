/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlwr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:58:07 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/19 09:59:04 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlwr(const char *str)
{
	char	*s;
	int		i;

	if (!(s = ft_strdup(str)))
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] <= 'Z' && s[i] >= 'A')
			s[i] = s[i] + 'a' - 'A';
	return (s);
}
