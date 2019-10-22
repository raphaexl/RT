/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspector_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:25:04 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 19:14:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_inspector_setup1(t_ptr *ptr, t_inspector *ins)
{
	int		i;

	i = -1;
	ins->v3[0].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Position");
	while (++i < 3)
		ins->v3[0].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	i = -1;
	ins->v3[1].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Rotation");
	while (++i < 3)
		ins->v3[1].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	i = -1;
	ins->v3[2].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Scale");
	while (++i < 3)
		ins->v3[2].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
}

void	ft_inspector_setup2(t_ptr *ptr, t_inspector *ins)
{
	int		i;

	i = -1;
	ins->v3[3].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Direction");
	while (++i < 3)
		ins->v3[3].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	i = -1;
	ins->v3[4].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "V1");
	while (++i < 3)
		ins->v3[4].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	i = -1;
	ins->v3[5].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "V2");
	while (++i < 3)
		ins->v3[5].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	i = -1;
	ins->v3[6].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "V3");
	while (++i < 3)
		ins->v3[6].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
}

void	ft_inspector_setup3(t_ptr *ptr, t_inspector *ins)
{
	int		i;

	i = -1;
	ins->v3[7].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "V4");
	while (++i < 3)
		ins->v3[7].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	ins->v1[0].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Radius 1");
	ins->v1[0].e = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	ins->v1[1].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Radius 2");
	ins->v1[1].e = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	ins->v1[2].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Height");
	ins->v1[2].e = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	ins->v1[3].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Angle");
	ins->v1[3].e = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	ins->v1[4].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Power");
	ins->v1[4].e = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
}

void	ft_inspector_setup4(t_ptr *ptr, t_inspector *ins)
{
	int		i;

	i = -1;
	ins->v3[8].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Diffuse");
	while (++i < 3)
		ins->v3[8].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	i = -1;
	ins->v3[9].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "Specular");
	while (++i < 3)
		ins->v3[9].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
	i = -1;
	ins->v4[0].b = ft_button_new(ptr, BUTB_COLOR, WHITE, "albedo");
	while (++i < 4)
		ins->v4[0].e[i] = ft_entry_new(ptr, ENTB_COLOR, YELLOW, "0.00");
}
