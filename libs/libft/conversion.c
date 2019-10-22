/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 22:10:04 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/17 22:10:14 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_get_conv_signed(t_conv *conv, va_list ap)
{
	if (conv->modif == HH)
		return ((char)va_arg(ap, int));
	if (conv->modif == H)
		return ((short)va_arg(ap, int));
	if (conv->modif == L)
		return (va_arg(ap, long));
	if (conv->modif == LL)
		return (va_arg(ap, long long));
	if (conv->modif == J)
		return (va_arg(ap, intmax_t));
	if (conv->modif == Z)
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

uintmax_t	ft_get_conv_unsigned(t_conv *conv, va_list ap)
{
	if (conv->modif == HH)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (conv->modif == H)
		return ((unsigned short)va_arg(ap, unsigned int));
	if (conv->modif == L)
		return (va_arg(ap, unsigned long));
	if (conv->modif == LL)
		return (va_arg(ap, unsigned long long));
	if (conv->modif == J)
		return (va_arg(ap, uintmax_t));
	if (conv->modif == Z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}
