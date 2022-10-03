#==============================================================================#
#..............................................................................#
#...............................DECLARATIONS...................................#
#..............................................................................#
#==============================================================================#

## Compilation

NAME	=	form

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3

## Sources

SRCDIR	=

SRCFILE	=	main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp\
			PresidentialPardonForm.cpp RobotomyRequestForm.cpp

SRC		=	$(addprefix $(SRCDIR), $(SRCFILE))

INCL_DIR=

INCL	=	$(wildcard $(INCL_DIR)*.hpp)

## Objects

OBJDIR	=	obj/

OBJ		=	$(addprefix $(OBJDIR), $(SRC:.cpp=.o))

#==============================================================================#
#..............................................................................#
#....................................RULES.....................................#
#..............................................................................#
#==============================================================================#

all			:	$(NAME)

$(NAME)		:	$(OBJ) Makefile
				$(CC) $(OBJ) -o $(NAME)

$(OBJDIR)%.o:	$(SRCDIR)%.cpp Makefile $(wildcard $(INCL_DIR)*.hpp)
				mkdir -p $(OBJDIR)
				$(CC) $(FLAGS) -c $< -o $@

clean		:
				rm -rf $(OBJ)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
