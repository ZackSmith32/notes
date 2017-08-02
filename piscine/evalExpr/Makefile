NAME = 	eval_expr

CFILES = 	eval.c					\
			ft_split_whitespaces.c	\
			funcs.c					\
			math.c

HDIR =		includes
SRCDIR =	./srcs/

FLAGS = -Wall -Werror -Wextra

all: compile

compile: 
	gcc  $(FLAGS) $(addprefix $(SRCDIR),$(CFILES)) -I $(HDIR) -o $(NAME)

clean:
	/bin/rm -f g_header.h.gch ft_rush02.h.gch a.out

fclean: clean
	/bin/rm -f $(NAME)