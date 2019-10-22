/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:53:29 by ebatchas          #+#    #+#             */
/*   Updated: 2019/09/19 18:46:38 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/rt.h"

t_light		*ft_light_new(t_ltype type, t_light *l)
{
	t_light	*new;

	if ((new = malloc(sizeof(*new))))
	{
		new->type = type;
		new->id = 0;
		new->u = l->u;
		new->diffuse = l->diffuse;
		new->next = NULL;
	}
	else
		ft_error();
	return (new);
}

void		ft_light_push_back(t_light **lst, t_light *new)
{
	t_light	*p;
	int		id;

	id = 1;
	if (!lst || !new)
		return ;
	else if (!*lst)
	{
		new->id = 0;
		*lst = new;
	}
	else
	{
		p = *lst;
		while (p->next && ++id)
			p = p->next;
		new->id = id;
		p->next = new;
	}
}

void		ft_light_add_back(t_light **lst, t_ltype type)
{
	t_light		new;

	new.diffuse = ft_col3(1.0, 1.0, 1.0);
	new.u.direct.dir = ft_vec3(0.0, 0.0, 0.0);
	new.u.def.pos = ft_vec3(0.0, 0.0, 0.0);
	if (type == DEFAULT_LIGHT)
		ft_light_push_back(lst, ft_light_new(type, &new));
	else if (type == DISTANT_LIGHT)
		ft_light_push_back(lst, ft_light_new(type, &new));
}

void		ft_light_remove(t_light **s, int id)
{
	t_light		*p;
	t_light		*q;

	if (!s || !*s)
		return ;
	p = *s;
	if (p && p->id == id)
	{
		*s = (*s)->next;
		free(p);
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
		free(q);
		return ;
	}
}

void		ft_light_clean(t_light **lst)
{
	t_light	*p;

	if (!lst || !*lst)
		return ;
	p = *lst;
	while (p)
	{
		(*lst) = (*lst)->next;
		free(p);
		p = (*lst);
	}
}
