/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:41:52 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 17:25:13 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_bresenham_x(t_mlx *mlx_w, int **nc, int position)
{
	t_size		maptool;
	int			i;

	ft_init_tool_x(mlx_w, mlx_w->nc, position);
	maptool.x_index = (mlx_w->dx >= 0) ? 1 : -1;
	maptool.y_index = (mlx_w->dy >= 0) ? 1 : -1;
	mlx_w->dx = abs(mlx_w->dx);
	mlx_w->dy = abs(mlx_w->dy);
	mlx_w->var = 0;
	ft_drawer(mlx_w, nc[position][0], nc[position][1]);
	i = 1;
	if (mlx_w->dx > mlx_w->dy)
	{
		mlx_w->var = mlx_w->dx / 2;
		ft_bresenham_x_tool1(mlx_w, maptool, i);
	}
	else
		ft_bresenham_x_tool2(mlx_w, maptool, i);
}

void		ft_bresenham_y(t_mlx *mlx_w, int **nc, int position, t_line *line)
{
	t_size		maptool;
	int			i;

	ft_init_tool_y(mlx_w, mlx_w->nc, line, position);
	maptool.x_index = (mlx_w->dx >= 0) ? 1 : -1;
	maptool.y_index = (mlx_w->dy >= 0) ? 1 : -1;
	mlx_w->dx = abs(mlx_w->dx);
	mlx_w->dy = abs(mlx_w->dy);
	mlx_w->var = 0;
	ft_drawer(mlx_w, nc[position][0], nc[position][1]);
	i = 1;
	if (mlx_w->dx > mlx_w->dy)
	{
		mlx_w->var = mlx_w->dx / 2;
		ft_bresenham_x_tool1(mlx_w, maptool, i);
	}
	else
		ft_bresenham_x_tool2(mlx_w, maptool, i);
}
