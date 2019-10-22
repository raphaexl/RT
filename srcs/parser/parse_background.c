/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 06:58:29 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/24 16:38:16 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_parsing_background(t_scene *s, char **str)
{
	int				i;

	i = -1;
	s->bg_color = (t_col3){0.05, 0.05, 0.05};
	s->background = NO_BACKGROUND;
	while (str[++i])
	{
		if (ft_rtstrequal("COLOR", str[i]) || ft_rtstrequal("COLOR", str[i]))
			s->bg_color = ft_col3_read(str[i]);
		else if (ft_rtstrequal("ENVIRONNEMENT", str[i]) ||
				ft_rtstrequal("CUBEMAPPING", str[i]))
			s->background = ENVMAP;
		else if (ft_rtstrequal("ENVMAP", str[i]) ||
				ft_rtstrequal("MAP", str[i]))
			s->background = ENVMAP;
	}
	if (s->background == ENVMAP)
		s->cmap = ft_cubemap_init(ft_default_env_map(), 0, 0);
}

int		ft_parse_process_background(t_scene *s, char *str)
{
	t_rtsplit		split;

	if (ft_strstr(ft_strsub(str, 0, BACKGROUND_NAME), "BACKGROUND"))
	{
		split = ft_parse_process_split(str, '{', '}', '\n');
		if (!split.tab)
			ft_parsing_error(BACKGROUND_DESCRIPTION);
		ft_parsing_background(s, split.tab);
		ft_split_free(&split.tab);
		return (split.max);
	}
	return (0);
}
