SRCS		= colors.c \
			  fractals.c \
			  fractol.c \
			  graphics.c \
			  hooks.c \
			  utils.c
SRCS		:= $(addprefix src/,$(SRCS)) 
OBJS		= ${SRCS:.c=.o}
NAME		= fractol
CC			= gcc
MAKE		= make
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -Iinclude -Ilibft -Iminilibx
			
$(NAME):		$(OBJS)
				$(MAKE) -C libft	
				$(MAKE) -C minilibx
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a minilibx/libmlx.a -framework OpenGL -framework AppKit
all:			$(NAME)
clean:
				${RM} ${OBJS}
				$(MAKE) clean -C libft
				$(MAKE) clean -C minilibx
fclean:			clean
				${RM} $(NAME)
				$(MAKE) fclean -C libft
				$(MAKE) clean -C minilibx
re:				fclean all
.PHONY:			all clean fclean re
