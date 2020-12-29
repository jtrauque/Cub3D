

NAME      = Cub3D

SRCS      = main.c color.c map.c parsing.c text.c tools.c graph.c gnl/get_next_line.c gnl/get_next_line_utils.c key.c ft_split.c

OBJS      = ${SRCS:.c=.o}

DEP       = ${OBJS:.o=.d}

CC        = gcc

CFLAGS    = -I gnl -I libft -Iincludes -Llibft -lft -lmlx -lm -lX11 -lXext -Wall -Wextra -Werror -fsanitize=address -Wno-unused-result -g -MMD

RM        = rm -f

all :     ${NAME}

.c.o :
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
		  ${CC} -o ${NAME} ${OBJS} ${CFLAGS} 

clean :   
					${RM} ${OBJS} ${DEP}

fclean :  clean
	        ${RM} ${NAME}

re :      fclean all

-include  ${OBJS:.o=.d}

.PHONY :  all clean fclean re
