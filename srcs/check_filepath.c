/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_filepath.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:40:44 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_file_name(t_all_conf *info, char *file_path)
{
	size_t	path_len;
	int		extension;
	int		flg;

	path_len = ft_strlen(file_path);
	extension = path_len - 4;
	if (extension <= 0)
		put_message(info, "Error\nfilepath is wrong");
	flg = ft_strncmp(file_path + extension, ".ber", 4);
	if (flg != 0)
		put_message(info, "Error\nfilepath is wrong");
}
