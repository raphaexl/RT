/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:55:01 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 13:43:04 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_vec3		ft_vec3_read(char *line)
{
	char	**tab;
	t_vec3	vect;

	vect.x = 0;
	if ((tab = ft_strsplit(line, ' ')) && ft_tab_len(tab) < 4)
	{
		ft_putendl(line);
		ft_print_error("vector error");
	}
	if (ft_isdigit(*tab[1]))
	{
		vect.x = ft_atof(tab[1]);
		vect.y = ft_atof(tab[2]);
		vect.z = ft_atof(tab[3]);
	}
	else
	{
		vect.x = ft_atof(tab[2]);
		vect.y = ft_atof(tab[3]);
		vect.z = ft_atof(tab[4]);
	}
	ft_split_free(&tab);
	return (vect);
}

t_col3		ft_col3_read(char *line)
{
	t_col3		c;
	char		**tab;

	c.red = 0;
	if ((tab = ft_strsplit(line, ' ')) && ft_tab_len(tab) < 4)
		ft_print_error("color error");
	if (ft_isdigit(*tab[1]))
	{
		c.red = ft_atof(tab[1]);
		c.green = ft_atof(tab[2]);
		c.blue = ft_atof(tab[3]);
	}
	else
	{
		c.red = ft_atof(tab[2]);
		c.green = ft_atof(tab[3]);
		c.blue = ft_atof(tab[4]);
	}
	ft_split_free(&tab);
	return (c);
}

float		ft_float_read(char *line)
{
	float		value;
	char		**tab;

	value = .0;
	if ((tab = ft_strsplit(line, ' ')) && ft_tab_len(tab) < 2)
		ft_print_error("expected floating value");
	if (ft_isdigit(*tab[1]))
		value = ft_atof(tab[1]);
	else
		value = ft_atof(tab[2]);
	ft_split_free(&tab);
	return (value);
}

char		*ft_str_read(char *line)
{
	char	**tab;
	char	*str;

	if (!(tab = ft_strsplit(line, ' ')) || ft_tab_len(tab) < 2)
		ft_print_error("expected a string :)");
	if (ft_isalpha(*tab[1]))
		str = ft_strdup(tab[1]);
	else
		str = ft_strdup(tab[2]);
	ft_split_free(&tab);
	return (str);
}

int			ft_bool_read(char *line)
{
	char	**tab;
	int		ret;

	if (!(tab = ft_strsplit(line, ' ')) || ft_tab_len(tab) < 2)
		ft_print_error("expected a boolean :)");
	if (ft_isalpha(*tab[1]))
		ret = !ft_strcmp(tab[1], "TRUE");
	else
		ret = !ft_strcmp(tab[2], "TRUE");
	ft_split_free(&tab);
	return (ret);
}
