#include "fdf.h"
/*
의문점
1. 맵의 좌표를 vector가 아니라 crd로 표현하는게 맞는듯?
2. 벡터로 표현할 것은 단위벡터 뿐임.
*/

/*
1. 두 점을 인자로 받으면 거리 측정해주는 함수 distance double리턴
2. 각도를 주면 회전하는 함수. x, y, z축 기준
3.
*/
void	scail_vector(t_crd *crd, t_crd scail)
{
	crd->x *= scail.x;
	crd->y *= scail.y;
	crd->z *= scail.z;
}

double	distance_crd(t_crd c1, t_crd c2)
{
	t_crd	new;

	new.x = pow(c2.x - c1.x, 2);
	new.y = pow(c2.y - c1.y, 2);
	new.z = pow(c2.z - c1.z, 2);
	return (sqrt(new.x + new.y + new.z));
}

t_crd	cross_vector(t_crd v1, t_crd v2)
{
	t_crd	crd;

	crd.x = v1.y * v2.z - v1.z * v2.y;
	crd.y = v1.z * v2.x - v1.x * v2.z;
	crd.z = v1.x * v2.z - v1.y * v2.x;
	return (crd);
}

void	rotate_unit_vector(t_unit new, t_crd *data)
{
	t_crd	tmp;

	tmp.x = data->x;
	tmp.y = data->y;
	tmp.z = data->z;

	data->x = tmp.x * new.u.x + tmp.y * new.u.y + tmp.z * new.u.z;
	data->y = tmp.x * new.v.x + tmp.y * new.v.y + tmp.z * new.v.z;
	data->z = tmp.x * new.n.x + tmp.y * new.n.y + tmp.z * new.n.z;
}
