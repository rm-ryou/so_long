/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:41:42 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	to_img(t_all_conf *info, char *c, int x, int y)
{
	t_img_conf	*img;

	img = info->img_info;
	if (*c == '0')
		mlx_put_image_to_window(info->mlx, info->mlx_win, img->empty, \
								x * img->img_width, y * img->img_height);
	else if (*c == '1')
		mlx_put_image_to_window(info->mlx, info->mlx_win, img->wall, \
								x * img->img_width, y * img->img_height);
	else if (*c == 'C')
		mlx_put_image_to_window(info->mlx, info->mlx_win, img->collect, \
								x * img->img_width, y * img->img_height);
	else if (*c == 'E')
		mlx_put_image_to_window(info->mlx, info->mlx_win, img->exit, \
								x * img->img_width, y * img->img_height);
	else if (*c == 'P')
		mlx_put_image_to_window(info->mlx, info->mlx_win, img->player, \
								x * img->img_width, y * img->img_height);
}

void	display_map(t_all_conf *info)
{
	t_map_conf	*map;
	int			i;
	int			j;

	map = info->map_info;
	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			to_img(info, &map->map[i][j], j, i);
			j += 1;
		}
		i += 1;
	}
}
