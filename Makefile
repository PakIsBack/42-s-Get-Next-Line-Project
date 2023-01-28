# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-ca <fdiaz-ca@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 13:58:38 by fdiaz-ca          #+#    #+#              #
#    Updated: 2022/09/10 14:19:30 by fdiaz-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line.a

SRCS	=	get_next_line.c get_next_line_utils.c

BONUS	=	get_next_line_bonus.c get_next_line_utils_bonus.c

OBJS	=	$(SRCS:.c=.o)

BOJS	=	$(BONUS:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f


all:		$(NAME)

$(NAME):	$(SRCS)	
		cc -c $(CFLAGS) $(SRCS)
		ar rcs $(NAME) $(OBJS)

bonus:
		cc -c $(CFLAGS) $(BONUS) $(SRCS)
		ar rcs $(NAME) $(OBJS) $(BOJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
