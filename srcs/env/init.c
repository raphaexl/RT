/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 08:53:56 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 19:29:56 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_img	ft_load_img(SDL_Renderer *rend, const char *file_name)
{
	SDL_Surface		*s;
	int				x;
	int				y;
	t_img			img;

	s = IMG_Load(file_name);
	if (!s)
		ft_sdl_error();
	img.pixels = (Uint32 *)malloc(sizeof(Uint32) * (s->w * s->h));
	SDL_LockSurface(s);
	y = -1;
	while ((++y < s->h) && (x = -1))
		while (++x < s->w)
			img.pixels[y * s->w + x] = ft_get_pixels(s, x, y);
	SDL_UnlockSurface(s);
	img.width = s->w;
	img.height = s->h;
	if (!(img.img = SDL_CreateTextureFromSurface(rend, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	return (img);
}

void	ft_env_load_images(t_env *e)
{
	SDL_Surface		*s;

	ft_env_load_img5(e);
	if (!(s = IMG_Load("data/imgs/bouton_bmp.png")))
		ft_sdl_error();
	if (!(e->menu.img[20] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_png.png")))
		ft_sdl_error();
	if (!(e->menu.img[21] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_rt.png")))
		ft_sdl_error();
	if (!(e->menu.img[22] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	s = NULL;
}
