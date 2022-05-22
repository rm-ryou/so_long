/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:37:49 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	on_destroy(t_all_conf *info)
{
	destroy_mlx(info);
	free_all(info);
	exit(1);
	return (0);
}

static int	on_keydown(int keycode, t_all_conf *info)
{
	if (keycode == 65307)
		on_destroy(info);
	if (keycode == 'w' || keycode == 65362)
		move_player(info, 'u');
	else if (keycode == 's' || keycode == 65364)
		move_player(info, 'd');
	else if (keycode == 'd' || keycode == 65363)
		move_player(info, 'r');
	else if (keycode == 'a' || keycode == 65361)
		move_player(info, 'l');
	get_player_info(info);
	display_map(info);
	return (0);
}

static int	on_expose(t_all_conf *info)
{
	display_map(info);
	return (0);
}

void	hooks(t_all_conf *info)
{
	mlx_hook(info->mlx_win, 2, 1L << 0, on_keydown, info);
	mlx_hook(info->mlx_win, 12, 1L << 15, on_expose, info);
	mlx_hook(info->mlx_win, 17, 1L << 17, on_destroy, info);
}
