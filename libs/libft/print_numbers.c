/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:11:19 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:11:27 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_init_alias(t_conv *conv, long *max, long *i)
{
	char			*str;

	*max = conv->precision + 20;
	*i = *max;
	str = (char *)malloc((*max) + 1);
	str[(*i)] = '\0';
	return (str);
}

void		ft_print_u(t_conv *conv, uintmax_t num)
{
	char			*str;
	long			max;
	long			i;

	max = conv->precision + 20;
	str = (char *)malloc(max + 1);
	i = max;
	str[i] = '\0';
	if (num > 0 || !conv->prec_set)
		str[--i] = '0' + (num % 10);
	while ((num /= 10) > 0)
		str[--i] = '0' + (num % 10);
	if (conv->precision > max - i)
		conv->flag->zero = 0;
	while (conv->precision > max - i)
		str[--i] = '0';
	if (conv->flag->zero && conv->sign && ft_tally_print(&(conv->sign), 1))
		conv->min_width--;
	else if (conv->sign)
		str[--i] = conv->sign;
	ft_print_num_spaced(conv, str + i);
	if (str)
		free(str);
	str = NULL;
}

void		ft_print_o(t_conv *conv, uintmax_t num)
{
	char			*str;
	long			max;
	long			i;

	max = conv->precision + 20;
	i = max;
	str = (char *)malloc(max + 1);
	str[i] = '\0';
	if (num > 0 || !conv->prec_set)
		str[--i] = '0' + (num % 8);
	while ((num /= 8) > 0)
		str[--i] = '0' + (num % 8);
	if (conv->flag->hash && str[i] != '0')
		str[--i] = '0';
	while (conv->precision > max - i)
		str[--i] = '0';
	ft_print_num_spaced(conv, str + i);
	if (str)
		free(str);
	str = NULL;
}

void		ft_print_x(t_conv *conv, uintmax_t num)
{
	char			*str;
	long			ma;
	long			i;

	str = ft_init_alias(conv, &ma, &i);
	if (num > 0 || !conv->prec_set)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16))
			: ('0' + (num % 16) + 39));
	while ((num /= 16) > 0)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16))
			: ('0' + (num % 16) + 39));
	while (conv->precision > (ma - i))
		str[--i] = '0';
	if (conv->flag->zero && ((conv->flag->hash && i < ma && str[ma - 1] != '0')
		|| conv->type == 'p') && ft_tally_print("0x", 2))
		conv->min_width -= 2;
	else if ((conv->flag->hash && i < ma && str[ma - 1] != '0')
		|| conv->type == 'p')
	{
		str[--i] = 'x';
		str[--i] = '0';
	}
	ft_print_num_spaced(conv, str + i);
	free(str);
	str = NULL;
}

void		ft_print_x_caps(t_conv *conv, uintmax_t num)
{
	char			*str;
	long			ma;
	long			i;

	str = ft_init_alias(conv, &ma, &i);
	if (num > 0 || !conv->prec_set)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16))
			: ('0' + (num % 16) + 7));
	while ((num /= 16) > 0)
		str[--i] = (((num % 16) <= 9) ? ('0' + (num % 16))
			: ('0' + (num % 16) + 7));
	while (conv->precision > (ma - i))
		str[--i] = '0';
	if (conv->flag->zero && ((conv->flag->hash && i < ma && str[ma - 1] != '0'))
			&& ft_tally_print("0x", 2))
		conv->min_width -= 2;
	else if ((conv->flag->hash && i < ma && str[ma - 1] != '0'))
	{
		str[--i] = 'X';
		str[--i] = '0';
	}
	ft_print_num_spaced(conv, str + i);
	if (str)
		free(str);
	str = NULL;
}
