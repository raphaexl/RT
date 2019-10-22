/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:54:42 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/24 11:43:04 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void		ft_parse_file(t_scene *s, int fd)
{
	char		*line;
	int			i;
	int			index;
	size_t		len;

	i = -1;
	len = 0;
	ft_read_all(fd, &line, &len);
	line = ft_strcapitalize(line);
	while (line[++i])
	{
		if ((index = ft_parse_process_objects(s, &line[i])))
			i += index;
		else if ((index = ft_parse_process_lights(s, &line[i])))
			i += index;
		else if ((index = ft_parse_process_camera(s, &line[i])))
			i += index;
		else if ((index = ft_parse_process_background(s, &line[i])))
			i += index;
		else if ((index = ft_parse_process_scene(s, &line[i])))
			i += index;
		else if ((index = ft_parse_process_envmap(s, &line[i])))
			i += index;
	}
	free(line);
}
