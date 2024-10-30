# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnakajo <tnakajo@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/10 14:26:33 by bschneid          #+#    #+#              #
#    Updated: 2024/10/30 15:34:42 by tnakajo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
BONUS = cub3D_bonus
MUSIC = cub3D_music
HEADER = header/cub3D.h
LIBFT = src/0_Libft_extended
LIBMLX	:= MLX42
LIBMUSIC	:=	miniaudio
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -L./$(LIBFT) -lft
SRC_DIR = src
IN = src/1_Parse_init
RC = src/2_Ray_casting
IH = src/3_Input_handling
GR = src/4_Graphics
CO = src/5_Colors
OT = src/6_Others
BO = src/7_Bonus
AN = src/8_Animation
# MS = src/9_Music
OBJ_DIR = obj
SOURCES = src/main.c \
		$(IN)/init_data.c $(IN)/init_image.c\
		$(IN)/init_map.c $(IN)/init_zone.c \
		$(IH)/hooks.c $(IH)/calc_new_frame.c $(RC)/raycast.c\
		$(GR)/load_textures.c $(GR)/load_textures_bonus.c $(GR)/wall_slices.c\
		$(GR)/draw_enemies.c\
		$(CO)/coloring.c\
		$(OT)/free.c $(OT)/error.c $(OT)/utilities.c \
		$(BO)/init_door.c $(BO)/init_pumpkin_candy.c $(BO)/init_minimap.c $(BO)/life.c \
		$(BO)/draw_minimap.c $(BO)/draw_player_dir.c \
		$(AN)/anim_textures.c $(AN)/life_hearts.c

SOURCES_MU = src/main_music.c \
		$(IN)/init_data.c $(IN)/init_image.c\
		$(IN)/init_map.c $(IN)/init_zone.c \
		$(IH)/hooks.c $(IH)/calc_new_frame.c $(RC)/raycast.c\
		$(GR)/load_textures.c $(GR)/load_textures_bonus.c $(GR)/wall_slices.c\
		$(GR)/draw_enemies.c\
		$(CO)/coloring.c\
		$(OT)/free.c $(OT)/error.c $(OT)/utilities.c \
		$(BO)/init_door.c $(BO)/init_pumpkin_candy.c $(BO)/init_minimap.c $(BO)/life.c \
		$(BO)/draw_minimap.c $(BO)/draw_player_dir.c \
		$(AN)/anim_textures.c $(AN)/life_hearts.c
# SOURCES = src/test_my_life.c
GIT_MLX		=	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX)
GIT_MUSIC	=	git clone https://github.com/mackron/miniaudio $(LIBMUSIC)

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))
OBJECTS_MU = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES_MU))
FLAGS = -Wall -Werror -Wextra -g3

all:	libmlx	$(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	cc $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(HEADER) $(LIBFT)/libft.a
	cc $(FLAGS) $(OBJECTS) -o $@ $(LIBS)
	cp ./images/magic_walls/wall_e.png ./images/magic_walls/magic_wall_e.png
	cp ./images/magic_walls/wall_n.png ./images/magic_walls/magic_wall_n.png
	cp ./images/magic_walls/wall_s.png ./images/magic_walls/magic_wall_s.png
	cp ./images/magic_walls/wall_w.png ./images/magic_walls/magic_wall_w.png
	# -L/path/to/MLX42/build	# optional
	@echo "Try $$ ./$(NAME) ./map/map00.cub"

$(LIBFT)/libft.a:
	$(MAKE) -C $(LIBFT) -f Makefile bonus
	$(MAKE) -C $(LIBFT) -f Makefile clean

clean:
	rm -rf $(OBJ_DIR)

bonus:	FLAGS += -D BONUS=1
bonus:	libmlx	$(BONUS)

music:	FLAGS += -D BONUS=1 -D MUSIC=1
music:	libmlx	$(MUSIC)

$(BONUS): $(OBJECTS) $(HEADER) $(LIBFT)/libft.a
	cc $(FLAGS) $(OBJECTS) -o $@ $(LIBS)
	cp ./images/magic_walls/bonus_e.png ./images/magic_walls/magic_wall_e.png
	cp ./images/magic_walls/bonus_n.png ./images/magic_walls/magic_wall_n.png
	cp ./images/magic_walls/bonus_s.png ./images/magic_walls/magic_wall_s.png
	cp ./images/magic_walls/bonus_w.png ./images/magic_walls/magic_wall_w.png
	@echo "Try $$ ./$(BONUS) ./map/map10.cub"

$(MUSIC): $(OBJECTS_MU) $(HEADER) $(LIBFT)/libft.a
	cc $(FLAGS) $(OBJECTS_MU) -o $@ $(LIBS)
	cp ./images/magic_walls/bonus_n.png ./images/magic_walls/magic_wall_n.png
	cp ./images/magic_walls/halloween_e.png ./images/magic_walls/magic_wall_e.png
	cp ./images/magic_walls/halloween_s.png ./images/magic_walls/magic_wall_s.png
	cp ./images/magic_walls/halloween_w.png ./images/magic_walls/magic_wall_w.png && clear
	@echo "Welcome to the 42 Halloween party!"
	@echo "Try $$ ./$(MUSIC) ./map/map10.cub"

fclean:	clean
	rm -f $(NAME)
	rm -f $(BONUS)
	rm -f $(MUSIC)
	rm -f $(LIBFT)/libft.a
	# rm -rf $(LIBMLX)/build

re:	fclean all

download_mlx42:
	$(GIT_MLX)
	cd $(LIBMLX) && cmake -B build
	cd $(LIBMLX) && cmake --build build -j4
	@echo "Now you do is: $$ make && ./$(NAME) ./map/map00.cub"

delete_mlx42:
	rm -rf $(LIBMLX)

download_music:
	$(GIT_MUSIC)
	@echo "Now you do is: $$ make music && ./$(MUSIC) ./map/map10.cub"

delete_music:
	rm -rf $(LIBMUSIC)

.PHONY:	all bonus clean fclean re libmlx
