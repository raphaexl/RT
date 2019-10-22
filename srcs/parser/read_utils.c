/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 00:14:08 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/22 19:54:45 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static int	ft_read(int fd, t_aux_read_file *a)
{
	while (1)
	{
		if (a->used + READALL_CHUNK + 1 > a->size)
		{
			if ((a->size = a->used + READALL_CHUNK + 1) <= a->used)
			{
				free(a->data);
				return (READALL_TOOMUCH);
			}
			if (!(a->temp = realloc(a->data, a->size)))
			{
				free(a->data);
				return (READALL_NOMEM);
			}
			a->data = a->temp;
		}
		if (!(a->n = read(fd, a->data + a->used, READALL_CHUNK)))
			break ;
		a->used += a->n;
	}
	return (0);
}

int			ft_read_all(int fd, char **dataptr, size_t *sizeptr)
{
	t_aux_read_file a;
	int				ret;

	ret = READALL_OK;
	ft_bzero(&a, sizeof(t_aux_read_file));
	if (fd < 0 || fd > 4096 || dataptr == NULL || sizeptr == NULL)
		return (READALL_INVALID);
	if ((ret = ft_read(fd, &a)) < 0)
		return (ret);
	a.temp = realloc(a.data, a.used + 1);
	if (a.temp == NULL)
	{
		free(a.data);
		return (READALL_NOMEM);
	}
	a.data = a.temp;
	a.data[a.used] = '\0';
	*dataptr = a.data;
	*sizeptr = a.used;
	return (READALL_OK);
}
