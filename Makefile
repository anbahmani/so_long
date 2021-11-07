NAME = so_long

CURRENT_MLX_FOLDER = minilibx-linux

CURRENT_MLX_EXEC = libmlx_Linux.a

MLXFLAGS =  -lXext -lX11 -lm

ifeq ($OSTYPE, darwin20.0)
	CURRENT_MLX_FOLDER = minilibx_macos
	CURRENT_MLX_EXEC = libmlx.a
	MLXFLAGS =  -framework OpenGL -framework AppKit
endif

LIBFT = libft

SRCS = 	srcs/get_next_line/get_next_line.c\
		srcs/get_next_line/get_next_line_utils.c\
		srcs/free_element/free_tab.c\
		srcs/utils/mapUtils.c\
		srcs/utils/fileUtils.c\
		srcs/check_error/check_arg_error.c\
		srcs/check_error/check_error.c\
		srcs/check_error/check_input_file_error.c\
		srcs/check_error/check_input_map_char_error.c\
		srcs/check_error/check_input_map_error.c\
		srcs/so_long_main.c\

OBJS	=	${SRCS:.c=.o}

OBJS_FOLDER = .objs

INCS	=	-I ./includes

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=128

RM		=	rm -f

RM_FOLDER = rm -rf

CREATE_FOLDER = mkdir

all:		 ${NAME}


${NAME}:	 ${OBJS}	
			${MAKE} -C ${CURRENT_MLX_FOLDER}
			${MAKE} -C ${LIBFT}
			${CC} ${CFLAGS} ${MLXFLAGS} ${INCS} $^ -o $@ ./${CURRENT_MLX_FOLDER}/${CURRENT_MLX_EXEC} ./libft/libft.a
			@${CREATE_FOLDER} ${OBJS_FOLDER}
			@mv srcs/*.o ${OBJS_FOLDER}
			@mv srcs/*/*.o ${OBJS_FOLDER}

.c.o:
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

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
