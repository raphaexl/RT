/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:13:11 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 18:44:48 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		ft_entry_setup(t_entry *w, Uint32 c, Uint32 c2, const char *m)
{
	w->focus = SDL_FALSE;
	w->color = c;
	w->color2 = c2;
	w->ft_mouse_on_entry = &ft_mouse_on_entry;
	w->x = SCR_WIDTH / 2;
	w->y = SCR_HEIGHT / 2;
	w->mes = ft_strdup(m);
	w->pos[0] = (SDL_Rect){0, 0, DEFAULT_W, DEFAULT_H};
	w->pos[1] = (SDL_Rect){0, 0, DEFAULT_W - 10, DEFAULT_H - 10};
}

t_entry			ft_entry_new(t_ptr *ptr, Uint32 c, Uint32 c2, const char *m)
{
	t_entry		w;
	SDL_Surface	*surf;

	ft_entry_setup(&w, c, c2, m);
	if (!(surf = SDL_CreateRGBSurface(0, DEFAULT_W, DEFAULT_H, 32, RMASK,
					GMASK, BMASK, AMASK)))
		ft_print_error("Creating entry 's Surface");
	if (SDL_FillRect(surf, &w.pos[0], w.color))
		ft_print_error("Error Coloruring the rect surface");
	if (!(w.img = SDL_CreateTextureFromSurface(ptr->renderer, surf)))
		ft_print_error("Creating entry 's Texture");
	SDL_FreeSurface(surf);
	surf = NULL;
	if (!(surf = SDL_CreateRGBSurface(0, DEFAULT_W - 10, DEFAULT_H - 10, 32,
					RMASK, GMASK, BMASK, AMASK)))
		ft_print_error("Creating entry 's Surface");
	if (SDL_FillRect(surf, &w.pos[1], 0xFFFFFFFF))
		ft_print_error("Error Coloruring the rect surface");
	if (!(w.lab = SDL_CreateTextureFromSurface(ptr->renderer, surf)))
		ft_print_error("Creating entry 's Texture");
	SDL_FreeSurface(surf);
	surf = NULL;
	return (w);
}

t_entry			*ft_entry_create(t_ptr *ptr, Uint32 c, Uint32 c2, const char *m)
{
	t_entry		*w;
	SDL_Surface	*surf;

	if (!(w = (t_entry *)malloc(sizeof(*w))))
		ft_print_error("Error malloc on creating entry's component !");
	ft_entry_setup(w, c, c2, m);
	if (!(surf = SDL_CreateRGBSurface(0, DEFAULT_W, DEFAULT_H, 32, RMASK,
					GMASK, BMASK, AMASK)))
		ft_print_error("Creating entry 's Surface");
	if (SDL_FillRect(surf, &w->pos[0], w->color))
		ft_print_error("Error Coloruring the rect surface");
	if (!(w->img = SDL_CreateTextureFromSurface(ptr->renderer, surf)))
		ft_print_error("Creating entry 's Texture");
	SDL_FreeSurface(surf);
	surf = NULL;
	if (!(surf = SDL_CreateRGBSurface(0, DEFAULT_W - 10, DEFAULT_H - 10, 32,
					RMASK, GMASK, BMASK, AMASK)))
		ft_print_error("Creating entry 's Surface");
	if (SDL_FillRect(surf, &w->pos[1], 0xFFFFFFFF))
		ft_print_error("Error Coloruring the rect surface");
	if (!(w->lab = SDL_CreateTextureFromSurface(ptr->renderer, surf)))
		ft_print_error("Creating entry 's Texture");
	SDL_FreeSurface(surf);
	surf = NULL;
	return (w);
}

void			ft_entry_clean(t_entry *b)
{
	if (b->img)
		SDL_DestroyTexture(b->img);
	if (b->tex)
		SDL_DestroyTexture(b->tex);
	if (b->lab)
		SDL_DestroyTexture(b->lab);
}

int				ft_mouse_on_entry(t_entry *w, int x, int y)
{
	if ((x < w->x) || (x > w->x + w->pos[0].w) || (y < w->y) ||
			(y > w->y + w->pos[0].h))
		return (0);
	return (1);
}
