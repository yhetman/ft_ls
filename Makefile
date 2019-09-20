# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yhetman <yhetman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/10 01:20:26 by yhetman           #+#    #+#              #
#    Updated: 2019/09/18 17:22:54 by blukasho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mclean mfclean mre

NAME :=		ft_ls

SRC_PATH :=	sources/
INC_PATH :=	includes/
LIB_PATH :=	libft/
OBJ_PATH :=	obj/

CC :=		clang

CFLAGS :=	-g3 -Wall -Wextra -Werror -fsanitize=address

IFLAGS :=	-I $(INC_PATH) -I $(LIB_PATH)

LIB :=		$(LIB_PATH)libft.a

HFILES :=	ft_ls structs

FILES :=	ft_ls flags errors	\
			sortings swap_files	\
			adding dir

HDRS :=		$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=		$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=		$(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIB) -o $(NAME)

$(LIB):
	make -C $(LIB_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)

$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)
	
fclean: mfclean
	make fclean -C $(LIB_PATH)
	
re: fclean all

mclean:
	rm -rf $(OBJ_PATH)
	
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
	
mre: mfclean all
