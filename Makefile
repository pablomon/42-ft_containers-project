# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmontese <pmontes@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 23:23:47 by pmontese          #+#    #+#              #
#    Updated: 2022/06/06 15:47:52 by pmontese         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
Green	= \033[0;32m
NoColor = \033[0m
# Name of the program.
NAMEFT	:= ft_test
NAMESTD := std_test

SRCS	:= 	main.cpp utils/utils.cpp \
			tests/vector_tests.cpp \
			tests/stack_tests.cpp \
			tests/map_tests.cpp

OBJS	:= 	$(SRCS:.cpp=.o)

# Define all the compiling flags.
CXX			:= clang++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98
SANITIZEFLAGS	:= -g -fsanitize=address
STDFLAG		:= -D STD='"STANDAR"'

# Compile and create everything.
all: $(SRCS)
	make std
	make ft

# This won't run if the source files don't exist or are not modified.
%.o: %.cpp %.hpp
		$(CXX) $(CXXFLAGS) $(SANITIZEFLAGS) -o $@ -c $<

# Rule to build tests using my implementation.
ft: $(SRCS)
	$(CXX) $(CXXFLAGS) $(SANITIZEFLAGS) $(SRCS) -o $(NAMEFT)
	@echo "${Green} ft version built ($(NAMEFT))\n ${NoColor}"

# Rule to build tests using std.
std:
	$(CXX) $(CXXFLAGS) $(SANITIZEFLAGS) $(STDFLAG) $(SRCS) -o $(NAMESTD)
	@echo "${Green} std version built ($(NAMESTD))\n ${NoColor}"

# Rule to remove all the object files.
clean:
		@rm -f $(OBJS)
		@rm -f $(OBJSO)
		@echo "[INFO] Objects removed!"

# Rule to remove everything that has been created by the makefile.
fclean: clean
		@rm -f $(NAMEFT)
		@echo "[INFO] $(NAMEFT) removed!"
		@rm -f $(NAMESTD)
		@echo "[INFO] $(NAMESTD) removed!"
		@rm -f ftlog
		@rm -f stdlog
		@echo "Logs removed!"

# Rule to re-make everything.
re: fclean all

# Makes sure that gnu make will still run even if files called
# clean / fclean / all and re already exist in the directory
.PHONY: all clean fclean format re
