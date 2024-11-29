NAME		= so_long
LIBFT		= ./libraries/libft/libft.a
MLX_DIR		= ./libraries/mlx
LIBRARY		= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

LIBC		= ar rcs
CC			= gcc
RM			= rm -f

FLAGS		= -Wall -Wextra -Werror -Iinc

SRCS 		= \
./src/map/check_element_map.c ./src/map/check_path_map.c ./src/map/check_wall_map.c ./src/map/init_map.c \
./src/win/create_images_struct.c ./src/win/render_objects.c ./src/win/render_player.c \
./src/move/controls.c \
./src/main.c ./src/utils.c \

OBJS 		= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all :		$(LIBFT) $(NAME)

$(NAME) :	${OBJS} ${LIBFT} 
			@echo "Building so_long..."
			@${CC} ${OBJS} ${LIBFT} $(FLAGS) $(LIBRARY) -o ${NAME}

$(LIBFT) :
			@echo "Building libft..."
			@make -C libraries/libft > /dev/null 2>&1

clean:
			@echo "Cleaning..."
			@rm -f $(OBJS)
			@make clean -C libraries/libft > /dev/null 2>&1

fclean:		clean
			@echo "Cleaning all..."
			@rm -f $(NAME)
			@make fclean -C libraries/libft > /dev/null 2>&1

re: 		fclean all