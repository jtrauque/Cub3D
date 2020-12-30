# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtrauque <jtrauque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/16 11:44:52 by jtrauque          #+#    #+#              #
#    Updated: 2020/11/17 15:37:44 by jtrauque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

SRCS 		= ft_bzero.c ft_memccpy.c ft_memcpy.c ft_memmove.c ft_memset.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strrchr.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c get_next_line_utils.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS 		= ${SRCS:.c=.o}

DEP		= ${OBJS:.o=.d} ${OBJSB:.o=.d}

CC		= gcc

CFLAGS		= -Wall -Wextra -Werror -Iincludes -MMD -Wno-unused-result

RM		= rm -f

.c.o :		
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all :		${NAME}
 
$(NAME):	${OBJS}
		ar rcs libft.a ${OBJS}

clean :
		${RM} ${OBJS} ${DEP}

fclean : 	clean
		${RM} libft.a

re : 		fclean all

-include ${OBJS:.o=.d} 

.PHONY : 	all bonus clean fclean re
