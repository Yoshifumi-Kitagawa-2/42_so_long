/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_render_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:13:58 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/03 23:21:27 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int render_map(t_data *data)
{
    size_t  x;
    size_t  y;

    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            id_and_put_image(data, x, y);
            x++;
        }
        y++;
    }
    return(0);
}

void id_and_put_image(t_data *data, size_t x, size_t y)
{
    if (data->map.map[y][x] == COLLECTIBLE)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->collectible.xpm_ptr, x, y);
    else if (data->map.map[y][x] == SPACE)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->space.xpm_ptr, x, y);
    else if (data->map.map[y][x] == WALL)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->wall.xpm_ptr, x, y);
    else if (data->map.map[y][x] == EXIT)
        mlx_put_image_to_window (data->mlx, data->mlx_win, data->exit.xpm_ptr, x, y);
    else if (data->map.map[y][x] == PLAYER)
    {
        if (data->map.player_direction == FRONT)
            mlx_put_image_to_window (data->mlx, data->mlx_win, data->player_front.xpm_ptr, x, y);
	    else if (data->map.player_direction == LEFT)
            mlx_put_image_to_window (data->mlx, data->mlx_win, data->player_left.xpm_ptr, x, y);
	    else if (data->map.player_direction == RIGHT)
            mlx_put_image_to_window (data->mlx, data->mlx_win, data->player_right.xpm_ptr, x, y);
	    else if (data->map.player_direction == BACK)
            mlx_put_image_to_window (data->mlx, data->mlx_win, data->player_back.xpm_ptr, x, y);
    }
}


