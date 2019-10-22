/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:00:38 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/20 11:55:06 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_font		ft_font(const char *message, const char *font_file, int font_size)
{
	t_font	f;

	f.mes = (char *)message;
	f.file = (char *)font_file;
	f.size = font_size;
	return (f);
}

SDL_Texture	*ft_get_render_text(SDL_Renderer *rend, t_font f, SDL_Color color)
{
	TTF_Font		*font;
	SDL_Surface		*surface;
	SDL_Texture		*texture;

	font = NULL;
	surface = NULL;
	texture = NULL;
	font = TTF_OpenFont(f.file, f.size);
	ERR_CHECK(surface = TTF_RenderText_Blended(font, f.mes, color));
	ERR_CHECK(texture = SDL_CreateTextureFromSurface(rend, surface));
	SDL_FreeSurface(surface);
	if (!font)
		perror(TTF_GetError());
	TTF_CloseFont(font);
	return (texture);
}

void		ft_render_draw_img(SDL_Renderer *ren, SDL_Texture *img, t_point p,\
		SDL_Rect *pos)
{
	SDL_Rect	src;

	src.x = p.x;
	src.y = p.y;
	src.w = pos->w;
	src.h = pos->h;
	if (ren && img)
		ERR_CHECK(SDL_RenderCopy(ren, img, &src, pos) == 0);
}
