#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: lgiacalo <marvin@42.fr>                    +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/12/19 22:14:00 by lgiacalo          #+#    #+#             *#
#*   Updated: 2017/09/01 00:52:40 by lgiacalo         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#


NAME		= wolf3d


################################################################################


CC			= gcc  
CFLAGS		= -Wall -Wextra -Werror #-Wpadded
CPPFLAGS	= -Iinclude -Ilibft/include
OPT			=

COLOR		= \033[31m
FINCOLOR	= \033[0m

SPY			=  


################################################################################


SRC_PATH	=	src

INC_PATH	=	include

OBJ_PATH	=	obj

SRC_NAME	=	main.c ft_file.c ft_check_file.c\
				ft_wolf.c fonctions.c\
				boucle.c hook.c\
				mouvement.c draw.c

INC_NAME	=	wolf3d.h

OBJ_NAME	=	$(SRC_NAME:.c=.o)


################################################################################


SRC	= $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ	= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
INC	= $(addprefix $(INC_PATH)/,$(INC_NAME))

LIB		= libft/libft.a
MINI	=  minilibx_macos/libmlx.a

FRAME	= -lmlx -framework OpenGL -framework AppKit -lpthread

################################################################################

OPT =

ifeq ($(DEBUG), info)
	OPT += -g
endif
ifeq ($(DEBUG), alloc)
	OPT += -g -fsanitize=address
endif
ifeq ($(DEBUG), opti)
	OPT += -O3
endif
	
export OPT

################################################################################

all: .lib $(NAME)

ifeq ($(DEBUG), yes)
	$(SPY)echo "================ DEBUG avec $(OPT) ! ================"
else ifeq ($(ALLOC), yes)
	$(SPY)echo "=========== ALLOC verification avec $(OPT) ! =========="
endif


$(OBJ_PATH): 
	$(SPY)mkdir $(OBJ_PATH) 2> /dev/null || true 

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INC) $(LIB)
	$(SPY)$(CC) $(OPT) $(CFLAGS) $(CPPFLAGS) -c $< -o $@ 

$(NAME):  $(OBJ_PATH) $(OBJ) $(LIB) 
	$(SPY)make -C minilibx_macos/
	$(SPY)$(CC) $(OPT) -o $(NAME) $(OBJ) $(LIB) $(MINI) $(FRAME)
	$(SPY)echo "$(COLOR)$(NAME)\t\t[OK]$(FINCOLOR)"

.lib :
	$(SPY)make -C libft/

clean:
	$(SPY)make clean -C libft/
	$(SPY)make clean -C minilibx_macos/
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)$(NAME)\t\t\tSuppression *.o$(FINCOLOR)"

fclean:
	$(SPY)make fclean -C libft/
	$(SPY)make clean -C minilibx_macos/
	$(SPY)/bin/rm -rf $(OBJ)
	$(SPY)rmdir $(OBJ_PATH) 2> /dev/null || true
	$(SPY)echo "$(COLOR)$(NAME)\t\tSuppression *.o$(FINCOLOR)"
	$(SPY)/bin/rm -rf $(NAME)
	$(SPY)echo "$(COLOR)$(NAME)\t\tSuppression fractol$(FINCOLOR)"

re: fclean all

norme:
	$(SPY)echo "$(COLOR)\tNORMINETTE : $(NAME)\n$(FINCOLOR)"
	$(SPY)norminette $(SRC)
	$(SPY)norminette include/*.h
	$(SPY)make norme -C libft/


.PHONY : all clean fclean re norme

################################################################################
