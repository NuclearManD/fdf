/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:29:44 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/04 15:29:44 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libftmath.h"

# define WIN_WIDTH 1024
# define WIN_HEIGHT 1024

# define WALK_SPEED .2

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_vec3		cam_pos;
	double		yaw;
	double		pitch;
}				t_mlx;

t_img			*create_image(void *mlx, int xs, int ys, int bgcolor);
int				mouse_hook(int button, int x, int y, void *param);
int				key_hook(int keycode,void *param);

#endif
