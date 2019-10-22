/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newconversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:09:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:09:18 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_flag	*ft_new_flags(void)
{
	t_flag		*new;

	if ((new = (t_flag *)malloc(sizeof(t_flag))))
		ft_bzero(new, sizeof(t_flag));
	else
		ft_printf_error("malloc error new flag !");
	return (new);
}

t_conv			*ft_new_conversion(char *str)
{
	t_conv	*new;

	if ((new = malloc(sizeof(t_conv))))
	{
		ft_bzero(new, sizeof(t_conv));
		new->start = str;
		new->flag = ft_new_flags();
		new->modif = NONE;
		new->precision = 0;
		new->prec_set = 0;
		new->prec_star_set = 0;
		new->width_star_set = 0;
	}
	else
		ft_printf_error("malloc error new flag !");
	return (new);
}

void			ft_del_conversion(t_conv *conv)
{
	free(conv->flag);
	free(conv);
}
