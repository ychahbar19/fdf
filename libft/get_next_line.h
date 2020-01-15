/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbar <ychahbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 12:41:39 by ychahbar          #+#    #+#             */
/*   Updated: 2019/05/30 16:59:57 by ychahbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10000
# include <unistd.h>
# include "libft.h"
# include <limits.h>

int	get_next_line(const int fd, char **line);
int	ft_gnl(const int fd, char **line, char **s);

#endif
