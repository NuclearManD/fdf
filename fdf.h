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

# define WIN_WIDTH 840
# define WIN_HEIGHT 840

# define WALK_SPEED .2

# define MASK_MOUSE_LEFT	1
# define MASK_KEY_LEFT		2
# define MASK_KEY_RIGHT		4
# define MASK_KEY_UP		8
# define MASK_KEY_DOWN		16

# define KEY_UPARROW	126
# define KEY_DOWNARROW	125
# define KEY_LEFTARROW	123
# define KEY_RIGHTARROW	124

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			sx;
	int			sy;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
	t_vec3		cam_pos;
	double		yaw;
	double		pitch;

	int			mousex;
	int			mousey;
	int			button_states;
	double		**map;

	double		a_x;
	double		a_y;
	double		i_x;
	double		i_y;
}				t_mlx;

t_img			*create_image(void *mlx, int xs, int ys, int bgcolor);
void			line_on_black(t_img *img, t_vec2 *a, t_vec2 *b, int color);

int				hook_mousedown(int button, int x, int y, t_mlx *mlx);
int				hook_mouseup(int button, int x, int y, t_mlx *mlx);
int				hook_mousemove(int x, int y, t_mlx *mlx);
int				key_press_hook(int keycode, t_mlx *mlx);
int				key_release_hook(int keycode, t_mlx *mlx);

void			rotate_camera(t_mlx *mlx, int last_x, int last_y);
void			move_camera(t_mlx *mlx);

double			**load_map(int fd, int *sizes);

#endif
