/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perlin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 20:40:26 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 17:54:40 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

double		ft_grad(int hash, double x, double y, double z)
{
	int		h;
	double	u;
	double	v;

	h = hash % 15;
	u = h < 8 ? x : y;
	v = h < 4 ? y : 0;
	v = h == 12 || h == 14 ? x : z;
	return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
}

static int	*ft_get_permutation(void)
{
	static int permutation[] =
	{151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53,
		194, 233, 7, 225, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
		190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117,
		35, 11, 32, 57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125, 136, 171,
		168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166, 77, 146, 158, 231, 83,
		111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40,
		244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187,
		208, 89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109,
		198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147, 118,
		126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182, 189, 28,
		42, 223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163, 70, 221, 153,
		101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79, 113,
		224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251, 34, 242, 193, 238,
		210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249, 14, 239, 107,
		49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50,
		45, 127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67, 29, 24, 72, 243,
		141, 128, 195, 78, 66, 215, 61, 156, 180};

	return (permutation);
}

static void	ft_perlin_init(t_perlin *perlin, t_vec3 *v, int *p)
{
	perlin->x = ((int)floor(v->x)) & 255;
	perlin->y = ((int)floor(v->y)) & 255;
	perlin->z = ((int)floor(v->z)) & 255;
	v->x -= floor(v->x);
	v->y -= floor(v->y);
	v->z -= floor(v->z);
	perlin->fx = ft_fade(v->x);
	perlin->fy = ft_fade(v->y);
	perlin->fz = ft_fade(v->z);
	perlin->a = p[perlin->x] + perlin->y;
	perlin->aa = p[perlin->a] + perlin->z;
	perlin->ab = p[perlin->a + 1] + perlin->z;
	perlin->b = p[perlin->x + 1] + perlin->y;
	perlin->ba = p[perlin->b] + perlin->z;
	perlin->bb = p[perlin->b + 1] + perlin->z;
}

static void	ft_permute(int *p, int *permutation)
{
	int			i;

	i = -1;
	while (++i < 256)
	{
		p[i] = permutation[i];
		p[256 + i] = p[i];
	}
}

double		ft_perlin(double x, double y, double z)
{
	int			p[512];
	t_vec3		v;
	int			*permutation;
	t_perlin	perlin;

	v = (t_vec3){.x = x, .y = y, .z = z};
	permutation = ft_get_permutation();
	ft_permute(p, permutation);
	ft_perlin_init(&perlin, &v, p);
	return (ft_lerp(perlin.fz, ft_lerp(perlin.fy,
					ft_lerp(perlin.fx, ft_grad(p[perlin.aa], v.x, v.y, v.z),
						ft_grad(p[perlin.ba], v.x - 1, v.y, v.z)),
					ft_lerp(perlin.fx, ft_grad(p[perlin.ab], v.x, v.y - 1, v.z),
						ft_grad(p[perlin.bb], v.x - 1, v.y - 1, v.z))),
				ft_lerp(perlin.fy, ft_lerp(perlin.fx,
						ft_grad(p[perlin.aa + 1], v.x, v.y, v.z - 1),
						ft_grad(p[perlin.ba + 1], v.x - 1, v.y, v.z - 1)),
					ft_lerp(perlin.fx,
						ft_grad(p[perlin.ab + 1], v.x, v.y - 1, v.z - 1),
						ft_grad(p[perlin.bb + 1],
							v.x - 1, v.y - 1, v.z - 1)))));
}
