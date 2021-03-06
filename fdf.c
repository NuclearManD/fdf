/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:21:15 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/04 15:21:15 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "libftmath.h"

int				loop_hook(t_mlx *mlx)
{
	t_img	*img;
	t_vec3	a = {1, 1, 1};
	t_vec3	b = {1, 1, -1};
	t_vec3	c = {-1, 1, -1};
	t_vec3	d = {-1, 1, 1};

	img = create_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, 0);
	
	if (mlx->button_states & MASK_KEY_UP)
		memset(&(img->data[WIN_WIDTH * 5 / 4]), 0x6F, WIN_WIDTH * 2);
	if (mlx->button_states & MASK_KEY_LEFT)
		memset(&(img->data[WIN_WIDTH * 2 * 4]), 0x6F, WIN_WIDTH * 2);
	if (mlx->button_states & MASK_KEY_RIGHT)
		memset(&(img->data[WIN_WIDTH * (2 * 4) + WIN_WIDTH / 2]), 0x6F, WIN_WIDTH * 2);
	if (mlx->button_states & MASK_KEY_DOWN)
		memset(&(img->data[WIN_WIDTH * 16 + WIN_WIDTH * 5 / 4]), 0x6F, WIN_WIDTH * 2);
	
	render_line(img, &a, &b, 0xFFFFFF, mlx);
	render_line(img, &b, &c, 0xFFFFFF, mlx);
	render_line(img, &c, &d, 0xFFFFFF, mlx);
	render_line(img, &d, &a, 0xFFFFFF, mlx);
	
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
	free(img);
	return (0);
}

int				main()//int ac, char **av)
{
	int		sizes[2];
	double	**map;

	t_mlx	mlx;

	/*if (!(mlx.map = load_map(0, sizes)))
		return (-1);*/

	mlx.i_x = 0;
	mlx.i_y = 0;
	mlx.a_x = 3.46;
	mlx.a_y = 3.46;
	mlx.yaw = -3.14;
	mlx.button_states = 0;
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "SS13 irl");

	mlx_loop_hook(mlx.mlx_ptr, loop_hook, &mlx);
	mlx_hook(mlx.win, 4, 0, hook_mousedown, &mlx);
	mlx_hook(mlx.win, 5, 0, hook_mouseup, &mlx);
	mlx_hook(mlx.win, 6, 0, hook_mousemove, &mlx);
	mlx_hook(mlx.win, 2, 0, key_press_hook, &mlx);
	mlx_hook(mlx.win, 3, 0, key_release_hook, &mlx);

	mlx_loop(mlx.mlx_ptr);
	return (0);
}
