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

int loop_hook(void *param) {
	t_img	*img;
	t_mlx	*mlx;
	static int count;

	mlx = (t_mlx*)param;
	img = create_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, 0x9080EF);
	ft_memset(img->data, 80, count * 4);
	img->data[count] = 0xA090FF;
	img->data[count + 1] = 0xA090FF;
	img->data[count + 2] = 0xA090FF;
	img->data[count + 3] = 0xA090FF;
	count += 16;
	if (count > WIN_WIDTH * WIN_HEIGHT)
		count = 0;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, img->img_ptr, 0, 0);
	free(img);
	return (0);
}

int				main()//int ac, char **av)
{
	t_mlx	mlx; //Here I first create my struct that will contains all the "MLX stuff"

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "SS13 irl");

	//mlx_loop_hook(mlx.mlx_ptr, loop_hook, &mlx);
	
	// Program works if these two lines are commented out
	mlx_mouse_hook(mlx.win, mouse_hook, &mlx);
	mlx_key_hook(mlx.win, key_hook, &mlx);

	mlx_loop(mlx.mlx_ptr);
	return (0);
}
