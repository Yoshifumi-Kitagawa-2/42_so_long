/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:46:33 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/16 00:48:48 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->map_flag = FALSE;
	check_arg(argc, argv, data);
	read_map(argv[1], data);
	init_map(&data->map);
	parse_map(data);
	init_other_data(data);
	render_map(data);
	mlx_hook(data->mlx_win, FocusIn, FocusChangeMask, render_map, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_action, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, close_game, data);
	mlx_loop(data->mlx);
	return (0);
}
