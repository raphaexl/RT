/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_calc1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:07:35 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:07:47 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_zeros(int len)
{
	char *new;

	new = (char*)malloc(len + 1);
	new = ft_memset(new, '0', len);
	new = ft_strjoin("0.", new);
	return (new);
}

static size_t	ft_is_end(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

char			*ft_mvfrc(char *str, int frac_len)
{
	char	*new;
	int		str_len;
	int		i;

	i = -1;
	str_len = ft_strlen(str);
	if (str_len - frac_len == 0)
		new = ft_strjoin("0.", str);
	else if (str_len - frac_len < 0)
	{
		new = ft_strdup(str);
		new = ft_strjoin(ft_zeros(ABS((str_len - frac_len))), new);
	}
	else
	{
		new = ft_strjoin(".", str);
		while (++i < ABS((str_len - frac_len)))
		{
			new[i] = new[i + 1];
			new[i + 1] = '.';
		}
	}
	return (new);
}

char			*ft_rmz(char *str, short flag_frac)
{
	size_t	i;

	i = 0;
	if (flag_frac)
	{
		while (str[i] != '.')
			i++;
	}
	if (ft_is_end(str + i + 1))
	{
		str[i] = 0;
		return (str);
	}
	while (str[i])
	{
		if (ft_is_end(str + i))
			str[i] = 0;
		i++;
	}
	return (str);
}
