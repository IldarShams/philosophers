NAME = philo
LIBFT = libft.a
SRCS = philo.c
LIB_PATH = ./Libft
HEADER = philo.h
OBJ =   $(SRCS:%.c=%.o)
RM = rm -f
CFLAGS  =   -Wall -Wextra -Werror -I $(HEADER)
.PHONY  :   all clean fclean re
all	:   $(NAME)
$(NAME) : ${OBJ} ${HEADER} ${LIBFT} 
	gcc $(CFLAGS) ${OBJ} -o $(NAME) -L. -lft 
%.o : %.c ${HEADER}
	gcc $(CFLAGS) -c $< -o $@
clean   :
	$(RM) $(OBJ) ${GNL}
	cd ./Libft && make -f Makefile2 clean
fclean  :   clean
	$(RM) ${LIBFT}
	$(RM) $(NAME)
${LIBFT}:
	cd ./Libft && make -f Makefile2 && mv libft.a ./..
re      :   fclean all
