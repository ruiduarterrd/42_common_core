#include "main.h"
#include "../mlx/mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

#define SIDE_LEN 800

void ft_pixel_put(t_img *img, int x, int y, int color) {
	int offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(offset + img->img_pixel)) = color;
}

void ft_square(t_mlx *mlx, int x_center, int y_center, int leght, int color) {
	int x_start = x_center - leght / 2;
	int x_end = x_center + leght / 2;
	int y_start = y_center - leght / 2;
	int y_end = y_center + leght / 2;
	int x, y = y_start;

	while (y <= y_end) {
		x = x_start;
		while (x <= x_end) {
			ft_pixel_put(&mlx->img, x, y, color);
			x++;
		}
		y++;
	}
}

void ft_circle(t_mlx *mlx, int x_center, int y_center, int radius, int color) {
	int x = 0, y = radius, p = 1 - radius;

	while (x <= y) {
		int i = x_center - x;
		while (i <= x_center + x) {
			ft_pixel_put(&mlx->img, i, y_center + y, color);
			ft_pixel_put(&mlx->img, i, y_center - y, color);
			i++;
		}
		i = x_center - y;
		while (i <= x_center + y) {
			ft_pixel_put(&mlx->img, i, y_center + x, color);
			ft_pixel_put(&mlx->img, i, y_center - x, color);
			i++;
		}
		if (p < 0) {
			p += 2 * x + 3;
		} else {
			p += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}

void ft_color_screen(t_mlx *mlx, int color) {
	int x, y = 0;

	while (y < SIDE_LEN) {
		x = 0;
		while (x < SIDE_LEN) {
			ft_pixel_put(&mlx->img, x, y, color);
			x++;
		}
		y++;
	}
}

int ft_key_hook(int keysym, t_mlx *mlx) {
	static int background_color;
	if (keysym == XK_Escape) {
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_image(mlx->con, mlx->img.img);
		mlx_destroy_window(mlx->con, mlx->win);
		mlx_destroy_display(mlx->con);
		free(mlx->con);
		exit(0);
	} else if (keysym == XK_r) {
		background_color = RED;
		ft_color_screen(mlx, background_color);
	} else if (keysym == XK_g) {
		background_color = GREEN;
		ft_color_screen(mlx, background_color);
	} else if (keysym == XK_b) {
		background_color = BLUE;
		ft_color_screen(mlx, background_color);
	} else if (keysym == XK_c) {
		ft_circle(mlx, SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN / 8, WHITE);
	} else if (keysym == XK_v) {
		ft_square(mlx, SIDE_LEN / 2, SIDE_LEN / 2, SIDE_LEN / 8, ORANGE);
	}
	mlx_put_image_to_window(mlx->con, mlx->win, mlx->img.img, 0, 0);
	printf("The %d key has been pressed\n\n", keysym);
	return 0;
}

int main(void) {

	t_mlx mlx;

	mlx.con = mlx_init();
	if (mlx.con == NULL)
		return 1;
	mlx.win = mlx_new_window(mlx.con, SIDE_LEN, SIDE_LEN, "GAME");
	if (mlx.win == NULL) {
		mlx_destroy_display(mlx.con);
		free(mlx.con);
		return 1;
	}
	mlx.img.img = mlx_new_image(mlx.con, SIDE_LEN, SIDE_LEN);
	if (mlx.img.img == NULL) {
		mlx_destroy_window(mlx.con, mlx.win);
		mlx_destroy_display(mlx.con);
		free(mlx.con);
		return 1;
	}
	mlx.img.img_pixel = mlx_get_data_addr(mlx.img.img, &mlx.img.bpp,
										  &mlx.img.line_len, &mlx.img.endian);
	if (mlx.img.img_pixel == NULL) {
		mlx_destroy_image(mlx.con, mlx.img.img);
		mlx_destroy_window(mlx.con, mlx.win);
		mlx_destroy_display(mlx.con);
		free(mlx.con);
		return 1;
	}
	mlx_key_hook(mlx.win, ft_key_hook, &mlx);
	mlx_loop(mlx.con);
	return 0;
}

