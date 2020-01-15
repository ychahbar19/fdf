/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:54:42 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 15:07:09 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_init_tool_x(t_mlx *mlx_w, int **nc, int pos)
{
	mlx_w->x = nc[pos][0];
	mlx_w->y = nc[pos][1];
	mlx_w->dx = nc[pos + 1][0] - nc[pos][0];
	mlx_w->dy = nc[pos + 1][1] - nc[pos][1];
}

void			ft_init_tool_y(t_mlx *mlx_w, int **nc, t_line *line, int pos)
{
	mlx_w->x = nc[pos][0];
	mlx_w->y = nc[pos][1];
	mlx_w->dx = nc[pos + (line->width)][0] - nc[pos][0];
	mlx_w->dy = nc[pos + (line->width)][1] - nc[pos][1];
}

void			ft_init_tool_x_p(t_mlx *mlx_w, int **nc, int pos)
{
	mlx_w->x = nc[pos][0];
	mlx_w->y = nc[pos][1];
	mlx_w->dx = nc[pos + 1][0] - nc[pos][0];
	mlx_w->dy = nc[pos + 1][1] - nc[pos][1];
}

void			ft_init_tool_y_p(t_mlx *mlx_w, int **nc, t_line *line, int pos)
{
	mlx_w->x = nc[pos][0];
	mlx_w->y = nc[pos][1];
	mlx_w->dx = nc[pos + (line->width)][0] - nc[pos][0];
	mlx_w->dy = nc[pos + (line->width)][1] - nc[pos][1];
}

void			add_line_to_last(t_line *list_adress, t_line *new_line)
{
	t_line		*tmp;

	if (!(list_adress) || !(new_line))
		return ;
	tmp = list_adress;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_line;
}
