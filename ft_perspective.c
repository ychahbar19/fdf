/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perspective.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:48:23 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 17:29:05 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "minilibx_macos/mlx.h"
#include "mlx_keycode.h"

static void		ft_linetrace_iso(int position, t_mlx *mlx_window, t_line *line)
{
	position = 0;
	while (position < (line->map_area - line->width))
		ft_bresenham_y(mlx_window, mlx_window->nc, position++, line);
	position = 0;
	while (position < (line->map_area))
	{
		if ((position + 1) % (line->width) != 0)
			ft_bresenham_x(mlx_window, mlx_window->nc, position++);
		else
			position++;
	}
}

static void		ft_linetrace_parallele(int position, t_mlx *mlx_w, t_line *line)
{
	position = 0;
	while (position < (line->map_area - line->width))
		ft_bresenham_y_2(mlx_w, mlx_w->nc, position++, line);
	position = 0;
	while (position < (line->map_area))
	{
		if ((position + 1) % (line->width) != 0)
			ft_bresenham_x_2(mlx_w, mlx_w->nc, position++);
		else
			position++;
	}
}

int				ft_newcoordonate_tool(t_mlx *mlx_w, t_line *line)
{
	int		i;

	i = 0;
	if (!((mlx_w->nc) = malloc(sizeof(int *) * ((int)line->map_area))))
		return (-1);
	while (i < line->map_area)
	{
		if (!((mlx_w->nc)[i] = (int *)malloc(sizeof(int) * (2))))
			return (-1);
		i++;
	}
	return (0);
}

int				ft_iso_coordonate(t_mlx *mlx_window, t_line *line)
{
	int			position;

	position = 0;
	ft_initialize(mlx_window, line);
	if ((ft_newcoordonate_tool(mlx_window, line)) == -1)
		return (-1);
	ft_render_iso(mlx_window, line, position);
	ft_linetrace_iso(position, mlx_window, line);
	return (0);
}

int				ft_parallele_coordonate(t_mlx *mlx_window, t_line *line)
{
	int			position;

	position = 0;
	ft_initialize_parallele(mlx_window, line);
	ft_render_parallele(mlx_window, line, position);
	ft_linetrace_parallele(position, mlx_window, line);
	return (0);
}
