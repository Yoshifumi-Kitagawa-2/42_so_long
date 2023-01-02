/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:26:54 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/03 02:40:54 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../gnl/get_next_line.h"
# include "../printf/ft_printf.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define FALSE   0
# define TRUE    1

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'
# define SPACE			'0' 
# define WALL			'1'

typedef struct s_data{
    void        *mlx;
    void        *mlx_win;
    size_t      flag;
    t_map       map;
    t_image		wall;
	t_image		space;
	t_image		collectible;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		player;
}t_data;

typedef struct s_pos{
    size_t  x;
    size_t  y;
}t_pos;

typedef struct s_map{
    char       **map;
    size_t     fd;
    size_t     height;
    size_t     width;
    t_pos      player;
}t_map;

typedef struct s_image{
    void        *xpm_ptr;
	size_t      x;
	size_t		y;
}t_image;





#endif