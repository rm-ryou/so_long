/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:44:33 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img(t_all_conf *info)
{
	info->img_info = (t_img_conf *)malloc(sizeof(t_img_conf));
	if (info->img_info == NULL)
		put_message(info, "img malloc error");
	info->img_info->empty = NULL;
	info->img_info->wall = NULL;
	info->img_info->collect = NULL;
	info->img_info->exit = NULL;
	info->img_info->player = NULL;
	info->img_info->img_height = 0;
	info->img_info->img_width = 0;
}

void	init_player(t_all_conf *info)
{
	info->player_info = (t_player_conf *)malloc(sizeof(t_player_conf));
	if (info->player_info == NULL)
		put_message(info, "Error\nplayer malloc error");
	info->player_info->x = 0;
	info->player_info->y = 0;
	info->player_info->count_collect = 0;
	info->player_info->count_move = 0;
}

void	init_map(t_all_conf *info)
{
	info->map_info = (t_map_conf *)malloc(sizeof(t_map_conf));
	if (info->map_info == NULL)
		put_message(info, "Error\nmap malloc error");
	info->map_info->map = NULL;
	info->map_info->map_height = 0;
	info->map_info->map_width = 0;
	info->map_info->count_collect = 0;
	info->map_info->count_exit = 0;
	info->map_info->count_player = 0;
}

void	init(t_all_conf *info)
{
	info->mlx = NULL;
	info->mlx_win = NULL;
	info->img = NULL;
	init_map(info);
	init_player(info);
	init_img(info);
}
