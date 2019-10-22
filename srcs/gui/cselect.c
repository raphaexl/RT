/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cselect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:25:50 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 17:35:47 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_cview_camera(t_cview *view, t_camera *c)
{
	view->v[0].e[0].mes = ft_itoaf(c->pos.x, 2);
	view->v[0].e[1].mes = ft_itoaf(c->pos.y, 2);
	view->v[0].e[2].mes = ft_itoaf(c->pos.z, 2);
	view->v[1].e[0].mes = ft_itoaf(c->at.x, 2);
	view->v[1].e[1].mes = ft_itoaf(c->at.y, 2);
	view->v[1].e[2].mes = ft_itoaf(c->at.z, 2);
}
