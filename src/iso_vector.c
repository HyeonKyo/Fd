#include "fdf.h"

void	adjust_z(t_map *data)
{
	size_t	i;
	t_crd	scail;
	/*
	1. eye만큼 translation
	2. unit벡터 이용한 rotation
	*/
	scail.x = 1;
	scail.y = 1;
	scail.z = 0.1;
	i = 0;
	while (i < data->size)
	{
		scail_vector(&(data->crd[i]), scail);
		i++;
	}
}

void	camera_eye(t_crd *eye, t_map *data)
{
	t_map_len	*map;
	int	max;

	map = data->map;
	max = find_max(map->x, map->y, map->z);
	max++;
	eye->x = (double)max;
	eye->y = (double)max;
	eye->z = (double)max;
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

void	translate_first_quadrant(t_map *data)
{
	t_crd	trans;
	size_t	i;

	trans.x = data->crd[0].x;
	trans.y = data->crd[data->map->x - 1].y;
	trans.z = 0.0;
	i = 0;
	while (i < data->size)
	{
		translation_vector(&(data->crd[i]), trans);
		i++;
	}
}

void	change_view_to_camera(t_crd eye, t_unit unit, t_map *data)
{
	size_t	i;
	t_crd	scail;
	/*
	1. eye만큼 translation
	2. unit벡터 이용한 rotation
	*/
	scail.x = 1;
	scail.y = 1;
	scail.z = 0.15;
	i = 0;
	while (i < data->size)
	{
		scail_vector(&(data->crd[i]), scail);
		translation_vector(&(data->crd[i]), eye);
		rotate_unit_vector(unit, &(data->crd[i]));
		i++;
	}
}

void	make_iso_vector(t_map *data)
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
	change_view_to_camera(eye, unit, origin_data);
	*/
	//adjust_z(data);
	camera_eye(&eye, data);
	make_camera_unit(eye, &unit);
	change_view_to_camera(eye, unit, data);
	translate_first_quadrant(data);
}
