/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:51:47 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/19 10:01:04 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupr(const char *str)
{
	char	*s;
	int		i;

	if (!(s = ft_strdup(str)))
		return (NULL);
	i = -1;
	while (s[++i])
		if (s[i] <= 'z' && s[i] >= 'a')
			s[i] = s[i] + 'A' - 'a';
	return (s);
}
