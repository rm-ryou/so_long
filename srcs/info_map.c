/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:47:33 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_error(t_all_conf *info, t_list **list)
{
	ft_lstclear(list, free);
	put_message(info, "Error\ninvalid map");
}

static void	get_file_info(t_all_conf *info, t_list **list, char *file_path)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		put_message(info, "Error\nfilepath is wrong");
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || *line == '\n')
		{
			if (i == 0)
				map_error(info, &(*list));
			else
				break ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		ft_lstadd_back(list, ft_lstnew(line));
		i += 1;
	}
	close(fd);
}

static void	map_read(t_all_conf *info, t_list **list)
{
	t_map_conf	*map;
	t_list		*list_tmp;
	int			i;

	map = info->map_info;
	list_tmp = (*list);
	map->map = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	if (map->map == NULL)
	{
		ft_lstclear(&(*list), free);
		put_message(info, "Error\nmalloc error");
	}
	i = 0;
	while (i < map->map_height)
	{
		map->map[i] = ft_strdup(list_tmp->content);
		list_tmp = list_tmp->next;
		i += 1;
	}
	map->map[i] = NULL;
	ft_lstclear(&(*list), free);
}

void	set_map(t_all_conf *info, char *file_path)
{
	t_list	*map_list;

	map_list = NULL;
	get_file_info(info, &map_list, file_path);
	map_isvalid(info, &map_list);
	map_read(info, &map_list);
}
