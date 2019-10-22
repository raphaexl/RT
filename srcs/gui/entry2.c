/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entry2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:11:20 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 16:03:44 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		ft_process_entry(t_entry *e, t_input *in)
{
	if (e->ft_mouse_on_entry && in->render_text && ft_strlen(in->text))
	{
		e->mes = ft_strcpy(e->mes, in->text);
		return (1);
	}
	return (0);
}

void	ft_entry_process(t_entry *w, t_input *in)
{
	if (ft_mouse_on_entry(w, in->mousex, in->mousey))
		ft_putendl("Yes");
}

void	ft_entry_draw(t_ptr *ptr, t_entry *w, int x, int y)
{
	SDL_Rect		dest;
	SDL_Rect		pos;

	w->x = x;
	w->y = y;
	dest = (SDL_Rect){x, y, w->pos[0].w, w->pos[0].h};
	pos = (SDL_Rect){0, 0, w->pos[0].w, w->pos[0].h};
	SDL_RenderCopy(ptr->renderer, w->img, NULL, &dest);
	dest = (SDL_Rect){x + w->pos[0].w / 2 - w->pos[1].w / 2,
	y + w->pos[0].h / 2 - w->pos[1].h / 2, w->pos[1].w, w->pos[1].h};
	SDL_RenderCopy(ptr->renderer, w->lab, NULL, &dest);
	if (!ft_strlen(w->mes))
		return ;
	if (!(w->tex = ft_get_render_text(ptr->renderer, ft_font(w->mes,
						DEFAULT_FONT, DEFAULT_FSIZE),
					ft_sdl_color(w->color2))))
		ft_print_error("Error entry text rendering ");
	if (SDL_QueryTexture(w->tex, NULL, NULL, &pos.w, &pos.h))
		ft_print_error("Error SDL_QueryTexture :");
	dest = (SDL_Rect){dest.x + w->pos[1].w / 2 - pos.w / 2,
	dest.y + w->pos[1].h / 2 - pos.h / 2, pos.w, pos.h};
	SDL_RenderCopy(ptr->renderer, w->tex, &pos, &dest);
	SDL_DestroyTexture(w->tex);
	w->tex = NULL;
}
