/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 20:30:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 14:02:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_material		ft_default_material(void)
{
	t_material	m;

	ft_bzero(&m, sizeof(t_material));
	m.diffuse = (t_col3){1.0, 0.0, 0.0};
	m.diffuse1 = (t_col3){1.0, 0.0, 0.0};
	m.diffuse2 = (t_col3){1.0, 1.0, 1.0};
	m.specular = (t_col3){1.0, 1.0, 1.0};
	m.albedo[0] = .5;
	m.albedo[1] = .5;
	m.spec_pow = 60.0;
	return (m);
}
