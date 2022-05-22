/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:48:42 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_map(t_all_conf *info)
{
	t_map_conf	*map;
	int			i;

	map = info->map_info;
	i = 0;
	if (map->map != NULL)
	{
		while (i < map->map_height)
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i += 1;
		}
	}
	free(map->map);
	map->map = NULL;
	free(map);
	map = NULL;
}

void	free_player(t_all_conf *info)
{
	free(info->player_info);
	info->player_info = NULL;
}

void	free_img(t_all_conf *info)
{
	free(info->img_info);
	info->img_info = NULL;
}

void	free_all(t_all_conf *info)
{
	free_map(info);
	free_player(info);
	free_img(info);
}
