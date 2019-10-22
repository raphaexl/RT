/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:00:56 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 13:25:14 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_col3		ft_col3(float r, float g, float b)
{
	t_col3	color;

	color.red = r;
	color.green = g;
	color.blue = b;
	return (color);
}

t_col3		ft_col3_sum(t_col3 a, t_col3 b)
{
	t_col3 res;

	res.red = a.red + b.red;
	res.green = a.green + b.green;
	res.blue = a.blue + b.blue;
	return (res);
}

t_col3		ft_col3_mult(t_col3 a, t_col3 b)
{
	t_col3 res;

	res.red = a.red * b.red;
	res.green = a.green * b.green;
	res.blue = a.blue * b.blue;
	return (res);
}

t_col3		ft_col3_kmult(float k, t_col3 a)
{
	t_col3 res;

	res.red = k * a.red;
	res.green = k * a.green;
	res.blue = k * a.blue;
	return (res);
}
