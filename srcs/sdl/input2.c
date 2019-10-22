/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:30:09 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 21:25:03 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static int	ft_rtdigit(char c)
{
	if (c == '-')
		return (1);
	if (c == '.')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void		ft_event_key_down(SDL_Event *e, t_input *in)
{
	int			len;

	if (e->key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		in->quit = SDL_TRUE;
	else if (e->key.keysym.scancode == SDL_SCANCODE_BACKSPACE &&
			(len = ft_strlen(in->text)))
	{
		in->text[len - 1] = '\0';
		in->render_text = 1;
	}
	else if (e->key.keysym.scancode == SDL_SCANCODE_C &&
			(SDL_GetModState() & KMOD_CTRL))
		SDL_SetClipboardText(in->text);
	else if (e->key.keysym.scancode == SDL_SCANCODE_V &&
			(SDL_GetModState() & KMOD_CTRL))
	{
		in->text = ft_strjoin(in->text, SDL_GetClipboardText());
		in->render_text = 1;
	}
}

int			ft_event_edition(t_input *in)
{
	SDL_Event	e;

	SDL_StartTextInput();
	in->render_text = 0;
	SDL_GetMouseState(&in->mousex, &in->mousey);
	while (SDL_PollEvent(&e))
	{
		in->quit = (e.type == SDL_QUIT);
		if (e.type == SDL_KEYDOWN)
			ft_event_key_down(&e, in);
		else if (e.type == SDL_TEXTINPUT)
		{
			if (!(((e.text.text[0] == 'c' || e.text.text[0] == 'C') ||
							(e.text.text[0] == 'v' || e.text.text[0] == 'V'))
						&& (SDL_GetModState() & KMOD_CTRL)) &&
					(in->render_text = 1) && ft_rtdigit(e.text.text[0]))
				in->text = ft_strjoin(in->text, e.text.text);
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN)
			in->mouse[e.button.button] = SDL_TRUE;
		else if (e.type == SDL_MOUSEBUTTONUP)
			in->mouse[e.button.button] = SDL_FALSE;
	}
	SDL_StopTextInput();
	return (in->render_text);
}
