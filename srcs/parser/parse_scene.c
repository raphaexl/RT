/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 05:21:52 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 13:22:44 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_ftype	ft_parse_filter_type(char *str)
{
	if (ft_rtstrequal("GAUSSIAN_BLUR", str))
		return (GAUSSIAN_BLUR);
	else if (ft_rtstrequal("MOTION_BLUR", str))
		return (MOTION_BLUR);
	else if (ft_rtstrequal("SHARPEN", str))
		return (SHARPEN);
	else if (ft_rtstrequal("EMBOSS", str))
		return (EMBOSS);
	else if (ft_rtstrequal("SOBEL", str))
		return (SOBEL);
	else if (ft_rtstrequal("GREY", str))
		return (GREY);
	else if (ft_rtstrequal("NEGATIVE", str))
		return (NEGATIVE);
	else if (ft_rtstrequal("SEPIA", str))
		return (SEPIA);
	return (NO_FILTER);
}

void	ft_parsed_scene(t_scene *s, char **str)
{
	int				i;

	s->filter = NO_FILTER;
	i = -1;
	while (str[++i])
	{
		if (ft_rtstrequal("FILTER", str[i]))
			s->filter = ft_parse_filter_type(str[i]);
		else if (ft_rtstrequal("AMBIENT", str[i]))
			s->ambiant = ft_col3_read(str[i]);
		else if (ft_rtstrequal("SAMPLES", str[i]) ||
				ft_rtstrequal("ANTIALISING", str[i]))
			s->nb_samples = ft_clamp(ft_float_read(str[i]), 1.0, 100.0);
	}
}

int		ft_parse_process_scene(t_scene *s, char *str)
{
	t_rtsplit		split;

	if (ft_strstr(ft_strsub(str, 0, SCENE_NAME), "SCENE"))
	{
		split = ft_parse_process_split(str, '{', '}', '\n');
		if (!split.tab)
			ft_parsing_error(SCENE_DESCRIPTION);
		ft_parsed_scene(s, split.tab);
		ft_split_free(&split.tab);
		return (split.max);
	}
	return (0);
}
