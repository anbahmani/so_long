NAME        	=   so_long

NAME_BONUS     	=   so_long_bonus

CC          	=   gcc

ifeq ($(OS),Darwin)
	MLX_DIR = mlx_macos
	MLXFLAGS = -framework OpenGL -framework AppKit
else
	MLX_DIR = mlx_linux
	MLXFLAGS	=	-lm -lX11 -lXext
endif

SRC_DIR			= 	$(shell find srcs -type d)
INC_DIR			= 	$(shell find includes -type d) \
					$(shell find lib/$(MLX_DIR) -type d) \
					$(shell find lib/libft -type d)

OBJ_DIR			=	obj

LIB_DIR			=	lib/libft lib/$(MLX_DIR)

vpath %.c $(foreach dir, $(SRC_DIR), $(dir):)

MLXFLAG	=	-lm -lX11 -lXext

# library -----------------------------------------------------------

LIB			=	ft mlx_Linux

SRC			= 	get_next_line_utils.c \
				get_next_line.c \
				draw_map.c \
				init_ihm.c \
				pixel_put.c \
				free_tab.c \
				catch_event.c \
				move.c \
				check_arg_error.c \
				check_input_map_char_error.c \
				check_input_map_error.c \
				check_texture_file_error.c \
				check_input_file_error.c \
				check_error.c \
				mapUtils.c \
				end_game.c \
				textureUtils.c \
				so_long.c

SRC_BONUS		=	catch_event_bonus.c\
					check_error_bonus.c\
					finish.c\
					get_path_bonus.c\
					monsters_bonus.c\
					monsters_movement.c\
					range_bonus.c\
					so_long_bonus.c\
					check_arg_error.c\
					check_error.c\
					check_input_file_error.c\
					check_input_map_char_error.c\
					check_input_map_error.c\
					check_texture_file_error.c\
					catch_event.c\
					move.c\
					free_tab.c\
					get_next_line.c\
					get_next_line_utils.c\
					draw_map.c\
					init_ihm.c\
					pixel_put.c\
					end_game.c\
					mapUtils.c\
					textureUtils.c

OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

OBJ_BONUS	=	$(addprefix $(OBJ_DIR)/, $(SRC_BONUS:%.c=%.o))

# Compilation flags -------------------------------------------------

CFLAGS		=	-Wall -Wextra -Werror

D_NO_BONUS  =	-DBONUS=0

D_BONUS		=	-DBONUS=1

IFLAGS		=	$(foreach dir, $(INC_DIR), -I $(dir))

LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib)) \
				$(MLXFLAG)

# Colors ------------------------------------------------------------

_GREY	=	$'\e[30m
_RED	=	$'\e[31m
_GREEN	=	$'\e[32m
_YELLOW	=	$'\e[33m
_BLUE	=	$'\e[34m
_PURPLE	=	$'\e[35m
_CYAN	=	$'\e[36m
_WHITE	=	$'\e[37m

# main part ---------------------------------------------------------

all:
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make  $(NAME)

bonus: fclean
	@echo "\n$(_BLUE)___$(NAME) Setting___\n$(_WHITE)"
	@make $(NAME_BONUS)

show:
	@echo "$(_BLUE)SRC :\n$(_YELLOW)$(SRC)$(_WHITE)"
	@echo "$(_BLUE)OBJ :\n$(_YELLOW)$(OBJ)$(_WHITE)"
	@echo "$(_BLUE)CFLAGS :\n$(_YELLOW)$(CFLAGS)$(_WHITE)"
	@echo "$(_BLUE)IFLAGS :\n$(_YELLOW)$(IFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LFLAGS :\n$(_YELLOW)$(LFLAGS)$(_WHITE)"
	@echo "$(_BLUE)LIB_DIR :\n$(_YELLOW)$(LIB_DIR)$(_WHITE)"
	@echo "\n-----\n"
	@echo "$(_BLUE)Compiling : \n$(_YELLOW)$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)$(_WHITE)"

install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir);)

re-install:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) re;)

fclean-install:
	@make -C lib/libft fclean
	@make -C lib/mlx_linux clean

$(NAME): install $(OBJ)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $(NAME)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

$(NAME_BONUS): install $(OBJ_BONUS)
	@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(LFLAGS) -o $(NAME_BONUS)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

$(OBJ_DIR)/%.o : %.c
	@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<
	@echo "$(_GREEN)DONE$(_WHITE)"

re:	fclean all

clean:
	@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
	@$(foreach file, $(OBJ), rm -rf $(file))
	@$(foreach file, $(OBJ_BONUS), rm -rf $(file))
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean:	clean
	@echo "Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(_GREEN)DONE$(_WHITE)\n-----"

.PHONY: all bonus show install re-install re clean flcean