#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# define GR 0x0000FF00
# define RED 0x00FF0000
# define MLX_X_SIZE 1600
# define MLX_Y_SIZE 1200
# define IMG_X_SIZE 800
# define IMG_Y_SIZE 600


typedef struct s_map_len
{
	int	x;
	int	y;
	int	z;
}				t_map_len;


typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct	s_map
{
	size_t		size;
	t_map_len	*map;
	t_vector	*vec;
}				t_map;

typedef struct s_img {
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_img;

typedef struct	s_delta
{
	double	x;
	double	y;
}				t_delta;

typedef struct	s_crd
{
	double	x;
	double	y;
	double	z;
}				t_crd;//coordinate

typedef struct	s_unit
{
	t_crd	u;
	t_crd	v;
	t_crd	n;
}				t_unit;//unit vector


int		get_next_line(int fd, char **line);
//ft_utils
void	error(const char *str);
void	merror(void *ptr);
int		find_max(int a, int b, int c);

//parse
int		check_input(int ac, char **av);
void	expand_arr(int ***arr, t_map_len *map);
void	fill_value(int **arr, char **buf, t_map_len *map);
int		**save_vector(int fd, t_map_len *map);
t_vector	*make_vector(int **arr, t_map_len *map);
t_map *parsing_map(int ac, char **av);
//parse_utils
void	clear_arr(int **arr, t_map_len *map);
void	clear_str(char **buf, char **line);
t_map	*create_data(void);
//vector
void	scail_vector(t_crd *crd, t_crd scail);
double	distance_crd(t_crd c1, t_crd c2);
void	rotate_unit_vector(t_unit new, t_crd *data);
t_crd	cross_vector(t_crd v1, t_crd v2);


//iso_vector
void	rotate_z_axis(t_map *origin, double rad);
void	rotate_x_axis(t_map *origin, double rad);
void	make_iso_vector(t_map *origin_data);
//print_img
void	multiplied_pixel(t_map *data);

#endif
