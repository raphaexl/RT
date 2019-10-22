/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filters_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 21:37:47 by aabouibr          #+#    #+#             */
/*   Updated: 2019/10/07 21:37:48 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_col3		ft_greyscale(t_col3 c)
{
	double	grey;

	grey = (c.red + c.green + c.blue) / 3.0;
	c.red = grey;
	c.green = grey;
	c.blue = grey;
	return (c);
}

t_col3		ft_negate(t_col3 c)
{
	c.red = 255 - c.red;
	c.green = 255 - c.green;
	c.blue = 255 - c.blue;
	return (c);
}

t_col3		ft_apply_sepia(t_col3 c)
{
	int tr;
	int tg;
	int tb;

	tr = (int)(0.393 * c.red + 0.769 * c.green + 0.189 * c.blue);
	tg = (int)(0.349 * c.red + 0.686 * c.green + 0.168 * c.blue);
	tb = (int)(0.272 * c.red + 0.534 * c.green + 0.131 * c.blue);
	if (tr > 255)
		c.red = 255;
	else
		c.red = tr;
	if (tg > 255)
		c.green = 255;
	else
		c.green = tg;
	if (tb > 255)
		c.blue = 255;
	else
		c.blue = tb;
	return (c);
}
