#include "fdf.h"

t_data	*rotate_z_axis(t_data *origin, double rad)
{
	size_t	i;
	t_data	*new;
	t_vector	*vec;

	new = create_data();
	ft_memcpy(new, origin, sizeof(t_data));
	vec = new->vec;
	i = 0;
	while (i < new->size)
	{
		vec[i].x = vec[i].x * cos(rad) + vec[i].y * sin(rad);
		vec[i].y = vec[i].y * sin(rad) - vec[i].x * sin(rad);
		i++;
	}
	return (new);
}

void	rotate_x_axis(t_data *origin, double rad)
{
	size_t	i;
	t_data	*new;
	t_vector	*vec;

	vec = origin->vec;
	i = 0;
	while (i < origin->size)
	{
		vec[i].y = cos(rad) * vec[i].y + sin(rad) * vec[i].z;
		vec[i].z = -sin(rad) * vec[i].y + cos(rad) * vec[i].z;
		i++;
	}
}

t_data	*make_iso_vector(t_data *origin_data)
{
	t_data	*iso_data;

	iso_data = rotate_z_axis(origin_data, M_PI_4);
	rotate_x_axis(iso_data, M_PI_4);
	return (iso_data);
}
