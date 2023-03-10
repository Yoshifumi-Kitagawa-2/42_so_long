/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_init_other_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitaga <yokitaga@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:50:26 by yokitaga          #+#    #+#             */
/*   Updated: 2023/01/18 01:35:43 by yokitaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_other_data(t_data *data)
{
	init_mlx(data);
	init_image(data);
}

void	init_mlx(t_data *data)
{
	//初期化
	//失敗したらNULLを返す。成功しても後でfreeしないといけない。
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		put_error_and_exit("MLX ERROR", data);
	//windowを用意
	data->mlx_win = mlx_new_window(data->mlx, data->map.width * IMG_WIDTH, \
			data->map.height * IMG_HEIGHT, "S_LONG");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_win);
		put_error_and_exit("MLX_WIN ERROR", data);
	}
}

void	init_image(t_data *data)
{
	data->collectible = xpm_file_to_image(data->mlx, COLLECTIBLE_IMG, data);
	data->wall = xpm_file_to_image(data->mlx, WALL_IMG, data);
	data->space = xpm_file_to_image(data->mlx, SPACE_IMG, data);
	data->player = xpm_file_to_image(data->mlx, PLAYER_IMG, data);
	data->exit = xpm_file_to_image(data->mlx, EXIT_IMG, data);
}

t_image	xpm_file_to_image(void *mlx, char *path, t_data *data)
{
	t_image	image;

	//変換するだけじゃなくて&image.x, &image.yに縦横の長さが入る。今回は50。
	//だからIMG_HIGHT/IMG_WIDTHはそれぞれ50
	image.img_ptr = mlx_xpm_file_to_image(mlx, path, &image.x, &image.y);
	if (image.img_ptr == NULL)
		put_error_and_exit("XPM_TO_IMAGE ERROR", data);
	return (image);
}
