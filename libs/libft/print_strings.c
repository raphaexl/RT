/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:11:35 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:12:32 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_print_chars(t_conv *conv, char *str, int size)
{
	if (conv->prec_set && conv->type == 's')
		size = (size < conv->precision ? size : conv->precision);
	if (conv->flag->minus)
	{
		ft_tally_print(str, size);
		ft_print_spacing(size, conv->min_width, ' ');
		return ;
	}
	if (conv->flag->zero)
		ft_print_spacing(size, conv->min_width, '0');
	else
		ft_print_spacing(size, conv->min_width, ' ');
	ft_tally_print(str, size);
}

void			ft_print_char(t_conv *conv, char c)
{
	ft_print_chars(conv, &c, 1);
}

void			ft_print_str(t_conv *conv, char *str)
{
	if (!str)
		str = "(null)";
	ft_print_chars(conv, str, ft_strlen(str));
}
