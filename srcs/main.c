/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:51:02 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_message(t_all_conf *info, char *s)
{
	ft_printf("%s\n", s);
	destroy_mlx(info);
	free_all(info);
	exit(STDERR_FILENO);
}

int	main(int argc, char **argv)
{
	t_all_conf	info;

	if (argc != 2)
	{
		ft_printf("Error\nusage: ./so_long [*.ber]\n");
		exit(1);
	}
	init(&info);
	check_file_name(&info, argv[1]);
	set_info(&info, argv[1]);
	display_map(&info);
	hooks(&info);
	mlx_loop(info.mlx);
	return (0);
}
