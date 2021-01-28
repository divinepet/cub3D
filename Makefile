SRCS			=	main.c \
					keyboard.c \
					minimap_draw.c \
					screenshot.c \
					init_params.c \
					./gnl/get_next_line.c \
					./gnl/get_next_line_utils.c \
					./parsing/open_map.c \
					./parsing/edit_map.c \
					./parsing/data_load.c \
					./parsing/data_load_more.c \
					./engine/raycasting.c \
					./engine/draw.c \
					./engine/additional_funcs.c \
					./utils/utils.c \
					./utils/utils_2.c \
					./utils/utils_3.c \
					./errors/errors.c
OBJS			= $(SRCS:.c=.o)

RM				= rm -f
CFLAGS			= -O3 -g -I.
LIBS			= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX				= libmlx.dylib

NAME			= cub3D

all:			$(NAME)

$(NAME):		$(MLX) $(OBJS)
				gcc ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}
				$(RM) $(OBJS)

$(MLX):
				@$(MAKE) -C mlx
				@mv mlx/$(MLX) .

clean:
				@$(MAKE) -C mlx clean
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME) $(MLX)

re:				fclean $(NAME)

.PHONY:			all clean fclean re