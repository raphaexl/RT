/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspector_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:31:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:49:25 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_inspector_display1(t_ptr *ptr, t_inspector *ins)
{
	ft_button_draw(ptr, &ins->v3[0].b, 60, START_Y);
	ft_entry_draw(ptr, &ins->v3[0].e[0], 25, START_Y + DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[0].e[1], DEFAULT_W + 30, START_Y + DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[0].e[2], 2 * DEFAULT_W + 35,
			START_Y + DEFAULT_H);
	ft_button_draw(ptr, &ins->v3[1].b, 60, START_Y + 2 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[1].e[0], 25, START_Y + 3 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[1].e[1], DEFAULT_W + 30,
			START_Y + 3 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[1].e[2], 2 * DEFAULT_W + 35,
			START_Y + 3 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v3[2].b, 60, START_Y + 4 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[2].e[0], 25, START_Y + 5 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[2].e[1], DEFAULT_W + 30,
			START_Y + 5 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[2].e[2], 2 * DEFAULT_W + 35,
			START_Y + 5 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v3[3].b, 60, START_Y + 6 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[3].e[0], 25, START_Y + 7 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[3].e[1], DEFAULT_W + 30,
			START_Y + 7 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[3].e[2], 2 * DEFAULT_W + 35,
			START_Y + 7 * DEFAULT_H);
}

void	ft_inspector_display2(t_ptr *ptr, t_inspector *ins)
{
	ft_button_draw(ptr, &ins->v3[4].b, 60, START_Y + 8 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[4].e[0], 25, START_Y + 9 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[4].e[1], DEFAULT_W + 30,
			START_Y + 9 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[4].e[2], 2 * DEFAULT_W + 35,
			START_Y + 9 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v3[5].b, 60, START_Y + 10 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[5].e[0], 25, START_Y + 11 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[5].e[1], DEFAULT_W + 30,
			START_Y + 11 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[5].e[2], 2 * DEFAULT_W + 35,
			START_Y + 11 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v3[6].b, 60, START_Y + 12 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[6].e[0], 25, START_Y + 13 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[6].e[1], DEFAULT_W + 30,
			START_Y + 13 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[6].e[2], 2 * DEFAULT_W + 35,
			START_Y + 13 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v3[7].b, 60, START_Y + 14 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[7].e[0], 25, START_Y + 15 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[7].e[1], DEFAULT_W + 30,
			START_Y + 15 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[7].e[2], 2 * DEFAULT_W + 35,
			START_Y + 15 * DEFAULT_H);
}

void	ft_inspector_display3(t_ptr *ptr, t_inspector *ins)
{
	ft_button_draw(ptr, &ins->v1[0].b, 25, START_Y + 16 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v1[0].e, 2 * DEFAULT_W + 35,
			START_Y + 16 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v1[1].b, 25, START_Y + 17 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v1[1].e, 2 * DEFAULT_W + 35,
			START_Y + 17 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v1[2].b, 25, START_Y + 18 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v1[2].e, 2 * DEFAULT_W + 35,
			START_Y + 18 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v1[3].b, 25, START_Y + 19 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v1[3].e, 2 * DEFAULT_W + 35,
			START_Y + 19 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v1[4].b, 25, START_Y + 20 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v1[4].e, 2 * DEFAULT_W + 35,
			START_Y + 20 * DEFAULT_H);
}

void	ft_inspector_display4(t_ptr *ptr, t_inspector *ins)
{
	ft_button_draw(ptr, &ins->v3[8].b, 60, START_Y + 21 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[8].e[0], 25, START_Y + 22 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[8].e[1], DEFAULT_W + 30,
			START_Y + 22 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[8].e[2], 2 * DEFAULT_W + 35,
			START_Y + 22 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v3[9].b, 60, START_Y + 23 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[9].e[0], 25, START_Y + 24 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[9].e[1], DEFAULT_W + 30,
			START_Y + 24 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v3[9].e[2], 2 * DEFAULT_W + 35,
			START_Y + 24 * DEFAULT_H);
	ft_button_draw(ptr, &ins->v4[0].b, 60, START_Y + 25 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v4[0].e[0], 25, START_Y + 26 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v4[0].e[1], DEFAULT_W + 30,
			START_Y + 26 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v4[0].e[2], 2 * DEFAULT_W + 35,
			START_Y + 26 * DEFAULT_H);
	ft_entry_draw(ptr, &ins->v4[0].e[3], 3 * DEFAULT_W + 40,
			START_Y + 26 * DEFAULT_H);
}
