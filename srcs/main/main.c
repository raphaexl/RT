/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:53:56 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:08:25 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	ft_env_draw(t_env *e)
{
	int		i;

	SDL_SetRenderDrawColor(e->ptr.renderer, 0x20, 0x20, 0x20, 255);
	SDL_RenderClear(e->ptr.renderer);
	i = NB_OPTIONS;
	while (--i >= 0)
		SDL_RenderCopy(e->ptr.renderer, e->menu.img[i], NULL, &e->menu.pos[i]);
	ft_env_display_text(e->ptr.renderer,
			e->selected ? e->selected->name : "NONE");
	if (ft_process_event(e, &e->in) && (e->in.mode == DEFAULT))
	{
		ft_inspector_apply(&e->inspector, &e->selected);
		if (e->optimize)
			ft_draw(e);
		else
			ft_render(&e->s, e->pixels);
		ft_filter(e);
	}
	else
		ft_cview_apply(&e->cview, &e->s.cam);
	ft_inspector_display(&e->ptr, &e->inspector);
	ft_cview_display(&e->ptr, &e->cview);
	ft_update_renderer(&e->ptr, e->pixels);
	SDL_RenderPresent(e->ptr.renderer);
}

int			main(int argc, char *argv[])
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	if (argc <= 3)
		ft_env_init(&e, argc, argv);
	else
		ft_error();
	ft_memset(&e.in, SDL_FALSE, sizeof(t_input));
	e.in.text = ft_strdup("");
	while (!e.in.quit)
	{
		ft_update_event(&e.in);
		ft_env_draw(&e);
		SDL_Delay(16);
	}
	ft_env_quit(&e);
	return (0);
}
