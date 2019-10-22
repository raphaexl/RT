/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 04:14:33 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 13:59:41 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_light		*ft_parse_point_light(t_light *l, char **str)
{
	int		i;

	l->u.point.pos = ft_vec3(-1.0, -1.0, -1.0);
	l->u.point.constant = 1.0;
	l->u.point.linear = 0.025;
	l->u.point.quadratic = 0.45;
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("POS", str[i]) || ft_rtstrequal("POSITION", str[i]))
			l->u.point.pos = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("LINEAR", str[i]))
			l->u.point.linear = ft_float_read(str[i]);
		else if (ft_rtstrequal("QUADRATIC", str[i]))
			l->u.point.quadratic = ft_float_read(str[i]);
	}
	return (ft_light_new(POINT_LIGHT, l));
}

static void	ft_aux_spot_light_init(t_light *l)
{
	l->u.spot.pos = ft_vec3(-1.0, -1.0, -1.0);
	l->u.spot.dir = ft_vec3(1.0 / 3.0, 1.0 / 3.0, 1.0 / 3.0);
	l->u.spot.constant = 1.0;
	l->u.spot.linear = 0.025;
	l->u.spot.quadratic = 0.45;
	l->u.spot.cut_off = cos(DEG_TO_RAD(40));
	l->u.spot.outer_cut_off = cos(DEG_TO_RAD(45));
}

t_light		*ft_parse_spot_light(t_light *l, char **str)
{
	int		i;

	i = -1;
	ft_aux_spot_light_init(l);
	while (str[++i])
	{
		if (ft_rtstrequal("POS", str[i]) || ft_rtstrequal("POSITION", str[i]))
			l->u.spot.pos = ft_vec3_read(str[i]);
		else if (ft_rtstrequal("DIR", str[i]) || ft_rtstrequal("DIRECTION",
					str[i]))
			l->u.spot.dir = ft_vec3_normalized(ft_vec3_read(str[i]));
		else if (ft_rtstrequal("LINEAR", str[i]))
			l->u.spot.linear = ft_float_read(str[i]);
		else if (ft_rtstrequal("QUADRATIC", str[i]))
			l->u.spot.quadratic = ft_float_read(str[i]);
		else if (ft_rtstrequal("CUT_OFF", str[i]))
			l->u.spot.cut_off = cos(DEG_TO_RAD(ft_float_read(str[i])));
		else if (ft_rtstrequal("OUTER_CUT_OFF", str[i]))
			l->u.spot.outer_cut_off = cos(DEG_TO_RAD(ft_float_read(str[i])));
	}
	return (ft_light_new(SPOT_LIGHT, l));
}

t_light		*ft_parse_direct_light(t_light *l, char **str)
{
	int		i;

	l->u.direct.dir = ft_vec3(0.0, 1.0, 1.0);
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("DIR", str[i]) || ft_rtstrequal("DIRECTION", str[i]))
			l->u.direct.dir = ft_vec3_read(str[i]);
	}
	return (ft_light_new(DISTANT_LIGHT, l));
}

t_light		*ft_parse_default_light(t_light *l, char **str)
{
	int		i;

	l->u.def.pos = ft_vec3(0.0, 1.0, 1.0);
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("POS", str[i]) || ft_rtstrequal("POSITION", str[i]))
			l->u.def.pos = ft_vec3_read(str[i]);
	}
	return (ft_light_new(DEFAULT_LIGHT, l));
}
