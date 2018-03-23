/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvillepo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:28:48 by yvillepo          #+#    #+#             */
/*   Updated: 2018/03/20 11:30:58 by yvillepo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		read_cone(t_cone *cone, int fd)
{
	char	*line;

	cone->dir = read_vect(fd);
	v_unit(cone->dir);
	cone->pos = read_vect(fd);
	if (!get_next_line(fd, &line))
		exit_error("format input");
	cone->a = deg_to_rad(ft_atof(line));
	free(line);
}

void		read_object_cone(t_object *object, int fd)
{
	object->type = CONE;
	object->form = ft_malloc(sizeof(t_cone));
	read_cone(object->form, fd);
}

double		inter_cone(t_cone *cone, t_line *l)
{
	t_vect	*diff;
	t_vect	d2;
	double	tan2;

	diff = v_sub(l->origin, cone->pos);
	tan2 = pow(tan(cone->a), 2);
	d2.x = v_mult(l->dir, l->dir) - (1 + tan2) *
		pow(v_mult(l->dir, cone->dir), 2);
	d2.y = 2 * (v_mult(l->dir, diff) - (1 + tan2) *
			v_mult(l->dir, cone->dir) * v_mult(diff, cone->dir));
	d2.z = v_mult(diff, diff) - (1 + tan2) * pow(v_mult(diff, cone->dir), 2);
	free(diff);
	return (solv_2nd(d2.x, d2.y, d2.z));
}

void		print_cone(t_cone *cone)
{
	printf("cone :\ndir : %f %f %f\npositon : %f %f %f\nR = %f\n",
			cone->dir->x, cone->dir->y,
			cone->dir->z, cone->pos->x, cone->pos->y, cone->pos->z, cone->a);
}
