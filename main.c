/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 14:30:12 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 18:06:16 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "mlx_keycode.h"
#include "fdf.h"

static int		deal_key(int key, t_gen *free_manager)
{
	if (key == ESC_KEY)
	{
		ft_free_2(free_manager->line, free_manager->mlx_window);
		free(free_manager->mlx_window);
		free(free_manager->line);
		free(free_manager);
		exit(0);
	}
	return (0);
}

static int		ft_manager(t_size map_size, t_line *line, t_mlx *mlx_w)
{
	if ((input_checker(map_size, line) == -1)
	|| ((mlx_w->int_tab = tab_generator(line, mlx_w)) == NULL))
	{
		ft_putendl("invalid file");
		return (-1);
	}
	if ((coordonate_generator(line, mlx_w)) == -1)
		return (-1);
	if ((ft_iso_coordonate(mlx_w, line) == -1))
		return (-1);
	ft_parallele_coordonate(mlx_w, line);
	ft_free_1(line, mlx_w);
	return (0);
}

static void		init_struct(t_size *s)
{
	s->height = 0;
	s->width = 0;
	s->x_index = 0;
	s->y_index = 0;
}

static void		ft_arg_error(void)
{
	ft_putendl("wrong number of arguments");
	exit(EXIT_FAILURE);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_line		*line_ptr;
	t_size		map_size;
	t_mlx		*mlx_window;
	t_gen		*free_manager;

	init_struct(&map_size);
	if (argc != 2)
		ft_arg_error();
	if (!(line_ptr = new_line())
	|| ((fd = open(argv[1], O_RDONLY)) <= 0))
		exit(EXIT_FAILURE);
	if (input_reader(fd, map_size, line_ptr) == -1
	|| (!(mlx_window = mlx_list_init()))
	|| (!(free_manager = manager_list_init()))
	|| (ft_manager(map_size, line_ptr, mlx_window) == -1))
		exit(EXIT_FAILURE);
	free_manager->mlx_window = mlx_window;
	free_manager->line = line_ptr;
	mlx_key_hook(mlx_window->win_ptr, &deal_key, free_manager);
	mlx_key_hook(mlx_window->win_ptr2, &deal_key, free_manager);
	mlx_loop(mlx_window->mlx_ptr);
	exit(EXIT_SUCCESS);
}
