/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 17:28:53 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 17:28:55 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_3(t_line *line)
{
	t_line		*tmp;
	int			i;

	tmp = line;
	while (tmp)
	{
		i = 0;
		while (i < tmp->width)
		{
			free(tmp->words_tab[i]);
			i++;
		}
		free(tmp->words_tab);
		free(tmp->get_line);
		tmp = tmp->next;
	}
}

void	ft_free_1(t_line *line_ptr, t_mlx *mlx_window)
{
	int		i;

	i = 0;
	while (i < line_ptr->height)
	{
		free(mlx_window->int_tab[i]);
		i++;
	}
	free(mlx_window->int_tab);
	ft_free_3(line_ptr);
}

void	ft_free_2(t_line *line_ptr, t_mlx *mlx_window)
{
	int		i;

	i = 0;
	while (i < line_ptr->map_area)
	{
		free(mlx_window->int_tableau[i]);
		i++;
	}
	free(mlx_window->int_tableau);
	i = 0;
	while (i < line_ptr->map_area)
	{
		free(mlx_window->nc[i]);
		i++;
	}
	free(mlx_window->nc);
}
