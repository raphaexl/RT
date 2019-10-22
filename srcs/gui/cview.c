/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cview.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:34:54 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 19:05:34 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

void	ft_cview_init(t_ptr *ptr, t_cview *cv)
{
	int		i;

	i = -1;
	cv->b = ft_button_new(ptr, BUTB_COLOR, BUTT_COLOR, "CAMERA");
	cv->v[0].b = ft_button_new(ptr, BUTB_COLOR, BUTT_COLOR, "Position");
	cv->v[1].b = ft_button_new(ptr, BUTB_COLOR, BUTT_COLOR, "Look At");
	while (++i < 3)
		cv->v[0].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	i = -1;
	while (++i < 3)
		cv->v[1].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
}

void	ft_cview_display(t_ptr *ptr, t_cview *cv)
{
	ft_button_draw(ptr, &cv->b, END_X + DEFAULT_W, SCR_HEIGHT / 2);
	ft_button_draw(ptr, &cv->v[0].b, END_X + DEFAULT_W, SCR_HEIGHT / 2
			+ DEFAULT_H);
	ft_entry_draw(ptr, &cv->v[0].e[0], END_X + 20, SCR_HEIGHT / 2
			+ 2 * DEFAULT_H);
	ft_entry_draw(ptr, &cv->v[0].e[1], END_X + DEFAULT_W + 20,
			SCR_HEIGHT / 2 + 2 * DEFAULT_H);
	ft_entry_draw(ptr, &cv->v[0].e[2], END_X + DEFAULT_W * 2 + 20,
			SCR_HEIGHT / 2 + 2 * DEFAULT_H);
	ft_button_draw(ptr, &cv->v[1].b, END_X + DEFAULT_W, SCR_HEIGHT / 2
			+ 3 * DEFAULT_H);
	ft_entry_draw(ptr, &cv->v[1].e[0], END_X + 20, SCR_HEIGHT / 2
			+ 4 * DEFAULT_H);
	ft_entry_draw(ptr, &cv->v[1].e[1], END_X + DEFAULT_W + 20,
			SCR_HEIGHT / 2 + 4 * DEFAULT_H);
	ft_entry_draw(ptr, &cv->v[1].e[2], END_X + DEFAULT_W * 2 + 20,
			SCR_HEIGHT / 2 + 4 * DEFAULT_H);
}

int		ft_cview_update_event(t_cview *cv, t_input *in)
{
	int			i;
	int			j;

	j = -1;
	while (++j < 2)
	{
		i = -1;
		while (++i < 3)
			if (ft_gui_event(&cv->v[j].e[i], in))
				return (1);
	}
	return (0);
}

void	ft_cview_clean(t_cview *cv)
{
	int		j;
	int		i;

	ft_button_clean(&cv->b);
	i = -1;
	while (++i < 2)
	{
		ft_button_clean(&cv->v[i].b);
		j = -1;
		while (++j < 3)
			ft_entry_clean(&cv->v[i].e[j]);
	}
}
