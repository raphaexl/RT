/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 11:41:00 by ebatchas          #+#    #+#             */
/*   Updated: 2019/07/31 11:45:05 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prev_len, size_t next_len)
{
	void	*new_ptr;

	if (next_len <= 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (malloc(next_len));
	else if (next_len <= prev_len)
		return (ptr);
	else
	{
		if (!(new_ptr = malloc(next_len)))
			return (NULL);
		ft_memcpy(new_ptr, ptr, prev_len);
		free(ptr);
	}
	return (new_ptr);
}
