/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 19:25:02 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 12:17:40 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_H
# define VEC3_H

# include "defines.h"

typedef struct	s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

typedef struct	s_vec2
{
	float	x;
	float	y;
}				t_vec2;

typedef struct	s_uv
{
	float	u;
	float	v;
}				t_uv;

t_vec3			ft_vec3(float x, float y, float z);
t_vec3			ft_vec3_sum(t_vec3 a, t_vec3 b);
t_vec3			ft_vec3_sub(t_vec3 a, t_vec3 b);
t_vec3			ft_vec3_mult(t_vec3 a, t_vec3 b);
t_vec3			ft_vec3_cross(t_vec3 a, t_vec3 b);
t_vec3			ft_vec3_kmult(float k, t_vec3 b);
t_vec3			ft_vec3_normalized(t_vec3 a);
float			ft_vec3_norm(t_vec3 a);
float			ft_vec3_norm2(t_vec3 a);
float			ft_vec3_dot(t_vec3 a, t_vec3 b);
t_vec3			ft_reflect(t_vec3 v, t_vec3 n);
int				ft_refract(t_vec3 v, t_vec3 n, float ior, t_vec3 *r);
#endif
