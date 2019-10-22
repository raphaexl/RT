/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:53:43 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 14:01:00 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void		ft_env_load_img1(t_env *e)
{
	SDL_Surface		*s;

	if (!(s = IMG_Load("data/imgs/bouton_enfonce.bmp")))
		ft_sdl_error();
	if (!(e->menu.img[0] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_sphere.png")))
		ft_sdl_error();
	if (!(e->menu.img[1] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_cone.png")))
		ft_sdl_error();
	if (!(e->menu.img[2] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_cylinder.png")))
		ft_sdl_error();
	if (!(e->menu.img[3] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	s = NULL;
}

static void		ft_env_load_img2(t_env *e)
{
	SDL_Surface		*s;

	ft_env_load_img1(e);
	if (!(s = IMG_Load("data/imgs/bouton_box.png")))
		ft_sdl_error();
	if (!(e->menu.img[4] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_plane.png")))
		ft_sdl_error();
	if (!(e->menu.img[5] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_disk.png")))
		ft_sdl_error();
	if (!(e->menu.img[6] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_torus.png")))
		ft_sdl_error();
	if (!(e->menu.img[7] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	s = NULL;
}

static void		ft_env_load_img3(t_env *e)
{
	SDL_Surface		*s;

	ft_env_load_img2(e);
	if (!(s = IMG_Load("data/imgs/bouton_cube.png")))
		ft_sdl_error();
	if (!(e->menu.img[8] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_triangle.png")))
		ft_sdl_error();
	if (!(e->menu.img[9] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_parallelogram.png")))
		ft_sdl_error();
	if (!(e->menu.img[10] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_ring.png")))
		ft_sdl_error();
	if (!(e->menu.img[11] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	s = NULL;
}

static void		ft_env_load_img4(t_env *e)
{
	SDL_Surface		*s;

	ft_env_load_img3(e);
	if (!(s = IMG_Load("data/imgs/bouton_ellipsoid.png")))
		ft_sdl_error();
	if (!(e->menu.img[12] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_paraboloid.png")))
		ft_sdl_error();
	if (!(e->menu.img[13] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_mesh.png")))
		ft_sdl_error();
	if (!(e->menu.img[14] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_delete.png")))
		ft_sdl_error();
	if (!(e->menu.img[15] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	s = NULL;
}

void			ft_env_load_img5(t_env *e)
{
	SDL_Surface		*s;

	ft_env_load_img4(e);
	if (!(s = IMG_Load("data/imgs/bouton_edit.png")))
		ft_sdl_error();
	if (!(e->menu.img[16] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_raytrace.png")))
		ft_sdl_error();
	if (!(e->menu.img[17] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_video.png")))
		ft_sdl_error();
	if (!(e->menu.img[18] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	if (!(s = IMG_Load("data/imgs/bouton_ppm.png")))
		ft_sdl_error();
	if (!(e->menu.img[19] = SDL_CreateTextureFromSurface(e->ptr.renderer, s)))
		ft_sdl_error();
	SDL_FreeSurface(s);
	s = NULL;
}
