/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 12:04:42 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/05 12:04:42 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "libftmath.h"

void			move_camera(t_mlx *mlx)
{
	(void *)mlx;
}

void			rotate_camera(t_mlx *mlx, int new_x, int new_y)
{
	mlx->yaw += (new_x - mlx->mousex) * 3.14 / WIN_WIDTH;
	mlx->pitch -= (new_y - mlx->mousey) * 3.14 / WIN_HEIGHT;

	if (mlx->yaw > 3.14 * 2)
		mlx->yaw -= 3.14 * 2;
	if (mlx->pitch > 3.14 * 2)
		mlx->pitch -= 3.14 * 2;
	if (mlx->yaw < 0)
		mlx->yaw += 3.14 * 2;
	if (mlx->pitch < 0)
		mlx->pitch += 3.14 * 2;
}
