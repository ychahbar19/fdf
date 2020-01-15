/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham_tool.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:32:42 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 17:25:09 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_drawer(t_mlx *m, int x, int y)
{
	mlx_pixel_put(m->mlx_ptr, m->win_ptr, x + 640, y + 150, m->color);
	return (1);
}

void		ft_bresenham_x_tool1(t_mlx *mlx_w, t_size maptool, int i)
{
	while (i <= mlx_w->dx)
	{
		mlx_w->x += maptool.x_index;
		mlx_w->var += mlx_w->dy;
		if (mlx_w->var >= mlx_w->dx)
		{
			mlx_w->var -= mlx_w->dx;
			mlx_w->y += maptool.y_index;
		}
		ft_drawer(mlx_w, mlx_w->x, mlx_w->y);
		i++;
	}
}

void		ft_bresenham_x_tool2(t_mlx *mlx_w, t_size maptool, int i)
{
	while (i++ <= mlx_w->dy)
	{
		mlx_w->y += maptool.y_index;
		mlx_w->var += mlx_w->dx;
		if (mlx_w->var >= mlx_w->dy)
			mlx_w->x += maptool.x_index;
		if (mlx_w->var >= mlx_w->dy)
			mlx_w->var -= mlx_w->dy;
		ft_drawer(mlx_w, mlx_w->x, mlx_w->y);
	}
}

void		ft_bresenham_y_tool1(t_mlx *mlx_w, t_size maptool, int i)
{
	while (i <= mlx_w->dx)
	{
		mlx_w->x += maptool.x_index;
		mlx_w->var += mlx_w->dy;
		if (mlx_w->var >= mlx_w->dx)
		{
			mlx_w->var -= mlx_w->dx;
			mlx_w->y += maptool.y_index;
		}
		ft_drawer(mlx_w, mlx_w->x, mlx_w->y);
		i++;
	}
}

void		ft_bresenham_y_tool2(t_mlx *mlx_w, t_size maptool, int i)
{
	while (i++ <= mlx_w->dy)
	{
		mlx_w->y += maptool.y_index;
		mlx_w->var += mlx_w->dx;
		if (mlx_w->var >= mlx_w->dy)
			mlx_w->x += maptool.x_index;
		if (mlx_w->var >= mlx_w->dy)
			mlx_w->var -= mlx_w->dy;
		ft_drawer(mlx_w, mlx_w->x, mlx_w->y);
	}
}
