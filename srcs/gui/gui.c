/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:58:40 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/22 13:03:06 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

int		ft_event_entry_pressed(t_entry *entry, t_input *in)
{
	if (in->mouse[SDL_BUTTON_LEFT])
	{
		if (entry->ft_mouse_on_entry(entry, in->mousex, in->mousey))
		{
			in->mode = EDITING;
			in->focus = SDL_TRUE;
			in->text = "";
			entry->focus = SDL_TRUE;
			return (1);
		}
		else
		{
			in->mode = DEFAULT;
			in->focus = SDL_FALSE;
			entry->focus = SDL_FALSE;
			in->text = "";
		}
	}
	else if ((in->mouse[SDL_BUTTON_RIGHT]) && !(in->focus = SDL_FALSE))
	{
		in->text = "";
		in->mode = DEFAULT;
		entry->focus = SDL_FALSE;
	}
	return (0);
}

int		ft_gui_event(t_entry *entry, t_input *in)
{
	if (ft_event_entry_pressed(entry, in) && entry->focus)
		in->text = entry->mes;
	if (in->focus && entry->focus)
	{
		ft_process_entry(entry, in);
		return (1);
	}
	entry->focus = SDL_FALSE;
	return (0);
}
