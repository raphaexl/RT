/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:11:14 by ebatchas          #+#    #+#             */
/*   Updated: 2019/10/12 18:26:02 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

static void	ft_object_free(t_object **p)
{
	if (!p || !*p)
		return ;
	if ((*p)->material.texture)
		free((*p)->material.texture);
	(*p)->type == MESH ? free((*p)->e.mesh.triangles) : 1;
	free(*p);
	p = NULL;
}

void		ft_object_remove(t_object **s, int id)
{
	t_object	*p;
	t_object	*q;

	if (!s || !*s)
		return ;
	p = *s;
	if (p && p->id == id)
	{
		*s = (*s)->next;
		ft_object_free(&p);
		return ;
	}
	q = (*s)->next;
	while (q && q->id != id)
	{
		p = q;
		q = q->next;
	}
	if (q && q->id == id)
	{
		p->next = q->next;
		ft_object_free(&q);
		return ;
	}
}

void		ft_object_clean(t_object **lst)
{
	t_object	*p;

	if (!lst || !*lst)
		return ;
	p = *lst;
	while (p)
	{
		(*lst) = (*lst)->next;
		ft_object_free(&p);
		p = (*lst);
	}
}
