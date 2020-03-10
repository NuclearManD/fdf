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
#include <math.h>
#include "libft.h"
#include "libftmath.h"
#include "mlx.h"
#include "fdf.h"

t_img			*create_image(void *mlx, int xs, int ys, int bgcolor)
{
	t_img	*img;
	int		cnt;

	img = malloc(sizeof(t_img));
	img->img_ptr = mlx_new_image(mlx, xs, ys);
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l,
										&img->endian);
	img->sx = xs;
	img->sy = ys;
	cnt = 0;
	while (cnt < xs * ys)
		img->data[cnt++] = bgcolor;
	return (img);
}

double			vec2_dist(t_vec2 *a, t_vec2 *b)
{
	t_vec2	dab10;

	dab10.x = a->x - b->x;
	dab10.y = a->y - b->y;
	return (vec2_mag(&dab10));
}

void			line_on_black(t_img *img, t_vec2 *a, t_vec2 *b, int color)
{
	t_vec2	slope;
	t_vec2	i;

	slope.x = b->x - a->x;
	slope.y = b->y - a->y;
	vec2_norm(&slope);
	i.x = a->x;
	i.y = a->y;
	while (vec2_dist(&i, b) >= 1)
	{
		if (!(i.x < 0 || i.y < 0 || i.x > img->sx || i.y > img->sy))
			if (img->data[(int)i.x + img->sx * (int)i.y] == 0)
				img->data[(int)i.x + img->sx * (int)i.y] = color;
		i.x += slope.x;
		i.y += slope.y;
	}
}
