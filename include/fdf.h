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
}				t_map_len;


typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

typedef struct	s_data
{
	size_t		size;
	t_map_len	*map;
	t_vector	*vec;
}				t_data;

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

int		get_next_line(int fd, char **line);
//ft_utils
void	error(const char *str);
void	merror(void *ptr);

//parse
int		check_input(int ac, char **av);
void	expand_arr(int ***arr, t_map_len *map);
void	fill_value(int **arr, char **buf, t_map_len *map);
int		**save_vector(int fd, t_map_len *map);
t_vector	*make_vector(int **arr, t_map_len *map);
t_data *parsing_map(int ac, char **av);
//parse_utils
void	clear_arr(int **arr, t_map_len *map);
void	clear_str(char **buf, char **line);
t_data	*create_data(void);
//iso_vector
void	rotate_z_axis(t_data *origin, double rad);
void	rotate_x_axis(t_data *origin, double rad);
void	make_iso_vector(t_data *origin_data);
//print_img
void	multiplied_pixel(t_data *data);

#endif
