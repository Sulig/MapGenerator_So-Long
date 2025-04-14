# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 17:25:36 by sadoming          #+#    #+#              #
#    Updated: 2025/04/14 18:44:32 by sadoming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## EDITABLE VARIABLES
##	The directory where the *.ber will be saved
MAPDIR	= GeneratedMaps
##	Number of maps to create (each one in diferent file)
MAPNUM	= 5
# ------------------ #

##	Ejecutable file name
NAME		:= map_gen
# ------------------ #

### DO NOT TOUCH BELLOW THIS LINE ###
############################################################################################
# ------------------ #
# Flags:

MAKF 		+=	--silent

CC			=	gcc
CFLAGS		:=	-Wall -Werror -Wextra -g -c #-fsanitize=address
# ------------------ #
# Colors

R	:=	\033[0;31m
G	:=	\033[0;32m
Y	:=	\033[0;33m
B	:=	\033[0;34m
P	:=	\033[0;35m
C	:=	\033[0;36m
W	:=	\033[0;37m
DEF	:=	\033[0m

RG	:=	\033[1;32m
# ------------------ #
# Directories:

# SRC DIR
SRC_DIR		:=	./src/
INC_DIR		:=	./inc
OBJ_DIR		:=	./obj

# Libft DIR
LIB_DIR		:=	./New_Libft
LIB_INC		:=	$(LIB_DIR)/inc
LIB_LIB		:=	$(LIB_DIR)/libft.a

# Sorces:
SRC_SRC	:=	map_generator_main.c print_errors.c init_map_vars.c\
			generate_map.c randomRange.c print_map_t.c \
			check_map_sol.c

SRC := $(addprefix $(SRC_DIR), $(SRC_SRC))

OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)/%.d, $(SRC))
-include $(DEPS)

# More deps...
vpath %.h $(INC_DIR) $(LIB_INC)
vpath %.c $(SRC_DIR)
vpath %.o $(OBJ_DIR)
# ******************************************************************************* #
#-------------------------------------------------------------#
all: $(LIB_LIB) $(NAME)
	@make -C $(LIB_DIR)
	@echo "$(RG)\n~ **************************************** ~"
	@echo "  ~\t     $(NAME) is ready!\t\t ~"
	@echo "~ **************************************** ~$(DEF)\n"
	@make -s author

# ----
libft:
	@echo "$(Y)Checking if Libft exist...$(DEF)"
	@if [ -d "New_Libft" ]; then \
		echo "$(DEF)Dir exists, aborting cloning...\n"; \
	else \
		echo "$(B)Clonning ... $(DEF)"; \
		git clone https://github.com/Sulig/New_Libft.git; \
	fi
#-------------------------------------------------------------#
author:
	@echo "\n$(P)~ **************************************** ~"
	@echo " ~\t      Made by Sadoming \t         ~"
	@echo "~ **************************************** ~$(DEF)\n"
#-------------------------------------------------------------#
help:
	@echo "\033[1;37m\n ~ Posible comands:\n"
	@echo "\t~ \t\t\t #-> Make $(NAME)\n"
	@echo "\t~ all  \t\t #-> Make $(NAME)\n"
	@echo "\t~ libft \t #-> Make Libft\n"
	@echo "\t~ gen  \t\t #-> Generate $(MAPNUM) maps\n"
	@echo "\t~ clean \t #-> Clean *.o\n"
	@echo "\t~ fclean \t #-> Clean all\n"
	@echo "\t~ clear \t #-> Clean all & clear\n"
	@echo "\t~ norm \t\t #-> Run norminette\n"
	@echo "\t~ re   \t\t #-> Redo $(NAME)\n"
	@make -s author
#-------------------------------------------------------------#
norm:
	@echo "\n$(Y)~ Norminette:\n"
	@make -s norm -C $(LIB_DIR)
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(INC_DIR)
	@echo "\n~~~~~~~~~~~~~~~~~~~~~~\n"
	@norminette $(SRC_DIR) $(INC_DIR)
	@echo "$(G)\n ~ Norminette:\t~ OK\n"
	@echo "~~~~~~~~~~~~~~~~~~~~~~$(DEF)\n"
#-------------------------------------------------------------#
gen: all $(NAME)
	@if [ -d $(MAPDIR) ]; then \
		echo "$(DEF)OK! Dir exists\n"; \
	else \
		mkdir -p $(MAPDIR); \
	fi
	@echo "$(C)\n~ **************************************** ~"
	@echo " ~ Generating $(MAPNUM) maps in $(MAPDIR)"
	@echo "~ **************************************** ~ $(DEF)\n"
	@./$(NAME) $(MAPDIR) $(MAPNUM)
#-------------------------------------------------------------#
# ******************************************************************************* #
# Compiling Region:

#Libft
$(LIB_LIB): libft
	@make -C $(LIB_DIR)

#-------------------------------------------------------------#
# Objs
$(OBJ_DIR)/%.o: $(SRC_DIR)%.c $(MAK) $(LIB_LIB)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -I $(LIB_INC) $< -o $@

# Executable
$(NAME): $(OBJS) $(LIB_LIB)
	@$(CC) $(OBJS) $(LIB_LIB) -o $(NAME)
	@echo "$(G)\n~ $(NAME) Compiled Successfully ~"
#-------------------------------------------------------------#
# ********************************************************************************* #
# Debug region

val: $(NAME)
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

val_s: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

#-----------#
debug: re
	@echo "$(C)\n~ **************************************** ~\n"
	@echo " ~ lldb will launch ´./$(NAME)´"
	@echo "\n~ **************************************** ~ $(DEF)\n"
	@lldb $(NAME)

# ********************************************************************************* #
# Clean region

clean:
	@/bin/rm -frd $(OBJ_DIR)
	@make -s clean -C $(LIB_DIR)
	@echo "$(B)\n All objs & deps removed$(DEF)\n"

fclean: clean
	@make -s fclean -C $(LIB_DIR)
	@/bin/rm -f $(NAME)
	@/bin/rm -frd $(NAME).dSYM
	@echo "$(B)\n All cleaned succesfully$(DEF)\n"

clear: fclean
	@clear

remove-libft: clear
	@rm -rf $(LIB_DIR)
	@echo "$(B)\n Libft removed$(DEF)\n"
	@echo "$(C)\tReady!$(DEF)\n"

re: fclean all
re-bonus: fclean bonus
# -------------------- #
.PHONY: all author clean fclean libft norm re remove-libft run val val_s
# ********************************************************************************** #
