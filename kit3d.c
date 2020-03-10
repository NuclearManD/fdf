/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kit3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 22:57:38 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/09 22:57:38 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "libftmath.h"

void			rotate3d(t_vec3 *vec, double yaw, double pitch)
{
	double x;
	double y;

	x = vec->x;
	y = vec->y;
	vec->x = x * cos(yaw) + y * sin(yaw);
	vec->y = y * cos(yaw) - x * sin(yaw);

	vec->x = vec->x * cos(pitch) + vec->z * sin(pitch);
	vec->z = vec->z * cos(pitch) - vec->x * sin(pitch);
}

void			to_2d(t_vec2 *out, t_vec3 *point, t_mlx *config)
{
	t_vec3	ouch_help;
	double	oof;

	ft_memcpy(&ouch_help, point, sizeof(t_vec3));
	ouch_help.x -= config->cam_pos.x;
	ouch_help.y -= config->cam_pos.y;
	ouch_help.z -= config->cam_pos.z;
	rotate3d(&ouch_help, config->yaw, config->pitch);
	oof = ouch_help.y * config->a_x + config->i_x;
	out->x = (ouch_help.x + oof / 2) / oof;
	oof = ouch_help.y * config->a_y + config->i_y;
	out->y = (ouch_help.z + oof / 2) / oof;
}

void			render_point(t_img *img, t_vec3 *point, int color, t_mlx *config)
{
	t_vec2	watermelon;

	to_2d(&watermelon, point, config);
	watermelon.x *= img->sx;
	watermelon.y *= img->sy;
	img->data[(int)watermelon.x + img->sx * (int)watermelon.y] = color;
}

void			render_line(t_img *img, t_vec3 *a, t_vec3 *b, int color, t_mlx *config)
{
	t_vec2	pxa;
	t_vec2	pxb;

	to_2d(&pxa, a, config);
	to_2d(&pxb, b, config);
	pxa.x *= img->sx;
	pxa.y *= img->sy;
	pxb.x *= img->sx;
	pxb.y *= img->sy;
	line_on_black(img, &pxa, &pxb, color);
}

void			render_map(t_img *img, t_mlx *config)
{
	
}
