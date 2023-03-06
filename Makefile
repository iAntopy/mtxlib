SRC_DIR	= src

SRCS	= $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/mtx_math/*opps/*.c) $(wildcard $(SRC_DIR)/mtx_ufuncs/*copps/*.c)

OBJS	= $(SRCS:.c=.o)

LFTDIR	= ../libft
LIBFT	= $(LFTDIR)/libft.a

INCLS	= -Iincludes  -I$(LFTDIR)

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror $(INCLS)

AR	= ar -rcs

NAME	= libmtx.a

all:	$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(LIBFT):
	make -C $(LFTDIR)

$(NAME):	$(LIBFT) $(OBJS)
	$(AR) $(NAME) $(OBJS) $(LIBFT)


clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
