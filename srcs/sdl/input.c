/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:26:13 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/07 18:21:19 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void		ft_event_normal(t_input *in)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			in->quit = SDL_TRUE;
		else if (event.type == SDL_KEYDOWN)
		{
			in->keys[event.key.keysym.scancode] = SDL_TRUE;
			if (in->keys[SDL_SCANCODE_ESCAPE])
				in->quit = SDL_TRUE;
		}
		else if (event.type == SDL_KEYUP)
			in->keys[event.key.keysym.scancode] = SDL_FALSE;
		else if (event.type == SDL_MOUSEBUTTONDOWN)
			in->mouse[event.button.button] = SDL_TRUE;
		if (event.type == SDL_MOUSEBUTTONUP)
			in->mouse[event.button.button] = SDL_FALSE;
		if (event.type == SDL_MOUSEMOTION)
		{
			in->mousex = event.motion.x;
			in->mousey = event.motion.y;
		}
	}
}

void		ft_update_event(t_input *in)
{
	if (in->mode == EDITING)
	{
		ft_event_edition(in);
		return ;
	}
	else
		ft_event_normal(in);
}
