// #include "mlx.h"
// #include "fdf.h"
// #include <stdio.h>


// void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
// {
// 	char *dst;

// 	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

// int main()
// {
// 	void *mlx;
// 	void *mlx_win;
// 	t_img img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Hello 42 Seoul");
// 	img.img = mlx_new_image(mlx, 300, 300);//1400 1200은 디파인 상수로 변경하기
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	my_mlx_pixel_put(&img, -90, -90, GR);
// 	my_mlx_pixel_put(&img, -89, -90, GR);
// 	my_mlx_pixel_put(&img, -90, -89, GR);
// 	my_mlx_pixel_put(&img, -89, -89, GR);

// 	my_mlx_pixel_put(&img, 90, 90, RED);
// 	my_mlx_pixel_put(&img, 89, 90, RED);
// 	my_mlx_pixel_put(&img, 90, 89, RED);
// 	my_mlx_pixel_put(&img, 89, 89, RED);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 250, 250);
// 	mlx_loop(mlx);
// }
