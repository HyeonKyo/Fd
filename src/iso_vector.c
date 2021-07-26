#include "fdf.h"

t_data	*rotate_axis(t_data *origin, double rad)
{
	size_t	i;
	t_data	*new;
	t_vector	*vec;
	t_crd	crd;

	new = create_data();
	ft_memcpy(new, origin, sizeof(t_data));
	vec = new->vec;
	i = 0;
	while (i < new->size)
	{
		crd.x = vec[i].x -50;
		crd.y = vec[i].y -50;
		crd.z = vec[i].z -50;
		vec[i].x = crd.x * cos(rad) + crd.y * sin(rad);
		vec[i].y = cos(rad) * sin(rad) * crd.y - sin(rad) * sin(rad) * crd.x - cos(rad) * crd.z;
		vec[i].z = cos(rad) * cos(rad) * crd.y - sin(rad) * cos(rad) * crd.x + sin(rad) * crd.z;
		i++;
	}
	return (new);
}

void	translation(t_data *origin)
{
	size_t	i;
	t_vector	*vec;

	vec = origin->vec;
	i = 0;
	while (i < origin->size)
	{
		vec[i].x -= origin->map->x / 2 - 0.5;
		vec[i].y -= origin->map->y / 2 - 0.5;
		i++;
	}
}

void	retranslation(t_data *data)
{
	size_t	i;
	t_vector	*vec;
	t_map_len	*map;

	vec = data->vec;
	map = data->map;
	i = 0;
	while (i < data->size)
	{
		vec[i].x += (map->x / 2 - 0.5) * 1.5;
		vec[i].y += (map->y / 2 - 0.5) * 1.5;
		i++;
	}
}

void	rotate_z_axis(t_data *origin, double rad)
{
	size_t	i;
	t_vector	*vec;
	t_crd	crd;

	vec = origin->vec;
	i = 0;
	while (i < origin->size)
	{
		crd.x = vec[i].x;
		crd.y = vec[i].y;
		vec[i].x = crd.x * cos(rad) + crd.y * sin(rad);
		vec[i].y = crd.y * sin(rad) - crd.x * sin(rad);
		i++;
	}
}

void	rotate_x_axis(t_data *origin, double rad)
{
	size_t	i;
	t_vector	*vec;
	t_crd	crd;

	vec = origin->vec;
	i = 0;
	while (i < origin->size)
	{
		crd.y = vec[i].y;
		crd.z = vec[i].z;
		vec[i].y = cos(rad) * crd.y + sin(rad) * crd.z;
		vec[i].z = cos(rad) * crd.z - sin(rad) * crd.y;
		i++;
	}
}

void	make_iso_vector(t_data *origin_data)
{
	translation(origin_data);
	rotate_z_axis(origin_data, M_PI_4);
	rotate_x_axis(origin_data, M_PI_4);
	retranslation(origin_data);
}
