/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 23:28:11 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/04 12:01:53 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void parse_map(t_data *data)
{
    check_line(data);
    check_column(data);
    count_inside(data);
    check_parm(data);
    check_position(data);
}

void check_line(t_data *data)
{
    size_t y;
    size_t width;

    y = 0;
    width = ft_strlen(data->map.map[0]);
    while (y < data->map.height)
    {
        if (ft_strlen(ft_strlen(data->map.map[y]) != width)
            put_error_and_exit("INVARID MAP", data);
        if (data->map.map[y][0] != WALL || data->map.map[y][width - 1] != WALL)
            put_error_and_exit("INVARID MAP", data);
        y++;
    }
    data->map.width = width;
}

void check_column(t_data *data)
{
    size_t x;

    x = 0;
    while (x < data->map.width)
    {
        if (data->map.map[0][x] != WALL || data->map.map[data->map.height - 1][x] != WALL)
            put_error_and_exit("INVARID MAP", data);
        x++;
    }
}

void check_inside(t_data *data)
{
    size_t x;
    size_t y;
    
    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            if (data->map.map[y][x] == PLAYER)
            {
                data->map.n_player++;
                data->map.player.x = x;
                data->map.player.y = y;
            }
            else if (data->map.map[y][x] == COLLECTIBLE)
                data->map.n_collectibel++;
            else if (data->map.map[y][x] == EXIT)
                data->map.n_exit++;
            else if (ft_strchr("C01PE", data->map.map[y][x]) == NULL)
                put_error_and_exit("INVALID ERROR", data);
            x++;
        }
        y++;
    }
}

void check_parm(t_data *data)
{
    if (data->map.n_collectibel == 0)
        put_error_and_exit("INVALID ERROR", data);
    else if (data->map.n_exit != 1)
        put_error_and_exit("INVALID ERROR", data);
    else if (data->map.n_player != 1)
        put_error_and_exit("INVALID ERROR", data);
}

void check_position(t_data *data)
{
    size_t x;
    size_t y;

    y = 0;
    while (y < data->map.height)
    {
        x = 0;
        while (x < data->map.width)
        {
            if (data->map.map[y][x] == COLLECTIBLE || data->map.map[y][x] == EXIT || data->map.map[y][x] == PLAYER)
            {
                if (data->map.map[y-1][x-1] == WALL && data->map.map[y-1][x] == WALL && data->map.map[y-1][x+1] == WALL && data->map.map[y][x-1] == WALL && data->map.map[y][x+1] == WALL && && data->map.map[y+1][x-1] == WALL && && data->map.map[y+1][x] == WALL && && data->map.map[y+1][x+1] == WALL)
                    put_error_and_exit("INVALID ERROR", data);
            }
            x++;
        }
        y++;
    }
}