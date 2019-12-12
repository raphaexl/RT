/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:34:09 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/12 11:30:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

SDL_Color	ft_sdl_color(Uint32 c)
{
	SDL_Color color;

	if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
	{
		color.r = (c >> 16) & 0xFF;
		color.g = (c >> 8) & 0xFF;
		color.b = (c) & 0xFF;
		color.a = (c >> 24) & 0xFF;
	}
	else
	{
		color.r = (c >> 24) & 0xFF;
		color.g = (c >> 16) & 0xFF;
		color.b = (c >> 8) & 0xFF;
		color.a = (c & AMASK);
	}
	return (color);
}

Uint32		ft_color_sdl(SDL_Color c)
{
	return ((c.r << 24) + (c.g << 16) + (c.b << 8) + c.a);
}

char		*ft_itoaf(long double nb, int precision)
{
	int				n;
	int				i;
	char			*temp;

	i = 0;
	n = nb;
	temp = ft_strdup(ft_itoa(n));
	nb = nb > 0 ? nb - n : -(nb - n);
	temp = ft_strjoin(temp, ".");
	while (nb < 0.1 && nb > -0.1 && i < precision - 1)
	{
		nb *= 10;
		i++;
	}
	n = nb * ft_pow(10, precision - i);
	n = (nb * ft_pow(10, precision - i) - n > 0.01) ? n + 1 : n;
	temp = ft_strjoin(temp, ft_itoa(n));
	return (temp);
}

double		ft_fade(double t)
{
	return (t * t * t * (t * (t * 6 - 15) + 10));
}

double		ft_lerp(double t, double a, double b)
{
	return (a + t * (b - a));
}
