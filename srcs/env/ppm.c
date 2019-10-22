/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:52:04 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/13 14:26:26 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rt.h"

static void		ft_ppm_format(int w, int h, int fd)
{
	ft_putstr_fd("P3\n", fd);
	ft_putnbr_fd(w, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(h, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(255, fd);
	ft_putchar_fd('\n', fd);
}

static void		ft_save_screenshot(Uint32 *pixels, int *var, int w, int h)
{
	unsigned char	*buff;
	unsigned char	ppm;

	var[1] = -1;
	while (++var[1] < h)
	{
		var[2] = -1;
		while (++var[2] < w)
		{
			var[3] = 3;
			buff = (unsigned char *)&pixels[var[1] * w + var[2]];
			while (--var[3] >= 0)
			{
				ppm = buff[var[3]];
				ft_putnbr_fd(ppm, var[0]);
				ft_putchar_fd(' ', var[0]);
			}
		}
		ft_putchar_fd('\n', var[0]);
	}
	ft_putchar_fd('\n', var[0]);
}

void			ft_save_ppm_pixels(Uint32 *pixels, int w, int h)
{
	int				var[4];

	var[0] = open("out.ppm", O_RDWR | O_CREAT, 0777);
	ft_ppm_format(w, h, var[0]);
	ft_save_screenshot(pixels, var, w, h);
	ft_printf("A File out.ppm has been saved to current working directory\n");
}
