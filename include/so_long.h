/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmoriya <rmoriya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 11:12:15 by rmoriya           #+#    #+#             */
/*   Updated: 2022/05/02 12:35:39 by rmoriya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../mlx_linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
//# include <stdlib.h>
# include <stdio.h>

# define PIXEL_SIZE     32
# define BUFFER_SIZE    42
# define IMG_EMPTY      "./images/img_empty.xpm"
# define IMG_WALL       "./images/img_wall.xpm"
# define IMG_COLLECT    "./images/img_collectible.xpm"
# define IMG_EXIT       "./images/img_exit.xpm"
# define IMG_PLAYER     "./images/img_player.xpm"

typedef struct s_player_conf
{
	int	x;
	int	y;
	int	count_collect;
	int	count_move;
}	t_player_conf;

typedef struct s_map_conf
{
	char	**map;
	int		map_height;
	int		map_width;
	int		count_collect;
	int		count_exit;
	int		count_player;
}	t_map_conf;

typedef struct s_img_conf
{
	void	*empty;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*player;
	int		img_height;
	int		img_width;
}	t_img_conf;

typedef struct s_all_conf
{
	void			*mlx;
	void			*mlx_win;
	void			*img;
	t_map_conf		*map_info;
	t_player_conf	*player_info;
	t_img_conf		*img_info;
}	t_all_conf;

void	check_file_name(t_all_conf *info, char *file_path);
char	*get_next_line(int fd);
void	init(t_all_conf *info);
void	put_message(t_all_conf *info, char *s);
void	set_info(t_all_conf *info, char *file_path);
void	set_map(t_all_conf *info, char *file_path);
void	map_isvalid(t_all_conf *info, t_list **list);
void	map_error(t_all_conf *info, t_list **list);
void	get_player_info(t_all_conf *info);
void	hooks(t_all_conf *info);
void	display_map(t_all_conf *info);
void	move_player(t_all_conf *info, char order);
void	set_img(t_all_conf *info);
void	free_all(t_all_conf *info);
void	destroy_mlx(t_all_conf *info);

#endif
