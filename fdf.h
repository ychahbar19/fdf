/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:07:46 by ychahbar          #+#    #+#             */
/*   Updated: 2019/06/06 17:27:12 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fcntl.h"
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include "mlx_keycode.h"
# include "minilibx_macos/mlx.h"
# include <math.h>

typedef struct			s_size
{
	int		height;
	int		width;
	int		x_index;
	int		y_index;
}						t_size;

typedef struct			s_line
{
	int					words;
	int					width;
	int					height;
	int					map_area;
	char				**words_tab;
	char				*get_line;
	struct s_line		*next;
}						t_line;

typedef struct			s_gen
{
	struct s_mlx		*mlx_window;
	struct s_line		*line;
}						t_gen;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*win_ptr2;
	double				altitude;
	double				zoom;
	double				zoom_tool_x;
	double				zoom_tool_y;
	double				zoom_para;
	int					color;
	int					var;
	int					dx;
	int					dy;
	int					x;
	int					y;
	int					tag;
	int					**int_tab;
	int					**int_tableau;
	int					**nc;
}						t_mlx;

int						input_reader(int fd, t_size map_size, t_line *line);
int						input_checker(t_size map_size, t_line *line);
t_line					*new_line();
void					add_line_to_last(t_line *list_adress, t_line *new_line);
int						**tab_generator(t_line *line, t_mlx *mlx_window);
int						coordonate_generator(t_line *line, t_mlx *mlx_window);
t_mlx					*mlx_list_init();
t_gen					*manager_list_init();
void					window_generator(t_mlx *mlx_window);
int						ft_newcoordonate_tool(t_mlx *mlx_w, t_line *line);
/*
** isometric
*/
int						ft_iso_coordonate(t_mlx *mlx_window, t_line *line);
void					ft_initialize(t_mlx *mlx_w, t_line *line);
void					ft_init_tool_x(t_mlx *mlx_w, int **nc, int position);
void					ft_init_tool_y(t_mlx *mlx_w, int **nc, t_line *line,
						int pos);
void					ft_bresenham_x(t_mlx *mlx_w, int **nc, int position);
void					ft_bresenham_y(t_mlx *mlx_w, int **nc, int position,
						t_line *line);
int						ft_drawer(t_mlx *m, int x, int y);
void					ft_bresenham_x_tool1(t_mlx *mlx_w, t_size maptool,
						int i);
void					ft_bresenham_x_tool2(t_mlx *mlx_w, t_size maptool,
						int i);
void					ft_bresenham_y_tool1(t_mlx *mlx_w, t_size maptool,
						int i);
void					ft_bresenham_y_tool2(t_mlx *mlx_w, t_size maptool,
						int i);
/*
** parallele
*/
void					ft_initialize_parallele(t_mlx *mlx_w, t_line *line);
int						ft_parallele_coordonate(t_mlx *mlx_window,
						t_line *line_ptr);
void					ft_bresenham_x_2(t_mlx *mlx_w, int **nc, int position);
void					ft_bresenham_y_2(t_mlx *mlx_w, int **nc, int pos,
						t_line *line);
void					ft_init_tool_x_p(t_mlx *mlx_w, int **nc, int pos);
void					ft_init_tool_y_p(t_mlx *mlx_w, int **nc, t_line *line,
						int pos);
int						ft_drawer_p(t_mlx *m, int x, int y);
void					ft_bresenham_x_tool1_p(t_mlx *mlx_w, t_size maptool,
						int i);
void					ft_bresenham_x_tool2_p(t_mlx *mlx_w, t_size maptool,
						int i);
void					ft_bresenham_y_tool1_p(t_mlx *mlx_w, t_size maptool,
						int i);
void					ft_bresenham_y_tool2_p(t_mlx *mlx_w, t_size maptool,
						int i);
/*
** rendering
*/
void					ft_render_parallele(t_mlx *mlx_window, t_line *line,
						int position);
void					ft_render_iso(t_mlx *mlx_window, t_line *line,
						int position);
/*
** free memory
*/
void					ft_free_3(t_line *line);
void					ft_free_1(t_line *line_ptr, t_mlx *mlx_window);
void					ft_free_2(t_line *line_ptr, t_mlx *mlx_window);
#endif
