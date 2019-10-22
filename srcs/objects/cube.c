/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:51:21 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:55:17 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_min_ray(double s[4], float *t, int n)
{
	double	min;
	int		i;

	i = -1;
	while (++i < n)
	{
		if (s[i] > 0.0001)
		{
			min = s[i];
			break ;
		}
	}
	if (i == n)
		return (0);
	while (++i < n)
	{
		if (s[i] > 0.0001 && s[i] < min)
			min = s[i];
	}
	if (min < *t && min > 0.0001)
	{
		*t = min;
		return (n);
	}
	return (0);
}

t_object	*ft_cube_new(void)
{
	t_object	*new;

	if ((new = (t_object *)ft_memalloc(sizeof(*new))))
	{
		new->type = CUBE;
		new->name = "CUBE";
		new->pos = (t_vec3){0.0, 0.0, 0.0};
		new->translate = (t_vec3){0.0, 0.0, 0.0};
		new->rotate = (t_vec3){0.0, 0.0, 0.0};
		new->scale = (t_vec3){1.0f, 1.0f, 1.0f};
		new->material = ft_default_material();
		new->e.cube.radius = 11.8;
		new->next = NULL;
	}
	else
		ft_print_error("malloc error");
	return (new);
}

t_vec3		ft_normal_cube(t_cube *c, t_vec3 h)
{
	t_vec3	p;
	double	x;
	double	y;
	double	z;

	(void)c;
	x = h.x;
	y = h.y;
	z = h.z;
	p.x = 4.0 * x * x * x - 10.0 * x;
	p.y = 4.0 * y * y * y - 10.0 * y;
	p.z = 4.0 * z * z * z - 10.0 * z;
	return (ft_vec3_normalized(p));
}

int			ft_cube_compute(t_object *p, t_intersect *in)
{
	t_ray		r;

	r = in->ray;
	if (!ft_cube_intersect(&p->e.cube, &r, &in->t))
		return (0);
	in->current = p;
	in->p = ft_vec3_sum(r.start, ft_vec3_kmult(in->t, r.dir));
	in->n = ft_normal_cube(&p->e.cube, in->p);
	if (p->material.bump)
		in->n = ft_normal_bump(in);
	in->p = ft_translate_vec3(in->p, p->translate, 0);
	in->p = ft_rotate_vec3(in->p, p->rotate, 0);
	in->p = ft_scale_vec3(in->p, p->scale, 0);
	in->n = ft_rotate_vec3(in->n, p->rotate, 0);
	in->n = ft_scale_vec3(in->n, p->scale, -1);
	in->n = ft_vec3_normalized(in->n);
	return (1);
}

int			ft_cube_intersect(t_cube *cube, t_ray *r, float *min)
{
	t_vec3		dist;
	int			num;
	double		c[5];
	double		s[4];

	c[4] = pow(r->dir.x, 4) + pow(r->dir.y, 4) + pow(r->dir.z, 4);
	dist = r->start;
	c[3] = 4.0 * (pow(r->dir.x, 3) * dist.x + pow(r->dir.y, 3) * dist.y
			+ pow(r->dir.z, 3) * dist.z);
	c[2] = 6.0 * (pow(r->dir.x, 2) * pow(dist.x, 2) + pow(r->dir.y, 2) *
			pow(dist.y, 2) + pow(r->dir.z, 2) * pow(dist.z, 2))
		- 5.0 * ft_vec3_dot(r->dir, r->dir);
	c[1] = 4.0 * (pow(dist.x, 3) * r->dir.x + pow(dist.y, 3) * r->dir.y
			+ pow(dist.z, 3) * r->dir.z)
		- 10.0 * ft_vec3_dot(r->dir, dist);
	c[0] = pow(dist.x, 4) + pow(dist.y, 4) + pow(dist.z, 4)
		- 5.0 * ft_vec3_dot(dist, dist) + cube->radius;
	num = ft_solve_quartic(c, s);
	if (num == 0)
		return (0);
	return (ft_min_ray(s, min, num));
}
