/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capply.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 18:30:02 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 16:50:42 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_cview_apply(t_cview *view, t_camera *c)
{
	t_vec3		pos;
	t_vec3		at;
	static int	init = 0;
	float		angle;

	if (!init && (init = 1))
		ft_cview_camera(view, c);
	pos.x = ft_atof(view->v[0].e[0].mes);
	pos.y = ft_atof(view->v[0].e[1].mes);
	pos.z = ft_atof(view->v[0].e[2].mes);
	at.x = ft_atof(view->v[1].e[0].mes);
	at.y = ft_atof(view->v[1].e[1].mes);
	at.z = ft_atof(view->v[1].e[2].mes);
	angle = c->angle;
	*c = ft_camera_new(pos, at, c->focal_dist, c->fov);
	c->angle = angle;
}
