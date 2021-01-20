# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/20 18:37:16 by jtrauque          #+#    #+#              #
#    Updated: 2021/01/20 18:37:24 by jtrauque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = Cub3D

SRCS      = main.c color.c map.c parsing.c text.c tools.c graph.c key.c ft_split.c raycasting.c sprite.c hook.c bitmap.c player.c map2.c tools2.c

OBJS      = ${SRCS:.c=.o}

DEP       = ${OBJS:.o=.d}

CC        = gcc

MLX_DIR = minilibx-linux

CFLAGS    = -I libft -I ${MLX_DIR} -Iincludes -Wall -Wextra -Werror -fsanitize=address -Wno-unused-result -g -MMD


LDFLAGS    = -Llibft -Lminilibx-linux

LDLIBS    = -lm -lmlx -lXext -lX11 -lft

RM        = rm -f

all :     libft2 minilibx ${NAME}

libft2 : 
		make -C libft
minilibx : 
		make -C ${MLX_DIR}

$(NAME) : ${OBJS}
		  ${CC} -o ${NAME} ${OBJS} ${CFLAGS} ${LDFLAGS} ${LDLIBS}

clean :   
					${RM} ${OBJS} ${DEP}

fclean :  clean
	        ${RM} ${NAME}
			make -C libft fclean
			make -C ${MLX_DIR} clean

lib_fclean : 
			./libft/ make fclean

re :      fclean all

-include  ${OBJS:.o=.d}

.PHONY :  all clean fclean re
