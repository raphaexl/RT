/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 09:32:44 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/21 15:53:33 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

t_col3		ft_background_image(t_scene *s, t_intersect *in, int index)
{
	(void)index;
	if (s->background == NO_BACKGROUND)
		return (s->bg_color);
	else
		return (ft_read_cubemap(s->cmap, in->ray));
}
