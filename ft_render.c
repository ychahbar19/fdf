/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:29:25 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 17:29:27 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_render_iso(t_mlx *mlx_w, t_line *line, int position)
{
	int			x;
	int			y;
	int			tmp;

	x = 0;
	y = 0;
	tmp = mlx_w->int_tableau[position][2];
	while (position < line->map_area)
	{
		x = ((sqrt(2) / 2) * (mlx_w->int_tableau[position][0]
		- mlx_w->int_tableau[position][1]) * mlx_w->zoom);
		y = (((sqrt(2 / 3)) * mlx_w->int_tableau[position][2])
		- ((1 / (sqrt(6))) * (mlx_w->int_tableau[position][0]
		+ mlx_w->int_tableau[position][1])) * mlx_w->zoom);
		y = (y * cos(180 * (M_PI / 180))) + (mlx_w->int_tableau[position][2]
		* sin(180 * (M_PI / 180)));
		tmp = (-1 * sin(180 * (M_PI / 180)))
		+ (mlx_w->int_tableau[position][2] * cos(180 * (M_PI / 180)));
		y = (y + (tmp * mlx_w->altitude));
		mlx_w->nc[position][0] = x;
		mlx_w->nc[position][1] = y;
		position++;
	}
}

void	ft_render_parallele(t_mlx *mlx_w, t_line *line, int position)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (position < line->map_area)
	{
		x = ((sqrt(2) / 2) * (mlx_w->int_tableau[position][0]
		- mlx_w->int_tableau[position][1]) * mlx_w->zoom);
		y = (((sqrt(2 / 3)) * mlx_w->int_tableau[position][2])
		- ((1 / (sqrt(6))) * (mlx_w->int_tableau[position][0]
		+ mlx_w->int_tableau[position][1])) * mlx_w->zoom);
		y = (mlx_w->int_tableau[position][2] + ((1 / 2) * x) + ((1 / 2) * y))
		* mlx_w->zoom_para;
		y = (y * cos(180 * (M_PI / 180))) + (mlx_w->int_tableau[position][2]
		* sin(180 * (M_PI / 180)));
		mlx_w->int_tableau[position][2] = (-1 * sin(180 * (M_PI / 180)))
		+ (mlx_w->int_tableau[position][2] * cos(180 * (M_PI / 180)));
		y = (y + (mlx_w->int_tableau[position][2] * mlx_w->altitude));
		mlx_w->nc[position][0] = x;
		mlx_w->nc[position][1] = y;
		position++;
	}
}
