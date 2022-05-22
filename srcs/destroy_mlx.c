/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:46:37 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	destroy_mlx(t_all_conf *info)
{
	t_img_conf	*img;

	img = info->img_info;
	if (img->empty != NULL)
		mlx_destroy_image(info->mlx, img->empty);
	if (img->wall != NULL)
		mlx_destroy_image(info->mlx, img->wall);
	if (img->collect != NULL)
		mlx_destroy_image(info->mlx, img->collect);
	if (img->exit != NULL)
		mlx_destroy_image(info->mlx, img->exit);
	if (img->player != NULL)
		mlx_destroy_image(info->mlx, img->player);
	if (info->mlx_win != NULL)
		mlx_destroy_window(info->mlx, info->mlx_win);
	if (info->mlx != NULL)
	{
		mlx_loop_end(info->mlx);
		free(info->mlx);
	}
}
