/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_read_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:19:01 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/03 11:29:57 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void read_map(char *argv, t_data *data)
{
    char    *map;
    char    *line;
    
    data->map.fd = open(argv, O_RDONLY);
    if (data->map.fd == -1)
        put_error_and_exit("OPEN ERROR", data);
    map = ft_strdup("");
    data->map.height = 0;
    while(1)
    {
        line = get_next_line(data->map.fd);
        if (line == NULL)
            break;
        map = ft_strjoin(map, line);
        free(line);
        data->map.height++;
    }
    close(data->map.fd);
    check_for_empty_line(map, data);//メモ後に実装必要かも
    data->map.map = ft_split(map, '\n');
    data->flag = TRUE;
}


