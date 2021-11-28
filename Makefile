NAME = so_long

MLX_LINUX_FOLDER = minilibx-linux

MLX_LINUX_EXEC = libmlx_Linux.a

MLX_LINUX_FLAGS =   -lXext -lX11 -lm

MLX_MACOS_FOLDER = minilibx-macos

MLX_MACOS_EXEC = libmlx.a

MLX_MACOS_FLAGS =  -framework OpenGL -framework AppKit

LIBFT = libft

SRCS = 	srcs/free_element/free_tab.c\
		srcs/utils/mapUtils.c\
		srcs/utils/fileUtils.c\
		srcs/check_error/check_arg_error.c\
		srcs/check_error/check_error.c\
		srcs/check_error/check_input_file_error.c\
		srcs/check_error/check_input_map_char_error.c\
		srcs/check_error/check_input_map_error.c\
		srcs/so_long_main.c\
		srcs/get_next_line/get_next_line.c\
		srcs/get_next_line/get_next_line_utils.c\
		srcs/ihm/draw_map.c\
		srcs/ihm/draw_texture.c\
		srcs/ihm/init_ihm.c\
		srcs/ihm/pixel_put.c

OBJS	=	${SRCS:.c=.o}

OBJS_FOLDER = .objs

INCS	=	-I./includes

CC		=	clang

FLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=128

RM		=	rm -f

RM_FOLDER = rm -rf

CREATE_FOLDER = mkdir

OS := $(shell uname)

ifeq ($(OS),Darwin)
	CURRENT_MLX_FOLDER = ${MLX_MACOS_FOLDER}
	CURRENT_MLX_EXEC = ${MLX_MACOS_EXEC}
	CURRENT_MLX_FLAGS = ${MLX_MACOS_FLAGS}
else
	CURRENT_MLX_FOLDER = ${MLX_LINUX_FOLDER}
	CURRENT_MLX_EXEC = ${MLX_LINUX_EXEC}
	CURRENT_MLX_FLAGS = ${MLX_LINUX_FLAGS}
endif

all:		 ${NAME}


${NAME}:	 ${OBJS}
			${MAKE} -C ${LIBFT}
			${MAKE} -C ${CURRENT_MLX_FOLDER}
			${CC} ${FLAGS} ${CURRENT_MLX_FLAGS} ${INCS} $^ -o $@ ./${CURRENT_MLX_FOLDER}/${CURRENT_MLX_EXEC} ./libft/libft.a
			@${CREATE_FOLDER} ${OBJS_FOLDER}
			@mv srcs/*.o ${OBJS_FOLDER}
			@mv srcs/*/*.o ${OBJS_FOLDER}

.c.o:
			${CC} ${FLAGS} ${INCS} -c $< -o $@

clean:
			${MAKE} -C ${CURRENT_MLX_FOLDER} clean
			${MAKE} -C ${LIBFT} clean
			@${RM_FOLDER} ${OBJS_FOLDER}
			@${RM} ${OBJS}

fclean:		clean
			${MAKE} -C ${LIBFT} fclean
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re
