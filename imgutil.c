/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:46:20 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/04 19:46:20 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "mlx.h"
#include "fdf.h"

t_img			*create_image(void *mlx, int xs, int ys, int bgcolor)
{
	t_img*	img;
	int		cnt;

	img = malloc(sizeof(t_img));
	img->img_ptr = mlx_new_image(mlx, xs, ys);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l,
										&img->endian);
	cnt = 0;
	while (cnt < xs * ys)
		img->data[cnt++] = bgcolor;
	return (img);
}
