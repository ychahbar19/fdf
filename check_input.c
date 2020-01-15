/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 14:44:00 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 18:06:11 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		input_stocker(t_line *line, t_size map_size)
{
	while (line->get_line != NULL)
	{
		line->height = map_size.height;
		line->width = ft_count_words(line->get_line, ' ');
		line->map_area = line->width * line->height;
		line = line->next;
	}
}

int				input_checker(t_size map_size, t_line *line)
{
	map_size.width = line->width;
	while (line->next->get_line)
	{
		if (line->width != line->next->width)
			return (-1);
		line = line->next;
	}
	return (0);
}

int				input_reader(int fd, t_size map_size, t_line *line)
{
	t_line		*line_ptr;
	t_line		*new_line_elem;
	char		*s;

	map_size.height = 0;
	line_ptr = line;
	if (ft_gnl(fd, &line->get_line, &s) == -1)
	{
		ft_putendl("argument is not a file");
		exit(EXIT_FAILURE);
	}
	while (ft_gnl(fd, &line->get_line, &s) > 0)
	{
		if (!(line->words_tab = ft_strsplit(line->get_line, ' ')))
			return (-1);
		map_size.height += 1;
		if (!(new_line_elem = new_line()))
			return (-1);
		add_line_to_last(line, new_line_elem);
		line = line->next;
	}
	line = line_ptr;
	input_stocker(line, map_size);
	return (0);
}
