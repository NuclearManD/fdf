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

#include "fdf.h"
#include "libft.h"
#include "libftmath.h"

int				main()//int ac, char **av)
{
	t_mlx	mlx; //Here I first create my struct that will contains all the "MLX stuff"
	t_img	*img;

	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "¥†®∑ß´√ç¨∆ƒˆ˚˙∂≈§å∞¢©¨¥∂ƒ∂¨∆˙≤çøˆ¨†©ø¬ˆ∆¨†©¶®ˆø…¨†¥®¨¬¥∂ˆ¥†¨√çƒ§∞ß∂´®†ªø¨∆ƒ©˜µ∆∫˙ƒ∂¨˚√ƒ");
	img = create_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, 0x6040F0);
	img->data[100000] = 0xFFFFFF;
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img->img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
