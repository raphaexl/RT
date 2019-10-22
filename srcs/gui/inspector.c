/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 17:24:57 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:07:33 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_inspector_init(t_ptr *ptr, t_inspector *ins)
{
	ft_inspector_setup1(ptr, ins);
	ft_inspector_setup2(ptr, ins);
	ft_inspector_setup3(ptr, ins);
	ft_inspector_setup4(ptr, ins);
}

void	ft_inspector_display(t_ptr *ptr, t_inspector *ins)
{
	ft_inspector_display1(ptr, ins);
	ft_inspector_display2(ptr, ins);
	ft_inspector_display3(ptr, ins);
	ft_inspector_display4(ptr, ins);
}

int		ft_inspector_pupdate_event(t_inspector *ins, t_input *in)
{
	int		i;
	int		j;

	i = -1;
	while (++i < N_PROPERTIES)
	{
		j = -1;
		while (++j < 3)
		{
			if (ft_gui_event(&ins->v3[i].e[j], in))
				return (1);
		}
	}
	i = -1;
	while (++i < N_VIEW1)
		if (ft_gui_event(&ins->v1[i].e, in))
			return (1);
	return (0);
}

int		ft_inspector_update_event(t_inspector *ins, t_input *in)
{
	int			i;
	int			j;

	if (ft_inspector_pupdate_event(ins, in))
		return (1);
	i = -1;
	while (++i < N_VIEW4)
	{
		j = -1;
		while (++j < 4)
		{
			if (ft_gui_event(&ins->v4[i].e[j], in))
				return (1);
		}
	}
	return (0);
}

void	ft_inspector_clean(t_inspector *ins)
{
	int		i;
	int		j;

	i = -1;
	while (++i < N_PROPERTIES)
	{
		j = -1;
		ft_button_clean(&ins->v3[i].b);
		while (++j < 3)
			ft_entry_clean(&ins->v3[i].e[j]);
	}
	j = -1;
	while (++j < N_VIEW1)
	{
		ft_button_clean(&ins->v1[j].b);
		ft_entry_clean(&ins->v1[j].e);
	}
	i = -1;
	while (++i < N_VIEW4)
	{
		j = -1;
		ft_button_clean(&ins->v4[i].b);
		while (++j < 4)
			ft_entry_clean(&ins->v4[i].e[j]);
	}
}
