/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:26:22 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 19:30:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static t_otype	ft_parsing_object2(char *str)
{
	if (ft_strstr((str), ("PARABOLOID")))
		return (PARABOLOID);
	else if (ft_strstr((str), ("ELLIPSOID")))
		return (ELLIPSOID);
	else if (ft_strstr((str), ("RING")))
		return (RING);
	else if (ft_strstr((str), ("MESH")))
		return (MESH);
	return (NO_OBJECT);
}

t_otype			ft_parsing_object(char *str)
{
	if (ft_strstr((str), ("SPHERE")))
		return (SPHERE);
	else if (ft_strstr((str), ("CONE")))
		return (CONE);
	else if (ft_strstr((str), ("CYLINDER")))
		return (CYLINDER);
	else if (ft_strstr((str), ("BOX")))
		return (BOX);
	else if (ft_strstr((str), ("PLANE")))
		return (PLANE);
	else if (ft_strstr((str), ("DISK")))
		return (DISK);
	else if (ft_strstr((str), ("TORUS")))
		return (TORUS);
	else if (ft_strstr((str), ("CUBE")))
		return (CUBE);
	else if (ft_strstr((str), ("TRIANGLE")))
		return (TRIANGLE);
	else if (ft_strstr((str), ("PARALLELOGRAM")))
		return (PARALLELOGRAM);
	return (ft_parsing_object2(str));
}
