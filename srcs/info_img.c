/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:46:17 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	read_img(t_all_conf *info, void **img, char *file_path)
{
	t_img_conf	*img_tmp;

	img_tmp = info->img_info;
	*img = mlx_xpm_file_to_image(info->mlx, file_path, \
				&img_tmp->img_width, &img_tmp->img_height);
	if (img == NULL)
		put_message(info, "Error\nmlx_xpm_file_to_image is error");
}

void	set_img(t_all_conf *info)
{
	t_map_conf	*map;
	t_img_conf	*img;

	map = info->map_info;
	img = info->img_info;
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		put_message(info, "Error\nmlx_init is error");
	info->mlx_win = mlx_new_window(info->mlx, map->map_width * 32, \
									map->map_height * 32, "so_long");
	if (info->mlx_win == NULL)
		put_message(info, "Error\nmlx_new_window is error");
	read_img(info, &img->empty, IMG_EMPTY);
	read_img(info, &img->wall, IMG_WALL);
	read_img(info, &img->collect, IMG_COLLECT);
	read_img(info, &img->exit, IMG_EXIT);
	read_img(info, &img->player, IMG_PLAYER);
}
