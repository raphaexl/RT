/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:12:56 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:13:06 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strleftjoin(char *str, char *buffer, int width)
{
	int		i;
	char	sign;
	char	*temp;

	sign = buffer[0];
	i = width - ft_strlen(buffer);
	if (i <= 0)
		return (buffer);
	if (str[0] == ' ')
		buffer = ft_strjoin(buffer, ft_newstr(*str, i));
	else
	{
		temp = (char *)malloc(sizeof(char) * (i + 1));
		temp = ft_newstr(*str, i);
		if (sign == '-' || sign == '+')
			temp[0] = buffer[0];
		if (sign == '-' || sign == '+')
			buffer = ft_strjoin(temp, ft_strchr(buffer, sign) + 1);
		else
			buffer = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	return (buffer);
}

char			*ft_strrightjoin(char *str, char *buffer, int width)
{
	int		i;
	char	sign;
	char	*temp;

	sign = buffer[0];
	i = width - ft_strlen(buffer);
	if (i <= 0)
		return (buffer);
	if (str[0] == ' ')
		buffer = ft_strjoin(ft_newstr(*str, i), buffer);
	else
	{
		temp = (char *)malloc(sizeof(char) * (i + 1));
		if (sign == '-' || sign == '+')
			temp[0] = buffer[0];
		temp = ft_strjoin(temp, ft_newstr(*str, i));
		temp = ft_strjoin(temp, str);
		if (sign == '-' || sign == '+')
			buffer = ft_strjoin(temp, ft_strchr(buffer, sign) + 1);
		else
			buffer = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	return (buffer);
}
