/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 04:34:49 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 13:42:45 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_light		*ft_parse_process_light(char **str, t_ltype type)
{
	int		i;
	t_light l;

	ft_bzero(&l, sizeof(t_light));
	l.diffuse = (t_col3){1.0, 0.0, 0.0};
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("DIFFUSE", str[i]) || ft_rtstrequal("DIFF", str[i]))
			l.diffuse = ft_col3_read(str[i]);
		else if (ft_rtstrequal("INTENSITY", str[i]) ||
				ft_rtstrequal("COLOR", str[i]))
			l.diffuse = ft_col3_read(str[i]);
		else if (ft_rtstrequal("COL", str[i]))
			l.diffuse = ft_col3_read(str[i]);
	}
	if (type == DEFAULT_LIGHT)
		return (ft_parse_default_light(&l, str));
	else if (type == DISTANT_LIGHT)
		return (ft_parse_direct_light(&l, str));
	else if (type == POINT_LIGHT)
		return (ft_parse_default_light(&l, str));
	else if (type == SPOT_LIGHT)
		return (ft_parse_spot_light(&l, str));
	return (NULL);
}

t_ltype		ft_parsing_light(char **str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("DEFAULT", str[i]))
			return (DEFAULT_LIGHT);
		else if (ft_rtstrequal("DISTANT", str[i]))
			return (DISTANT_LIGHT);
		else if (ft_rtstrequal("POINT", str[i]))
			return (POINT_LIGHT);
		else if (ft_rtstrequal("SPOT", str[i]))
			return (SPOT_LIGHT);
	}
	return (DEFAULT_LIGHT);
}

int			ft_parse_process_lights(t_scene *s, char *str)
{
	t_rtsplit		split;

	if (ft_strstr(ft_strsub(str, 0, LIGHT_NAME), "LIGHT"))
	{
		split = ft_parse_process_split(str, '{', '}', '\n');
		if (!split.tab)
			ft_parsing_error(LIGHT_DESCRIPTION);
		ft_light_push_back(&s->light,
				ft_parse_process_light(split.tab, ft_parsing_light(split.tab)));
		ft_split_free(&split.tab);
		return (split.max);
	}
	return (0);
}
