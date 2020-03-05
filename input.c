/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 10:40:07 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/05 10:40:07 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
#include "libft.h"
#include "libftmath.h"

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	if (y < 0 || button != 1)
		return (0);
	mlx->button_states |= MASK_MOUSE_LEFT;
	mlx->mousex = x;
	mlx->mousey = y;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	if (y < 0 || button != 1)
		return (0);
	mlx->button_states &= 0xFFFF ^ MASK_MOUSE_LEFT;
	mlx->mousex = x;
	mlx->mousey = y;
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	if (mlx->button_states & MASK_MOUSE_LEFT)
		rotate_camera(mlx, x, y);
	mlx->mousex = x;
	mlx->mousey = y;
	printf("yaw = %f\n", mlx->yaw);
	return (0);
}

int				key_press_hook(int keycode, void *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	// here we need to calculate and save the camera position somewhere
	printf("keydown = %#.4x, %p\n", keycode, param);
	return (0);
}

int				key_release_hook(int keycode, void *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	// here we need to calculate and save the camera position somewhere
	printf("keyup = %#.4x, %p\n", keycode, param);
	return (0);
}
