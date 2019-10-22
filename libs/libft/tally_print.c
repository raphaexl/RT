/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tally_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:10:58 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:11:08 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tally_get(int size, int add)
{
	static int	total = 0;
	static int	locked = 0;

	if (add == 0)
	{
		size = total;
		total = 0;
		locked = 0;
		return (size);
	}
	if (add == -1)
	{
		total = -1;
		locked = 1;
		return (total);
	}
	if (!locked)
		total += size;
	if (add == -2)
		locked = 1;
	return (total);
}

int		ft_tally_print(void *mem, int size)
{
	char	*str;
	int		ret;
	int		i;

	str = mem;
	i = 0;
	while (i < size)
	{
		ret = write(1, str + i, 1);
		if (ret == -1)
			ft_tally_get(0, -1);
		else
			ft_tally_get(1, 1);
		i++;
	}
	return (1);
}

void	ft_tally_str(char *str)
{
	ft_tally_print(str, ft_strlen(str));
}
