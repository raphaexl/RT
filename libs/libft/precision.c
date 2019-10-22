/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:13:26 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:13:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_precision_algo1(char *str, int i)
{
	while (str[i - 1] == '9')
		str[i--] = '0';
	str[i - 1] = str[i - 1] + (str[i] > '5');
	str[i] = str[i] == '9' ? '0' : str[i];
	return (str);
}

char			*ft_precision_algo(char *str, int pos)
{
	size_t		i;
	size_t		len;

	i = pos + 1;
	len = ft_strlen(str);
	if (i - 1 < len)
	{
		if (str[i] != '5')
			str = ft_precision_algo1(str, i);
		else
		{
			while (str[++i])
			{
				if (str[i] == '0')
					continue;
				else
					break ;
			}
			if (i < len && str[i] > '5')
				str[pos + 1] = str[pos + 1] + 1;
			else
				str[pos + 1] = !(str[pos] % 2);
		}
	}
	return (str);
}

char			*ft_handle_precision(char *buffer, int prec)
{
	int		len;
	char	*temp;
	char	*p;

	if (!(p = ft_strchr(buffer, '.')))
		return (buffer);
	len = prec - ft_strlen(p + 1);
	if (len <= 0)
	{
		len = ft_strlen(buffer) - ft_strlen(p);
		temp = ft_strsub(buffer, 0, len);
		return (ft_strjoin(temp, prec ? ft_precision_algo(ft_strsub(p, 0,
							prec + 1), prec - 1) : NULL));
	}
	buffer = ft_strjoin(buffer, ft_newstr('0', len));
	return (buffer);
}
