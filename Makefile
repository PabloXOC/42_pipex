# Makefile for your project

# Compiler and flags
CC := cc
CFLAGS := -g
LIB_DIR := libft/
LIBS := $(LIB_DIR)libft.a
INCLUDES := -I$(LIB_DIR) -I.

# Source files
SRCS = pipex.c ft_inputs.c ft_inputs_2.c \
ft_inputs_3.c ft_pipe.c ft_pipe_2.c ft_child.c \

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
NAME = pipex

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJS) $(LIBS)

$(LIBS):
	make -C $(LIB_DIR)

%.o: %.c pipex.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
