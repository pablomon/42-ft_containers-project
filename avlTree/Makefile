# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmontese <pmontes@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 23:23:47 by pmontese          #+#    #+#              #
#    Updated: 2022/06/10 10:00:58 by pmontese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program.
NAME	:= menu

# Define all the compiling flags.
CXX			:= clang++
CXXFLAGS	:= -std=c++98 -Wall -Wextra #-Werror
SANITIZEFLAGS	:= # -g -fsanitize=address

# Sources and objects.
SRCS	:= 	menu.cpp
OBJS	:= 	$(SRCS:.cpp=.o)

# Compile and create everything.
all: $(NAME)

# Compile the program with the objects.
$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(SANITIZEFLAGS) $(SRCS) -o $(NAME)

# Rule to remove all the object files.
clean:
		@rm -f $(OBJS)
		@rm -f $(OBJSO)
		@echo "[INFO] Objects removed!"

# Rule to remove everything that has been created by the makefile.
fclean: clean
		@rm -f $(NAME)
		@rm -f $(NAMESTD)
		@echo "[INFO] $(NAME) removed!"

# Rule to re-make everything.
re: fclean all

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all clean fclean format re
