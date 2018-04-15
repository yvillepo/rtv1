#include "rtv1.h"

t_vect	v_mult(t_vect *v1, t_vect *v2)
{
	t_vect	res;

	res.x = v1->x * v2->x;
	res.y = v1->y * v2->y;
	res.z = v1->z * v2->z;
	return (res);
}
