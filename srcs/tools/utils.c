/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:59:58 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/12 11:30:47 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

float	ft_modulo(float f)
{
	return (f - floor(f));
}

float	ft_clamp(float min, float max, float val)
{
	return (fmax(min, fmin(max, val)));
}

float	ft_rand48(void)
{
	static int	initialized = 0;

	if (!initialized)
	{
		initialized = 1;
		srand(time(NULL));
	}
	return ((float)(rand() % RAND_MAX) / ((float)(RAND_MAX + 1.0)));
}

int		ft_tab_len(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

t_pixel	ft_get_color(int color)
{
	t_pixel	c;

	c.col = color;
	c.r = color / 0x10000;
	c.g = color / 0x100;
	c.b = color % 0x100;
	return (c);
}
