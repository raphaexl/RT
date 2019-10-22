/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:07:58 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 13:11:45 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_col3	ft_add_scale_col3(t_col3 c1, t_col3 c2,
		double scale)
{
	c1.red += c2.red * scale;
	c1.green += c2.green * scale;
	c1.blue += c2.blue * scale;
	return (c1);
}

t_col3	ft_scale_col3(t_col3 c, double s)
{
	t_col3 ret;

	ret.red = c.red * s;
	ret.green = c.green * s;
	ret.blue = c.blue * s;
	return (ret);
}

t_col3	ft_get_col3(t_pixel pixel)
{
	t_col3	c;

	c.red = pixel.r;
	c.green = pixel.g;
	c.blue = pixel.b;
	return (c);
}

t_pixel	ft_scale_convert_col3(t_col3 c, double t)
{
	t_pixel col;
	int		r;
	int		g;
	int		b;

	c.red = c.red * t;
	c.green = c.green * t;
	c.blue = c.blue * t;
	r = (int)c.red;
	g = (int)c.green;
	b = (int)c.blue;
	r = r > 255 ? 255 : r;
	r = r < 0 ? 0 : r;
	g = g > 255 ? 255 : g;
	g = g < 0 ? 0 : g;
	b = b > 255 ? 255 : b;
	b = b < 0 ? 0 : b;
	col.r = r;
	col.g = g;
	col.b = b;
	col.col = col.r * 0x10000 + col.g * 0x100 + col.b;
	return (col);
}
