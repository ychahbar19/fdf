/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:13:33 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 17:29:38 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_keycode.h"
#include "minilibx_macos/mlx.h"

t_line			*new_line(void)
{
	t_line		*line;

	if (!(line = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	line->width = 0;
	line->height = 0;
	line->words = 0;
	line->map_area = 0;
	line->get_line = NULL;
	line->next = NULL;
	line->words_tab = NULL;
	return (line);
}

t_mlx			*mlx_list_init(void)
{
	t_mlx	*mlx_window;

	if (!(mlx_window = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	return (mlx_window);
}

t_gen			*manager_list_init(void)
{
	t_gen		*free_manager;

	if (!(free_manager = (t_gen *)malloc(sizeof(t_gen))))
		return (NULL);
	return (free_manager);
}

void			ft_initialize(t_mlx *mlx_w, t_line *line)
{
	mlx_w->color = AQUAMARINE;
	mlx_w->altitude = ((double)line->height / (double)line->map_area) * 40;
	mlx_w->zoom_tool_x = ((double)1422 / (double)(line->width) * 0.7);
	mlx_w->zoom_tool_y = ((double)900 / (double)(line->height) * 0.7);
	mlx_w->zoom = ft_min(mlx_w->zoom_tool_x, mlx_w->zoom_tool_y);
	mlx_w->mlx_ptr = mlx_init();
	mlx_w->win_ptr = mlx_new_window(mlx_w->mlx_ptr, 1280, 1080, "fdf");
	mlx_w->var = 0;
	mlx_w->dx = 0;
	mlx_w->dy = 0;
	mlx_w->x = 0;
	mlx_w->y = 0;
	mlx_w->zoom_para = 0.8;
}

void			ft_initialize_parallele(t_mlx *mlx_w, t_line *line)
{
	mlx_w->color = AQUAMARINE;
	mlx_w->altitude = ((double)line->height / (double)line->map_area) * 20;
	mlx_w->zoom_tool_x = ((double)1422 / (double)(line->width) * 0.6);
	mlx_w->zoom_tool_y = ((double)900 / (double)(line->height) * 0.6);
	mlx_w->zoom = ft_min(mlx_w->zoom_tool_x, mlx_w->zoom_tool_y);
	mlx_w->win_ptr2 = mlx_new_window(mlx_w->mlx_ptr, 1280, 1080, "fdf");
	mlx_w->var = 0;
	mlx_w->dx = 0;
	mlx_w->dy = 0;
	mlx_w->x = 0;
	mlx_w->y = 0;
}
