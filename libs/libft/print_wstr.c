/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:14:09 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:14:27 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_wchars(t_conv *conv, wchar_t *wstr, int *size)
{
	int		i;
	int		add;
	int		total;

	i = 0;
	add = 0;
	total = 0;
	while (i < *size)
	{
		if (wstr[i] <= 0x7F)
			add = 1;
		else if (wstr[i] <= 0x7FF)
			add = 2;
		else if (wstr[i] <= 0xFFFF)
			add = 3;
		else if (wstr[i] <= 0x10FFFF)
			add = 4;
		if (conv->prec_set && conv->type == 's'
			&& (total + add) > conv->precision)
			break ;
		total += add;
		i++;
	}
	*size = i;
	return (total);
}

static void		ft_print_wchars(t_conv *conv, wchar_t *wstr, int size)
{
	int		i;
	int		total;

	total = ft_count_wchars(conv, wstr, &size);
	if (!(conv->flag->minus) && conv->flag->zero)
		ft_print_spacing(total, conv->min_width, '0');
	else if (!(conv->flag->minus))
		ft_print_spacing(total, conv->min_width, ' ');
	i = 0;
	while (i < size)
	{
		ft_print_wint(wstr[i]);
		i++;
	}
	if (conv->flag->minus)
		ft_print_spacing(total, conv->min_width, ' ');
}

void			ft_print_wchar(t_conv *conv, wint_t wint)
{
	wchar_t	wchar;

	if (wint > 0x10FFFF)
		ft_printf_error("Invalid wide char. (print_wchar)");
	wchar = (wchar_t)wint;
	ft_print_wchars(conv, &wchar, 1);
}

static size_t	ft_wstrlen(wchar_t *wstr)
{
	wchar_t	*temp;

	temp = wstr;
	while (*temp != L'\0')
		temp++;
	return (temp - wstr);
}

void			ft_print_wstr(t_conv *conv, wchar_t *wstr)
{
	if (!wstr)
		ft_print_str(conv, NULL);
	else
		ft_print_wchars(conv, wstr, ft_wstrlen(wstr));
}
