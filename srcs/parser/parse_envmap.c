/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_envmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 09:01:49 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/24 16:37:06 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

char	**ft_default_env_map(void)
{
	char	**m;

	m = ft_memalloc(sizeof(char *) * 7);
	m[0] = ft_strdup("data/envmaps/cube/massal/alpup.tga");
	m[1] = ft_strdup("data/envmaps/cube/massal/alpdown.tga");
	m[2] = ft_strdup("data/envmaps/cube/massal/alpright.tga");
	m[3] = ft_strdup("data/envmaps/cube/massal/alpleft.tga");
	m[4] = ft_strdup("data/envmaps/cube/massal/alpforward.tga");
	m[5] = ft_strdup("data/envmaps/cube/massal/alpback.tga");
	m[6] = NULL;
	return (m);
}

int		ft_parsing_envmap_1(char *m[7], char *str)
{
	if (ft_rtstrequal("UP", ft_rtstrsub(str, 0, 2)))
		m[0] = ft_strlwr(ft_str_read(str));
	else if (ft_rtstrequal("DOWN", ft_rtstrsub(str, 0, 4)))
		m[1] = ft_strlwr(ft_str_read(str));
	else if (ft_rtstrequal("RIGHT", ft_rtstrsub(str, 0, 5)))
		m[2] = ft_strlwr(ft_str_read(str));
	else if (ft_rtstrequal("LEFT", ft_rtstrsub(str, 0, 4)))
		m[3] = ft_strlwr(ft_str_read(str));
	else
		return (0);
	return (1);
}

void	ft_parsing_envmap(t_scene *s, char **str)
{
	int				i;
	char			**m;
	t_point			p;

	i = -1;
	p = (t_point){0, 0};
	m = ft_default_env_map();
	while (str[++i])
	{
		if (ft_parsing_envmap_1(m, str[i]))
			;
		else if (ft_rtstrequal("FORWARD", ft_rtstrsub(str[i], 0, 7)))
			m[4] = ft_strlwr(ft_str_read(str[i]));
		else if (ft_rtstrequal("BACKWARD", ft_rtstrsub(str[i], 0, 8)))
			m[5] = ft_strlwr(ft_str_read(str[i]));
		else if (ft_rtstrequal("SRGB", ft_rtstrsub(str[i], 0, 4)))
			p.x = ft_bool_read(str[i]);
		else if (ft_rtstrequal("EXPOSED", ft_rtstrsub(str[i], 0, 7)))
			p.y = ft_bool_read(str[i]);
	}
	s->cmap = ft_cubemap_init(m, p.x, p.y);
	ft_split_free(&m);
}

int		ft_parse_process_envmap(t_scene *s, char *str)
{
	t_rtsplit		split;

	if (ft_strstr(ft_strsub(str, 0, ENVMAP_NAME), "ENVMAP"))
	{
		split = ft_parse_process_split(str, '{', '}', '\n');
		if (!split.tab)
			ft_parsing_error(ENVMAP_DESCRIPTION);
		ft_parsing_envmap(s, split.tab);
		s->background = ENVMAP;
		ft_split_free(&split.tab);
		return (split.max);
	}
	return (0);
}
