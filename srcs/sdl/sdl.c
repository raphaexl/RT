/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:58:32 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/22 16:36:02 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

int			ft_sdl_init(t_ptr *ptr, const char *title)
{
	SDL_Surface	*ico;

	ERR_CHECK(SDL_Init(SDL_INIT_EVERYTHING) == 0);
	ERR_CHECK(TTF_Init() == 0);
	ERR_CHECK(IMG_Init(IMG_INIT_PNG) != 0);
	ERR_CHECK(ptr->window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, SCR_WIDTH, SCR_HEIGHT,
				SDL_WINDOW_SHOWN));
	ERR_CHECK(ptr->renderer = SDL_CreateRenderer(ptr->window, -1,\
				SDL_RENDERER_ACCELERATED));
	ERR_CHECK(ptr->texture = SDL_CreateTexture(ptr->renderer, \
				SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, W_W, W_H));
	if ((ico = IMG_Load("data/imgs/SDL_Logo.png")))
	{
		SDL_SetWindowIcon(ptr->window, ico);
		SDL_FreeSurface(ico);
	}
	ico = NULL;
	return (0);
}

Uint32		ft_get_pixels(SDL_Surface *s, int x, int y)
{
	int		bpp;
	Uint8	*p;

	bpp = s->format->BytesPerPixel;
	p = (Uint8 *)s->pixels + y * s->pitch + x * bpp;
	if (bpp == 1)
		return (*p);
	if (bpp == 2)
		return (*(Uint16 *)p);
	if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (p[0] << 16 | p[1] << 8 | p[2]);
		else
			return (p[0] | p[1] << 8 | p[2] << 16);
	}
	if (bpp == 4)
		return (*(Uint32 *)p);
	return (0);
}

Uint32		*ft_load_pixels(char *file_name, int *w, int *h)
{
	SDL_Surface		*s;
	int				x;
	int				y;
	Uint32			*pixels;

	s = IMG_Load(file_name);
	if (!s)
		ft_sdl_error();
	pixels = (Uint32 *)malloc(sizeof(Uint32) * (s->w * s->h));
	SDL_LockSurface(s);
	y = -1;
	while ((++y < s->h) && (x = -1))
		while (++x < s->w)
			pixels[y * s->w + x] = ft_get_pixels(s, x, y);
	SDL_UnlockSurface(s);
	*w = s->w;
	*h = s->h;
	SDL_FreeSurface(s);
	s = NULL;
	return (pixels);
}

int			ft_update_renderer(t_ptr *ptr, Uint32 *pixels)
{
	SDL_Rect	d;

	d = (SDL_Rect){.x = START_X, .y = START_Y,
		.w = W_W, .h = W_H};
	SDL_UpdateTexture(ptr->texture, NULL, pixels, W_W * sizeof(Uint32));
	SDL_RenderCopy(ptr->renderer, ptr->texture, NULL, &d);
	return (0);
}

void		ft_sdl_quit(t_ptr *ptr)
{
	if (ptr->texture)
		SDL_DestroyTexture(ptr->texture);
	ptr->texture = NULL;
	if (ptr->renderer)
		SDL_DestroyRenderer(ptr->renderer);
	ptr->renderer = NULL;
	if (ptr->window)
		SDL_DestroyWindow(ptr->window);
	ptr->window = NULL;
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
}
