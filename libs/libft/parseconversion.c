/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseconversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:10:21 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:10:40 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_parse_flags(char *str, t_flag *flag)
{
	while (ft_strchr("#0-+ ", *str))
	{
		if (*str == '#')
			flag->hash = 1;
		else if (*str == '0')
			flag->zero = 1;
		else if (*str == '-')
			flag->minus = 1;
		else if (*str == '+')
			flag->plus = 1;
		else if (*str == ' ')
			flag->space = 1;
		else if (*str == '\0')
			break ;
		else
			ft_printf_error("Parse error !.");
		str++;
	}
	if (!str)
		ft_printf_error("Invalid format. (After Flags)");
	return (str);
}

static char	*ft_parse_min_width(char *str, t_conv *conv)
{
	conv->min_width = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str == '*')
	{
		conv->width_star_set = 1;
		str++;
		conv->min_width = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	if (!str)
		ft_printf_error("Invalid format. (After Min Width)");
	return (str);
}

static char	*ft_parse_precision(char *str, t_conv *conv)
{
	if (*str != '.')
		return (str);
	str++;
	conv->precision = ft_atoi(str);
	conv->prec_set = 1;
	while (ft_isdigit(*str))
		str++;
	if (*str == '*')
	{
		str++;
		conv->prec_star_set = 1;
		conv->precision = ft_atoi(str);
		while (ft_isdigit(*str))
			str++;
	}
	if (!str)
		ft_printf_error("Invalid format. (After Precision)");
	return (str);
}

static char	*ft_parse_modifier(char *str, t_conv *conv)
{
	if (!ft_strchr("hljzL", *str))
		return (str);
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		conv->modif = HH;
		return (str + 2);
	}
	if (ft_strncmp(str, "ll", 2) == 0)
	{
		conv->modif = LL;
		return (str + 2);
	}
	else if (*str == 'h')
		conv->modif = H;
	else if (*str == 'l')
		conv->modif = L;
	else if (*str == 'L')
		conv->modif = LF;
	else if (*str == 'j')
		conv->modif = J;
	else if (*str == 'z')
		conv->modif = Z;
	return (str + 1);
}

char		*ft_parse_conversion(char *str, t_conv *conv)
{
	str = ft_parse_flags(str, conv->flag);
	if (ft_strchr(",;:_", *str))
	{
		conv->sep = *str;
		str++;
	}
	if (!str)
		ft_printf_error("Invalid format. (After Seperator)");
	str = ft_parse_min_width(str, conv);
	str = ft_parse_precision(str, conv);
	str = ft_parse_modifier(str, conv);
	if (!str)
		ft_printf_error("Invalid format. (After Modifier)");
	conv->type = *str;
	return (str + 1);
}
