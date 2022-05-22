NAME := so_long
CFLAGS := -Wall -Werror -Wextra
INCLUDE := ./include/
PRINTF_DIR := ./ft_printf/
MLX_DIR := ./mlx_linux
MLX_URL := https://projects.intra.42.fr/uploads/document/document/8733/minilibx-linux.tgz
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
all: $(MLX_DIR) $(NAME)

$(MLX_DIR):
	@curl -OL $(MLX_URL)
	@tar -zxvf minilibx-linux.tgz
	@mv minilibx-linux mlx_linux && rm minilibx-linux.tgz

$(NAME) : $(OBJS)
	make -C $(PRINTF_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(PRINTF_DIR)libftprintf.a -o $@

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	mkdir -p $(OBJS_DIR)
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

.PHONY: clean
clean:
	@if [ -d $(MLX_DIR) ];then \
	make clean -C $(MLX_DIR); \
	fi
	make clean -C $(PRINTF_DIR)
	$(RM) -rf $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	$(RM) -rf $(MLX_DIR)
	make fclean -C $(PRINTF_DIR)
	$(RM) $(NAME)

.PHONY: re
re: fclean all
