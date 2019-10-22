/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:01:00 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:31:07 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

char	*ft_strjoin_3(char const *s1, char const *s2, char const *s3)
{
	char *res;

	if (s1 == NULL || s2 == NULL || s3 == NULL)
		return (NULL);
	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1);
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcat(res, s2);
	ft_strcat(res, s3);
	return (res);
}

void	ft_save_bmp_imgs(Uint32 *pixels, int w, int h, char *file_name)
{
	SDL_Surface		*s;
	int				x;
	int				y;

	if (!(s = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0)))
		ft_sdl_error();
	SDL_LockSurface(s);
	y = -1;
	while ((++y < h) && (x = -1))
		while (++x < w)
			ft_put_pixels(s, x, y, pixels[y * w + x]);
	SDL_UnlockSurface(s);
	if (SDL_SaveBMP(s, ft_strjoin("videos/", file_name)))
		ft_printf("SDL_SaveBMP() : %s\n", SDL_GetError());
	SDL_FreeSurface(s);
	s = NULL;
}

int		ft_save_rt_video(t_env *env)
{
	int			i;
	float		radius;
	t_camera	cam;

	i = 0;
	radius = env->s.cam.radius;
	cam = env->s.cam;
	env->s.cam.pos.y = 0.0;
	while (i <= VIDEO_SIZE && !env->in.quit)
	{
		env->s.cam.pos.x = radius * cos(DEG_TO_RAD(i));
		env->s.cam.pos.z = radius * sin(DEG_TO_RAD(i));
		env->s.cam = ft_camera_new(env->s.cam.pos, ft_vec3(0.0, 0.0, 0.0),
				cam.focal_dist, env->s.cam.fov);
		ft_draw(env);
		ft_save_bmp_imgs(env->pixels, W_W, W_H, ft_strjoin_3("img",
					ft_itoa(i / 10), ".bmp"));
		ft_printf("Rendering video %d%%\n", (i * 100) / VIDEO_SIZE);
		ft_update_event(&env->in);
		i += 10;
	}
	env->s.cam = cam;
	ft_printf("Finished saving Images for the video\n");
	return (0);
}
