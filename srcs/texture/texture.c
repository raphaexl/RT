/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:59:02 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 18:58:51 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static t_col3	ft_pixel_col3(Uint32 col)
{
	t_col3	c;

	c.red = (float)((col >> 16) & 0xFF) / 255.0;
	c.green = (float)((col >> 8) & 0xFF) / 255.0;
	c.blue = (float)(col & 0xFF) / 255.0;
	return (c);
}

t_col3			*ft_textures_pixels(char *file_name, int *w, int *h)
{
	SDL_Surface		*s;
	int				x;
	int				y;
	t_col3			*pixels;

	s = IMG_Load(file_name);
	if (!s)
		ft_sdl_error();
	pixels = (t_col3 *)malloc(sizeof(t_col3) * (s->w * s->h));
	SDL_LockSurface(s);
	y = -1;
	while ((++y < s->h) && (x = -1))
		while (++x < s->w)
			pixels[y * s->w + x] = ft_pixel_col3(ft_get_pixels(s, x, y));
	SDL_UnlockSurface(s);
	*w = s->w;
	*h = s->h;
	SDL_FreeSurface(s);
	s = NULL;
	return (pixels);
}

t_texture		*ft_texture_new(char *img)
{
	t_texture	*new;

	if (!(new = (t_texture *)malloc(sizeof(t_texture))))
		ft_print_error("Error malloc !");
	if (!(new->data = ft_textures_pixels(img, &new->w, &new->h)))
		ft_print_error("Error loading texture image !");
	return (new);
}

void			ft_texture_clean(t_texture **t)
{
	free((*t)->data);
	free(*t);
}
