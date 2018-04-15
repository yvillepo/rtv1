/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 10:40:59 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/23 08:23:12 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		read_object_plane(t_object *object, int fd)
{
	object->type = PLANE;
	object->form = ft_malloc(sizeof(t_plane));
	read_plane(object->form, fd);
}

void		read_plane(t_plane *plane, int fd)
{
	plane->normal = read_vect(fd);
	if (is_nul(plane->normal))
		exit_error("vecteur directeur null");
	plane->pos = read_vect(fd);
	plane->d = -v_scale(plane->normal, plane->pos);
}

double		inter_plane(t_plane *plane, t_line *line)
{
	double	d;

	d = v_scale(line->dir, plane->normal);
	return (-(v_scale(plane->normal, line->origin) + plane->d / d));
}
