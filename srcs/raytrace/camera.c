/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:50:25 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:30:35 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_camera	ft_camera_new(t_vec3 eye, t_vec3 at, float focal_dist, float a)
{
	t_camera	cam;

	ft_bzero(&cam, sizeof(t_camera));
	cam.ratio = (float)W_W / (float)W_H;
	cam.pos = eye;
	cam.at = at;
	cam.fov = a;
	cam.focal_dist = focal_dist;
	cam.h = tan((cam.fov * M_PI * (1.0 / 180.0)) / 2.0);
	cam.w = cam.ratio * cam.h;
	cam.radius = ft_vec3_norm(ft_vec3_sub(eye, at));
	cam.dir = ft_vec3_normalized(ft_vec3_sub(eye, at));
	cam.u = ft_vec3_normalized(ft_vec3_cross(ft_vec3(0.0,
					1.0, 0.0), cam.dir));
	cam.v = ft_vec3_cross(cam.dir, cam.u);
	cam.low_left = ft_vec3_sub(cam.pos, ft_vec3_sum(ft_vec3_kmult(cam.h,
					cam.v), ft_vec3_kmult(cam.w, cam.u)));
	cam.low_left = ft_vec3_sub(cam.low_left, cam.dir);
	cam.horiz = ft_vec3_kmult(2.0 * cam.w, cam.u);
	cam.vert = ft_vec3_kmult(2.0 * cam.h, cam.v);
	return (cam);
}

t_ray		ft_camera_ray(t_camera *cam, float x, float y)
{
	t_ray		r;
	t_vec3		tmp;
	t_vec3		point_aimed;
	t_vec3		start;
	double		radius;

	radius = 0.3;
	tmp = ft_vec3_sum(cam->low_left, ft_vec3_kmult((x + 0.5) / (float)W_W,
				cam->horiz));
	tmp = ft_vec3_sum(tmp, ft_vec3_kmult((y + 0.5) / (float)W_H,
				cam->vert));
	r.start = cam->pos;
	r.dir = ft_vec3_normalized(ft_vec3_sub(tmp, cam->pos));
	if (cam->focal_dist > 0.5f)
	{
		point_aimed = ft_vec3_sum(cam->pos, ft_vec3_kmult(cam->focal_dist,
					r.dir));
		start = ft_vec3_sum(cam->pos, ft_vec3_sum(ft_vec3_kmult(ft_rand48(),
		ft_vec3_kmult(radius, cam->horiz)), ft_vec3_kmult(ft_rand48(),
		ft_vec3_kmult(radius, cam->vert))));
		r.dir = ft_vec3_normalized(ft_vec3_sub(point_aimed, start));
		r.start = start;
	}
	return (r);
}
