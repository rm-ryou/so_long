/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:44:03 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_wall(t_all_conf *info, t_list **list, int line_len)
{
	int		i;
	char	*line;

	i = 0;
	line = (*list)->content;
	if (*line == '\n' || *line == '\0')
		map_error(info, &(*list));
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			map_error(info, &(*list));
		i += 1;
	}
	if (i != line_len)
		map_error(info, &(*list));
}

static void	check_char(t_all_conf *info, char c, t_list **list)
{
	t_map_conf	*map;

	map = info->map_info;
	if (c == '1' || c == '0')
		return ;
	else if (c == 'C')
		map->count_collect += 1;
	else if (c == 'E')
		map->count_exit += 1;
	else if (c == 'P')
		map->count_player += 1;
	else
		map_error(info, &(*list));
	return ;
}

static void	check_midle(t_all_conf *info, t_list **list, int line_len)
{
	char	*line;
	int		i;

	line = (*list)->content;
	i = 0;
	while (line[i] != '\0')
	{
		if (i == 0 || i == line_len - 1)
			if (line[i] != '1')
				map_error(info, &(*list));
		check_char(info, line[i], &(*list));
		i += 1;
	}
	if (i != line_len)
		map_error(info, &(*list));
}

static void	count_item(t_all_conf *info, t_list **list)
{
	t_map_conf	*tmp;

	tmp = info->map_info;
	if (tmp->count_collect < 1 || \
		tmp->count_exit < 1 || \
		tmp->count_player != 1)
	{
		ft_lstclear(list, free);
		put_message(info, "Error\ninvalide map item");
	}
}

void	map_isvalid(t_all_conf *info, t_list **list)
{
	t_list	*list_tmp;
	int		height;
	int		cur_height;
	int		line_len;

	list_tmp = *list;
	height = ft_lstsize(list_tmp);
	cur_height = 0;
	line_len = ft_strlen(list_tmp->content);
	if (height == line_len)
		map_error(info, &(*list));
	while (list_tmp != NULL)
	{
		if (cur_height == 0 || cur_height == height - 1)
			check_wall(info, &list_tmp, line_len);
		else
			check_midle(info, &list_tmp, line_len);
		list_tmp = list_tmp->next;
		cur_height += 1;
	}
	info->map_info->map_width = line_len;
	info->map_info->map_height = height;
	count_item(info, &list_tmp);
}
