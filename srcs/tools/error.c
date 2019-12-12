/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:52:50 by ebatchas          #+#    #+#             */
/*   Updated: 2019/12/12 11:48:15 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

void	ft_print_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

void	ft_sdl_error(void)
{
	ft_putendl(SDL_GetError());
	exit(EXIT_FAILURE);
}

void	ft_error(void)
{
	ft_putendl("Usage: ./RT [(-o)] <scene.rt>");
	ft_putendl("	-o  use multithreading for fast computation");
	exit(EXIT_FAILURE);
}

void	ft_parsing_error(int error)
{
	if (error == OBJECT_DESCRIPTION)
		ft_print_error("OBJECT DESRIPTION .. DID YOU THINK ABOUT {}");
	else if (error == LIGHT_DESCRIPTION)
		ft_print_error("LIGHT DESRIPTION .. DID YOU THINK ABOUT {}");
	else if (error == CAMERA_DESCRIPTION)
		ft_print_error("CAMERA DESRIPTION .. DID YOU THINK ABOUT {}");
	else if (error == BACKGROUND_DESCRIPTION)
		ft_print_error("BACKGROUND DESRIPTION .. DID YOU THINK ABOUT {}");
	else if (error == SCENE_DESCRIPTION)
		ft_print_error("SCENE DESRIPTION .. DID YOU THINK ABOUT {}");
	else
		ft_print_error("UNKNOWN ERROR");
}
