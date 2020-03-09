##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		src/main.c			\
				src/create_window.c	\
				src/main_menu/main_menu.c		\
				src/create_button.c	\
				src/create_element.c	\
				src/main_menu/create_main_menu_buttons.c	\
				src/main_menu/create_ui_main_menu.c	\
				src/main_menu/events_main_menu.c		\
				src/main_menu/draw_main_menu_bouttons.c	\
				src/main_menu/draw_main_menu.c			\
				src/main_menu/destroy_main_menu.c	\
				src/main_menu/quit_with_quit_button_main_menu.c	\
				src/leaderboard_menu/leaderboard_menu.c		\
				src/leaderboard_menu/create_buttons_leaderboard_menu.c	\
				src/leaderboard_menu/create_ui_leaderboard_menu.c	\
				src/leaderboard_menu/events_leaderboard_menu.c	\
				src/leaderboard_menu/draw_leaderboard_menu.c	\
				src/leaderboard_menu/destroy_leaderboard_menu.c	\
				src/leaderboard_menu/create_score_leaderboard_menu.c	\
				src/leaderboard_menu/create_highscore_text.c	\
				src/settings_menu/settings_menu.c	\
				src/settings_menu/destroy_settings_menu.c		\
				src/settings_menu/draw_settings_menu.c	\
				src/settings_menu/create_ui_settings_menu.c		\
				src/settings_menu/events_settings_menu.c		\
				src/settings_menu/create_buttons_settings_menu.c	\
				src/settings_menu/create_text_settings_menu.c	\
				src/settings_menu/check_mouse_pos_close_and_sound_sm.c	\
				src/settings_menu/resolution_dvd.c	\
				src/settings_menu/resolution_hd_ready.c	\
				src/settings_menu/resolution_hd.c	\
				src/in_game/pregame/pregame.c		\
				src/in_game/pregame/draw_pregame.c	\
				src/in_game/pregame/destroy_pregame.c	\
				src/in_game/pregame/events_pregame.c	\
				src/in_game/pregame/ui_pregame.c	\
				src/in_game/pregame/create_text_pregame.c	\
				src/in_game/pregame/tuto.c	\
				src/in_game/game/in_game.c		\
				src/in_game/game/text_init_next_wave.c	\
				src/in_game/game/buttons_in_game.c	\
				src/in_game/game/ui_in_game.c	\
				src/in_game/game/events_in_game.c	\
				src/in_game/game/events_shop_button.c	\
				src/in_game/game/destroy_in_game.c	\
				src/in_game/game/draw_in_game.c	\
				src/in_game/game/open_animation_shop_button.c	\
				src/in_game/game/close_animation_shop_button.c	\
				src/in_game/game/text_init_player_data_in_game.c	\
				src/in_game/game/create_entity.c	\
				src/in_game/game/hold_tower.c	\
				src/in_game/game/draw_shop_in_game.c	\
				src/in_game/game/draw_towers_in_game.c	\
				src/in_game/game/holding_tower_in_game.c	\
				src/in_game/game/create_tower_in_game.c	\
				src/in_game/game/create_tower_function.c	\
				src/in_game/game/init_shop_and_player_data.c \
				src/in_game/game/draw_pause_button_and_map.c	\
				src/in_game/game/draw_towers_elements_ig.c	\
				src/in_game/game/ennemy_is_on_range.c	\
				src/in_game/game/create_ennemy_function.c	\
				src/in_game/game/choose_wich_wave_to_create.c	\
				src/in_game/game/draw_ennemy.c	\
				src/in_game/game/change_ennemy_rect.c	\
				src/in_game/game/draw_warning_wave_text.c	\
				src/in_game/game/walk_through_map.c	\
				src/in_game/pause_menu/pause_menu.c	\
				src/in_game/pause_menu/draw_pause_menu.c	\
				src/in_game/pause_menu/event_pause_menu.c	\
				src/in_game/game/free_node_arrow_ennemy.c	\
				src/in_game/game/node_magic.c	\
				src/in_game/game/node_arrow.c	\
				src/in_game/game/throw_projectiles.c	\
				src/in_game/game/move_arrow.c	\
				src/in_game/game/player_get_money.c	\
				src/in_game/game/upgrade_tower.c	\
				src/in_game/game/check_if_enough_money_upgrade.c	\
				src/in_game/game/check_and_moove_rect_upgrade.c	\
				src/in_game/game/events_towers.c	\
				src/in_game/game/create_tower_check.c	\
				src/in_game/game/walking.c	\
				src/in_game/game/open_shop_button_set_position.c	\
				src/in_game/end_menu/end_menu.c	\
				src/in_game/end_menu/draw_end_menu.c	\
				src/in_game/end_menu/event_end_menu.c	\
				src/in_game/end_menu/destory_end_menu.c	\
				src/in_game/end_menu/ui_end_menu.c	\
				src/in_game/end_menu/file_to_tab.c	\
				src/in_game/end_menu/tab_to_score.c	\
				src/in_game/pregame/events_tuto.c	\
				src/in_game/pause_menu/create_ui_pause_menu.c	\
				src/in_game/pregame/draw_tuto.c	\
				src/cheat.c	\

NAME	=		my_defender

OBJ		=		$(SRC:.c=.o)

CFLAGS	=		-I./include	\
				-Wall	\
				-g

OFLAGS	=		-O2

LDFLAGS	= 	-lcsfml-graphics \
			-lcsfml-system \
			-lcsfml-window \
			-lcsfml-audio \
			-lm \

$(NAME):	$(OBJ)
		@$(MAKE)	-s -C	lib/my
		@clang -o $(NAME) $(OBJ) $(LDFLAGS) $(OFLAGS) -Llib/ -lmy

all:	$(NAME)

.PHONY:	clean

clean:
		@rm -f $(OBJ)
		@$(MAKE) -s -C lib/my clean

fclean:	clean
		@echo "###############################"
		@echo "#Removing lib and vgcore files#"
		@echo "##############################"
		@rm -f $(NAME)
		@$(MAKE) -s -C lib/my fclean
		@rm -f vgcore*

re: fclean all
