#include "fdf.h"

void	camera_eye(t_crd *eye, t_map *data)
{
	int	max;

	max = find_max(data->map->x, data->map->y, data->map->z);
	max++;
	eye->x = max;
	eye->y = max;
	eye->z = max;
}

t_crd	make_u_vector(t_crd eye)
{
	t_crd	origin;
	t_crd	size;

	ft_memset(&origin, 0, sizeof(t_crd));
	size.x = 1 / distance_crd(origin, eye);
	size.y = size.x;
	size.z = size.x;
	scail_vector(&eye, size);
	return (eye);
}

t_crd	make_v_vector(t_crd eye)
{
	t_crd	crd;
	t_crd	up;
	t_crd	size;

	up.x = -1;
	up.y = -1;
	up.z = 2 * sqrt(2);
	size.x = 1 / distance_crd(up, eye);
	size.y = size.x;
	size.z = size.x;
	scail_vector(&eye, size);
	crd = cross_vector(up, eye);
	scail_vector(&crd, size);
	return (crd);
}

void	make_n_vector(t_unit *unit)
{
	unit->n = cross_vector(unit->n, unit->u);
}

void	make_camera_unit(t_crd eye, t_unit *unit)
{
	t_crd	*n;

	unit->u = make_u_vector(eye);
	unit->v = make_v_vector(eye);
	make_n_vector(unit);
}

void	make_iso_vector(t_map *origin_data)
{
	t_crd	eye;
	t_unit	unit;
	/*
	1. 카메라 eye포인트 찾기
	camera_eye(&eye, origin_data);
	2. eye와 at(원점)으로 단위벡터 만들기
	camera_unit(eye, &unit);
	3. eye만큼 data translation
	4. unit벡터만큼 rotate
	change_view(eye, unit, origin_data);
	*/
}
