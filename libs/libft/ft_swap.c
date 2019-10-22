/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:12:53 by ebatchas          #+#    #+#             */
/*   Updated: 2019/06/07 16:15:06 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swap(void *const a, void *const b, size_t size)
{
	void	*temp;

	if ((temp = malloc(size)))
	{
		ft_memcpy(temp, a, size);
		ft_memcpy(a, b, size);
		ft_memcpy(b, temp, size);
		free(temp);
		temp = NULL;
	}
	else
	{
		write(1, "Error malloc\n", 13);
		exit(EXIT_FAILURE);
	}
}
