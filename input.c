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

int				mouse_hook(int button, int x, int y, void *param)
{
	// here we need to calculate and save the camera rotation somewhere
	printf("key = %#.4x (%5u, %5u), %p\n", button, x, y, param);
	return (0);
}

int				key_hook(int keycode, void *param)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	// here we need to calculate and save the camera position somewhere
	printf("key = %#.4x, %p\n", keycode, param);
	return (0);
}
