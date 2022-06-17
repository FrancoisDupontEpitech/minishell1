##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Create an archive of the library
##

CC	=	gcc

SRC	=	./src/display_help.c	\
		./src/shell/minishell1.c	\
		./src/shell/start_shell.c	\
		./src/shell/display_path.c	\
		./src/shell/interpret_commands.c	\
		./src/builtins/change_directory/my_getenv.c \
		./src/builtins/change_directory/do_cd.c	\
		./src/builtins/change_directory/go_to_home.c \
		./src/builtins/change_directory/go_to_old_path.c \
		./src/builtins/change_directory/go_to_a_home_directory.c \
		./src/builtins/do_exit.c	\
		./src/builtins/do_env.c	\
		./src/builtins/do_setenv.c	\
		./src/builtins/do_unsetenv.c	\
		./src/count_args.c	\
		./src/convert_env_to_envlist.c	\
		./src/execute_command.c	\
		./src/execute_program.c	\
		./src/sanatize_string/sanatize_string.c	\
		./src/sanatize_string/get_str_sanatized_size.c	\
		./src/sanatize_string/remove_all_extra_spaces.c

MAIN	=	./main.c

TESTSRC	=	./tests/redirect_all_std.c	\
			./tests/unit_tests/test_get_str_sanatized_size.c
			# ./tests/unit_tests/test_sanatize_string.c	\

OBJ	=	$(SRC:.c=.o)

OBJMAIN	=	$(MAIN:.c=.o)

OBJTEST	=	$(TESTSRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -W

LFLAGS	=	-L./lib -lmy

LIB_PATH	=	./lib/my

HEADER_PATH     =       ./includes

CPPFLAGS	=	-I./includes

COVFLAGS	=	--coverage -lcriterion

NAME	=	mysh

NAMETEST	=	unit_tests

.PHONY:	all clean fclean re

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJMAIN)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -g3 -o $(NAME) $(OBJ) $(OBJMAIN) $(LFLAGS) $(CFLAGS)

tests_run:	$(SRC) $(OBJTEST)
	$(MAKE) -C $(LIB_PATH)
	$(CC) -o $(NAMETEST) $(SRC) $(OBJTEST) $(CPPFLAGS) $(LFLAGS) $(COVFLAGS)
	./$(NAMETEST)

clean:
	$(MAKE) -C $(LIB_PATH) fclean
	$(RM) $(OBJ)
	$(RM) $(OBJMAIN)
	$(RM) $(OBJTEST)


fclean:	clean
	$(RM) $(NAME)
	$(RM) $(NAMETEST)
	$(RM) $(OBJTEST)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *~

re:	fclean all
