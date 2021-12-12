NAME = so_long

NAME_BONUS = so_long_bonus

FLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=128

OS := $(shell uname)

ifeq ($(OS),Darwin)
	MLX_FOLDER = minilibx-macos
	MLX_EXEC = libmlx.a
	MLX_FLAGS = -framework OpenGL -framework AppKit
else
	MLX_FOLDER = minilibx-linux
	MLX_EXEC = libmlx_Linux.a
	MLX_FLAGS = -lm -lXext -lX11
endif


FILESC = srcs/free_element/free_tab.c\
		srcs/utils/mapUtils.c\
		srcs/utils/textureUtils.c\
		srcs/utils/end_game.c\
		srcs/check_error/check_arg_error.c\
		srcs/check_error/check_error.c\
		srcs/check_error/check_input_file_error.c\
		srcs/check_error/check_input_map_char_error.c\
		srcs/check_error/check_input_map_error.c\
		srcs/check_error/check_texture_file_error.c\
		srcs/so_long.c\
		srcs/get_next_line/get_next_line.c\
		srcs/get_next_line/get_next_line_utils.c\
		srcs/ihm/draw_map.c\
		srcs/ihm/init_ihm.c\
		srcs/ihm/pixel_put.c\
		srcs/events/catch_event.c\
		srcs/events/move.c\

FILESO = free_tab.o\
		mapUtils.o\
		textureUtils.o\
		end_game.o\
		check_arg_error.o\
		check_error.o\
		check_input_file_error.o\
		check_input_map_char_error.o\
		check_input_map_error.o\
		check_texture_file_error.o\
		so_long.o\
		get_next_line.o\
		get_next_line_utils.o\
		draw_map.o\
		init_ihm.o\
		pixel_put.o\
		catch_event.o\
		move.o\


PATHLIBFT = ./libft/
LIBFTLIB = libft.a

BONUSFILESC = srcs/free_element/free_tab.c\
		srcs/utils/mapUtils.c\
		srcs/utils/textureUtils.c\
		srcs/utils/end_game.c\
		srcs/check_error/check_arg_error.c\
		srcs/check_error/check_error.c\
		srcs/check_error/check_input_file_error.c\
		srcs/check_error/check_input_map_char_error.c\
		srcs/check_error/check_input_map_error.c\
		srcs/check_error/check_texture_file_error.c\
		srcs/get_next_line/get_next_line.c\
		srcs/get_next_line/get_next_line_utils.c\
		srcs/ihm/draw_map.c\
		srcs/ihm/init_ihm.c\
		srcs/ihm/pixel_put.c\
		srcs/events/catch_event.c\
		srcs/events/move.c\
		srcs/bonus/catch_event_bonus.c\
		srcs/bonus/check_error_bonus.c\
		srcs/bonus/get_path_bonus.c\
		srcs/bonus/so_long_bonus.c\
		srcs/bonus/range_bonus.c\
		srcs/bonus/monsters_bonus.c \
		srcs/bonus/monsters_movement.c\
		srcs/bonus/finish.c


BONUSFILESO = free_tab.o\
		mapUtils.o\
		textureUtils.o\
		end_game.o\
		check_arg_error.o\
		check_error.o\
		check_input_file_error.o\
		check_input_map_char_error.o\
		check_input_map_error.o\
		check_texture_file_error.o\
		get_next_line.o\
		get_next_line_utils.o\
		draw_map.o\
		init_ihm.o\
		pixel_put.o\
		catch_event.o\
		move.o\
		catch_event_bonus.o\
		check_error_bonus.o\
		get_path_bonus.o\
		so_long_bonus.o\
		range_bonus.o\
		monsters_bonus.o \
		monsters_movement.o\
		finish.o


MLXINC = mlx.h
MLXLIB = libmlx.a

all : $(NAME)

$(NAME) : $(FILESC) $(LIBFTFILESC)
	@mkdir -p obj
	@make -C ./libft
	@mv libft/*.o ./obj && mv ./libft/libft.a .
	@cd $(MLX_FOLDER) && make all && mv $(MLXLIB) .. && make clean
	@gcc $(FLAGS) -c $(FILESC) $(MLX_FOLDER)/$(MLXINC) -lm -lX11 -lXext  -L/usr/X11R6/lib
	@gcc $(FLAGS) $(FILESO) $(LIBFTLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME) -lm -lX11 -lXext  -L/usr/X11R6/lib
	@mv $(FILESO) $(MLXLIB) $(LIBFTLIB) ./obj

clean :
	@rm -Rf ./obj
	@make -C libft clean

fclean : clean
	@rm -Rf $(NAME)
	@rm -Rf $(NAME_BONUS)
	@make -C libft fclean

re : fclean all

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(BONUSFILESC) $(LIBFTFILESC)
	@mkdir -p obj
	@make -C ./libft
	@mv libft/*.o ./obj && mv ./libft/libft.a .
	@cd $(MLX_FOLDER) && make all && mv $(MLXLIB) .. && make clean
	@cc $(FLAGS) -c $(BONUSFILESC) $(MLX_FOLDER)/$(MLXINC) -lm -lX11 -lXext  -L/usr/X11R6/lib
	@cc $(FLAGS) $(BONUSFILESO) $(LIBFTLIB) $(MLXLIB) $(MLXFLAGS) -o $(NAME_BONUS) -lm -lX11 -lXext  -L/usr/X11R6/lib
	@mv $(BONUSFILESO) $(MLXLIB) $(LIBFTLIB) ./obj

.PHONY:		all clean fclean re