# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 18:54:07 by zsyyida           #+#    #+#              #
#    Updated: 2023/11/08 09:10:17 by zsyyida          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bureaucrat

CXX = c++

RM = rm -rf

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

SRCS = main.cpp Bureaucrat.cpp

OBJS := $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean: $(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .cpp.o