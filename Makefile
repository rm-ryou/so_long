NAME := so_long
CFLAGS := -Wall -Werror -Wextra
INCLUDE := ./include/
PRINTF_DIR := ./ft_printf/
MLX_DIR := ./mlx_linux
SRCS_DIR := ./srcs/
OBJS_DIR := ./objs/
SRCS = $(SRCS_DIR)check_filepath.c \
	$(SRCS_DIR)check_map.c \
	$(SRCS_DIR)destroy_mlx.c \
	$(SRCS_DIR)display_map.c \
	$(SRCS_DIR)free.c \
	$(SRCS_DIR)get_next_line_utils.c \
	$(SRCS_DIR)get_next_line.c \
	$(SRCS_DIR)hooks.c \
	$(SRCS_DIR)info_img.c \
	$(SRCS_DIR)info_map.c \
	$(SRCS_DIR)info_player.c \
	$(SRCS_DIR)init.c \
	$(SRCS_DIR)main.c \
	$(SRCS_DIR)set_info.c
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:%.c=%.o)))
MLXFLAGS := -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

.PHONY: all
all: $(NAME)

$(NAME) : $(OBJS)
	make -C $(PRINTF_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) $(OBJS) $(MLXFLAGS) $(PRINTF_DIR)libftprintf.a -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE) -I /usr/include -Imlx_linux -O3 -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C $(MLX_DIR);
	$(MAKE) clean -C $(PRINTF_DIR)
	$(RM) -rf $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	$(MAKE) fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

.PHONY: re
re: fclean all
