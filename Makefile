NAME = philo
LIBFT = libft.a
PRF = libftprintf.a 
SRCS = philo.c
LIB_PATH = ./Libft
PRF_PATH = ./ft_printf_buf_without_flags
HEADER = philo.h
OBJ =   $(SRCS:%.c=%.o)
RM = rm -f
CFLAGS  =   -Wall -Wextra -Werror -I $(HEADER)
.PHONY  :   all clean fclean re
all	:   $(NAME)
$(NAME) : ${OBJ} ${HEADER} ${LIBFT} ${PRF}
	gcc $(CFLAGS) ${OBJ} -o $(NAME) -L. -lft -L. -lftprintf
%.o : %.c ${HEADER}
	gcc $(CFLAGS) -c $< -o $@
clean   :
	$(RM) $(OBJ) ${GNL}
	cd ${LIB_PATH} && make -f Makefile2 clean
	cd ${PRF_PATH}  && make -f Makefile2 clean
fclean  :   clean
	$(RM) ${LIBFT} ${PRF}
	$(RM) $(NAME)
${LIBFT}:
	cd ${LIB_PATH} && make -f Makefile2 && mv libft.a ./..
${PRF}:
	cd ${PRF_PATH} && make -f Makefile2 && mv libftprintf.a  ./..
re      :   fclean all
