/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordonate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 15:45:14 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 17:28:34 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_macos/mlx.h"
#include "fdf.h"

static int		ft_int_tab_allocate(t_mlx *mlx_w, t_line *line)
{
	int			y;

	y = 0;
	if (!(mlx_w->int_tab = (int **)malloc(sizeof(int *) * (line->height))))
		return (-1);
	while (y < line->height)
	{
		if (!(mlx_w->int_tab[y] = (int *)malloc(sizeof(int) * (line->width))))
			return (-1);
		y++;
	}
	return (0);
}

static int		ft_modified_atoi(const char *str, t_mlx *mlx_w)
{
	long		i;
	int			sign;
	int			result;

	result = 0;
	sign = 1;
	i = 0;
	mlx_w->tag = 0;
	while ((str[i] > 8 && str[i] < 14) || (str[i] == 32))
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		result = result * 10 + (str[i] - 48);
		mlx_w->tag = 1;
		i++;
	}
	return (result * sign);
}

int				**tab_generator(t_line *line, t_mlx *mlx_w)
{
	int		x;
	int		y;

	if (ft_int_tab_allocate(mlx_w, line) == -1)
		return (NULL);
	y = 0;
	while (line && (y < (line->height) || line->get_line))
	{
		x = 0;
		while (x < line->width)
		{
			mlx_w->int_tab[y][x] = ft_modified_atoi(line->words_tab[x], mlx_w);
			if (mlx_w->tag == 0)
				return (NULL);
			x++;
		}
		line = line->next;
		y++;
	}
	return (mlx_w->int_tab);
}

static void		ft_fill_tab(t_line *line, t_mlx *mlx_w)
{
	int			x;
	int			y;
	int			position;

	position = 0;
	y = 0;
	while (line->get_line)
	{
		x = -1;
		while (position < line->map_area)
		{
			x += 1;
			if (x == line->width)
				x = 0;
			y = position / line->width;
			mlx_w->int_tableau[position][0] = x;
			mlx_w->int_tableau[position][1] = y;
			mlx_w->int_tableau[position][2] = mlx_w->int_tab[y][x];
			position++;
		}
		line = line->next;
	}
}

int				coordonate_generator(t_line *line, t_mlx *mlx_window)
{
	int		i;

	i = 0;
	if (!(mlx_window->int_tableau = (int **)malloc(sizeof(int *)
	* (line->map_area))))
		return (-1);
	while (i < line->map_area)
	{
		if (!(mlx_window->int_tableau[i] =
		(int *)malloc(sizeof(*(mlx_window->int_tableau)) * (3))))
			return (-1);
		i++;
	}
	ft_fill_tab(line, mlx_window);
	return (0);
}
