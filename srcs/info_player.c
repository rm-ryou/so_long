/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:42:38 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	replace_char(t_all_conf *info, int *x, int *y)
{
	t_player_conf	*player;
	t_map_conf		*map;

	player = info->player_info;
	map = info->map_info;
	player->count_move += 1;
	ft_printf("%d actions were taken.\n", player->count_move);
	map->map[player->y][player->x] = '0';
	map->map[player->y + *y][player->x + *x] = 'P';
}

static void	move_position(t_all_conf *info, int x, int y)
{
	t_player_conf	*player;
	t_map_conf		*map;

	player = info->player_info;
	map = info->map_info;
	if (map->map[player->y + y][player->x + x] == '0')
		replace_char(info, &x, &y);
	else if (map->map[player->y + y][player->x + x] == '1')
		return ;
	else if (map->map[player->y + y][player->x + x] == 'C')
	{
		player->count_collect += 1;
		replace_char(info, &x, &y);
	}
	else if (map->map[player->y + y][player->x + x] == 'E')
	{
		if (player->count_collect == map->count_collect)
		{
			replace_char(info, &x, &y);
			ft_printf("game_clear\n");
			destroy_mlx(info);
			free_all(info);
			exit(1);
		}
	}
}

void	move_player(t_all_conf *info, char order)
{
	if (order == 'u')
		move_position(info, 0, -1);
	else if (order == 'd')
		move_position(info, 0, 1);
	else if (order == 'r')
		move_position(info, 1, 0);
	else if (order == 'l')
		move_position(info, -1, 0);
	return ;
}

void	get_player_info(t_all_conf *info)
{
	t_map_conf		*map;
	t_player_conf	*player;
	int				i;
	int				j;

	map = info->map_info;
	player = info->player_info;
	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->map[i][j] == 'P')
			{
				player->x = j;
				player->y = i;
				return ;
			}
			j += 1;
		}
		i += 1;
	}
}
