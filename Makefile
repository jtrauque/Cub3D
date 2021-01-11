

NAME      = Cub3D

SRCS      = main.c color.c map.c parsing.c text.c tools.c graph.c key.c ft_split.c raycasting.c sprite.c

OBJS      = ${SRCS:.c=.o}

DEP       = ${OBJS:.o=.d}

CC        = gcc

CFLAGS    = -I libft -Iincludes -Llibft -lft -lmlx -lm -lX11 -lXext -Wall -Wextra -Werror -fsanitize=address -Wno-unused-result -g -MMD

RM        = rm -f

all :     libft2 ${NAME}

libft2 : 
		make -C libft

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
		  ${CC} -o ${NAME} ${OBJS} ${CFLAGS} 

clean :   
					${RM} ${OBJS} ${DEP}

fclean :  clean
	        ${RM} ${NAME}
			make -C libft fclean

lib_fclean : 
			./libft/ make fclean

re :      fclean all

-include  ${OBJS:.o=.d}

.PHONY :  all clean fclean re
