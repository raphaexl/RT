/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:57:52 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:26:27 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_put_pixels(SDL_Surface *s, int x, int y, Uint32 pixel)
{
	int		bpp;
	Uint8	*p;

	bpp = s->format->BytesPerPixel;
	p = (Uint8 *)s->pixels + y * s->pitch + x * bpp;
	if (bpp == 1)
		*p = pixel;
	else if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xFF;
			p[1] = (pixel >> 8) & 0xFF;
			p[2] = (pixel & 0xFF);
		}
		else
		{
			p[0] = pixel & 0xFF;
			p[1] = (pixel >> 8) & 0xFF;
			p[2] = (pixel >> 16) & 0xFF;
		}
	}
	else
		*(Uint32 *)p = pixel;
}

void	ft_save_bmp_pixels(Uint32 *pixels, int w, int h)
{
	SDL_Surface		*s;
	int				x;
	int				y;

	if (!(s = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0)))
		ft_sdl_error();
	SDL_LockSurface(s);
	y = -1;
	while ((++y < h) && (x = -1))
		while (++x < w)
			ft_put_pixels(s, x, y, pixels[y * w + x]);
	SDL_UnlockSurface(s);
	SDL_SaveBMP(s, "out.bmp");
	ft_printf("A File out.bmp has been saved to current working directory\n");
	SDL_FreeSurface(s);
	s = NULL;
}

void	ft_save_png_pixels(Uint32 *pixels, int w, int h)
{
	SDL_Surface		*s;
	int				x;
	int				y;

	if (!(s = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0)))
		ft_sdl_error();
	SDL_LockSurface(s);
	y = -1;
	while ((++y < h) && (x = -1))
		while (++x < w)
			ft_put_pixels(s, x, y, pixels[y * w + x]);
	SDL_UnlockSurface(s);
	IMG_SavePNG(s, "out.png");
	ft_printf("A File out.png has been saved to current working directory\n");
	SDL_FreeSurface(s);
	s = NULL;
}

void	ft_save_jpg_pixels(Uint32 *pixels, int w, int h)
{
	SDL_Surface		*s;
	int				x;
	int				y;

	if (!(s = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0)))
		ft_sdl_error();
	SDL_LockSurface(s);
	y = -1;
	while ((++y < h) && (x = -1))
		while (++x < w)
			ft_put_pixels(s, x, y, pixels[y * w + x]);
	SDL_UnlockSurface(s);
	IMG_SaveJPG(s, "out.jpg", JPG_QUALITY);
	ft_printf("A File out.jpg has been saved to current working directory\n");
	SDL_FreeSurface(s);
	s = NULL;
}
