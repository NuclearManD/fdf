/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maploader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbrophy <dbrophy@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:14:54 by dbrophy           #+#    #+#             */
/*   Updated: 2020/03/05 14:14:54 by dbrophy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "libft.h"
#include "get_next_line.h"

static void		realloc_map(double ***ffof, int ncols)
{
	size_t		ffof_size;
	size_t		new_size;
	double		**nova;

	ffof_size = ncols * sizeof(double *);
	new_size = (ncols + 16) * sizeof(double *);
	nova = (double **)malloc(new_size);
	ft_memcpy(nova, *ffof, ffof_size);
	if (ncols > 0)
		free(*ffof);
	*ffof = nova;
}

static void		free_map(double **map, int size)
{
	while (size--)
		free(map[size]);
	free(map);
}

void			load_line(char **arr, double **dst, int size)
{
	int	i;

	i = -1;
	*dst = malloc(size * sizeof(double));
	while (++i < size)
		(*dst)[i] = ft_atoi(arr[i]);
}

double			**load_map(int fd, int *sizes)
{
	int		size_x;
	int		size_y;
	char	*line;
	char	**arr;
	double	**map;

	size_x = 0;
	size_y = 0;
	while (get_next_line(fd, &line))
	{
		if (size_x == 0)
		{
			size_x = ft_wordcount(line);
			arr = malloc((size_x + 1) * sizeof(char *));
		}
		else if (size_x != ft_wordcount(line))
		{
			free_map(map, size_y);
			size_x = -1;
			break;
		}
		if (size_y % 16 == 0)
			realloc_map(&map, size_y);
		ft_wordsplit(arr, line, size_x + 1);
		load_line(arr, &(map[size_y]), size_x);
		free(line);
		size_y++;
	}
	sizes[0] = size_x;
	sizes[1] = size_y;
	free(arr);
	return (map);
}
