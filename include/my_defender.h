/*
** EPITECH PROJECT, 2020
** defedner project
** File description:
** functions
*/

#include "my.h"

#ifndef MY_DEFENDER_H_
#define MY_DEFENDER_H_

extern int (*select_game_state[8])(game_t *game);
window_t *create_window(window_t *window, char *title);
void events(game_t *game);
int disp_window(game_t *game);
void game_loop(game_t *game);
void draw(game_t *game);
int main_menu(game_t *game);
int settings_menu(game_t *game);
int in_game(game_t *game);
int pause_menu(game_t *game);
int end_menu(game_t *game);
int init_game_state_tab(game_t *game);
int create_music(game_t *game);
create_button_t create_button(create_button_t button, char *button_name,
                                                    float pos_x, float pos_y);
elem_t create_element(elem_t element, char *element_name,
                                                    float pos_x, float pos_y);
int init_struct(game_t *game);
int create_main_menu_buttons(game_t *game);
int create_main_menu_hovering_buttons(game_t *game);
int create_main_menu_onclick_buttons(game_t *game);
int create_ui_main_menu(game_t *game);
void draw_main_menu(game_t *game);
void events_main_menu(game_t *game);
int check_mouse_position_main_menu(game_t *game);
void draw_play_button_main_menu(game_t *game);
void draw_leaderboard_button_main_menu(game_t *game);
void draw_settings_button_main_menu(game_t *game);
void draw_quit_button_main_menu(game_t *game);
int leaderboard_menu(game_t *game);
int destroy_main_menu_buttons_sprite(game_t *game);
int destroy_main_menu_buttons_texture(game_t *game);
int destroy_main_menu_elements(game_t *game);
int create_leaderboard_menu_buttons(game_t *game);
int create_ui_leaderboard_menu(game_t *game);
int check_mouse_position_leaderboard_menu(game_t *game);
int events_leaderboard_menu(game_t *game);
void draw_leaderboard_menu(game_t *game);
int destroy_leaderboard_menu(game_t *game);
int change_state_cause_of_error(game_t *game);
int no_best_highscore(game_t *game);
int read_buffer(game_t *game, char *buffer);
int create_highscore_string(game_t *game);
int place_highscore_leaderboard_menu(game_t *game);
int create_score(game_t *game);
int initiate_state_button_tab(game_t *game);
int set_string_position(game_t *game);
int create_text_highscore(game_t *game, char *str);
int create_ui_settings_menu(game_t *game);
int check_mouse_position_settings_menu(game_t *game);
int events_settings_menu(game_t *game);
int create_settings_menu_buttons(game_t *game);
void draw_settings_menu(game_t *game);
int create_quit_button_settings_menu(game_t *game);
int quit_game(game_t *game);
int create_text_settings_menu(game_t *game, char *string,
                                            sfVector2f position, int pos_tab);
int set_dvd_resolution(game_t *game);
int set_hd_resolution(game_t *game);
int set_hd_ready_resolution(game_t *game);
int check_mouse_position_settings_menu(game_t *game);
int check_mouse_pos_close_button_settings_menu(game_t *game);
int check_state_when_press_sound_button(game_t *game);
int check_mouse_pos_sound_button(game_t *game);
int pregame(game_t *game);
void draw_pregame(game_t *game);
void destroy_pregame(game_t *game);
void events_pregame(game_t *game);
int ui_pregame(game_t *game);
int create_text_pregame_pattern(game_t *game, char *string,
                                            sfVector2f position, int pos_tab);
void draw_in_game(game_t *game);
void destroy_in_game(game_t *game);
int events_in_game(game_t *game);
int ui_in_game (game_t *game);
int in_game_button(game_t *game);
int create_button_pregame(game_t *game);
int set_sprite_size(game_t *game, float ratio_x, float ratio_y);
int set_sprite_position(game_t *game, float ratio_x, float ratio_y);
int set_text_position(game_t *game, float ratio_x, float ratio_y);
int is_on_rt_button(game_t *game);
int is_on_st_button(game_t *game);
int is_on_yt_button(game_t *game);
int is_on_bt_button(game_t *game);
int is_on_shop_button(game_t *game);
int is_on_pause_button(game_t *game);
int is_on_button_in_game(game_t *game);
void draw_shop_buttons(game_t *game);
void draw_bt_and_yt_towers(game_t *game);
void draw_st_and_rt_towers(game_t *game);
int open_animation_shop(game_t *game);
int resize_pregame(game_t *game);
int resize_text_pregame(game_t *game);
int resize_pregame_ui(game_t *game);
int resize_leaderboard_ui(game_t *game);
int resize_leaderboard_menu(game_t *game);
int resize_buttons_menu(game_t *game);
int set_sprite_size_settings(game_t *game);
int set_sprite_position_settings(game_t *game);
int set_text_position_settings(game_t *game);
int close_animation_shop(game_t *game);
int create_map(game_t *game);
int init_player_data(game_t *game);
int init_shop_data(game_t *game);
int create_text_ig(game_t *game);
int create_text_in_game_pattern(game_t *game, char *string,
                                            sfVector2f position, int pos_tab);
int create_entity(game_t *game);
int hold_blue_tower(game_t *game);
int hold_yellow_tower(game_t *game);
int hold_straw_tower(game_t *game);
int hold_rock_tower(game_t *game);
void draw_shop_elements(game_t *game);
int set_hd_two(game_t *game, float ratio_x, float ratio_y);
int check_tower_holding(game_t *game);
int add_node_towers(game_t *game, int wich_rect);
create_tower_t create_towers_generic_function(game_t *game, int rect);
int init_linked_list(game_t *game);
int first_node_tower(game_t *game, int rect);
add_tower_t *create_node_tower(game_t *game, int wich_rect, add_tower_t *node);
int create_rectangle_placing(game_t *game, int x, int y, int i);
int create_towers_place(game_t *game);
void draw_placed_towers(game_t *game);
void draw_pause_button_ig(game_t *game);
void draw_sprite_shot(game_t *game);
int ennemy_is_on_range(game_t *game);
void draw_map_ig(game_t *game);
int create_text_next_wave(game_t *game);
create_ennemy_t create_ennemy_generic_function(game_t *game);
char *choose_tower_file(int tower_type);
sfIntRect choose_tower_rect_when_placing(game_t *game, create_tower_t tower);
int create_node_ennemy(game_t *game, add_ennemy_t **head);
int create_wave_one(game_t *game);
int create_ennemy(game_t *game);
void draw_ennemy_wave(game_t *game);
int walk_ennemy(game_t *game);
int choose_wich_rect_to_change(game_t *game);
int check_nbr_of_img_for_ennemy(game_t *game);
int change_ennemy_rect(game_t *game);
int is_he_on_range(game_t *game);
int check_range(add_ennemy_t *tmp_ennemy, add_tower_t *tmp_tower,
                                                        sfVector2f scale);
int throw_arrow(add_ennemy_t *tmp_ennemy, add_tower_t *tmp_tower, game_t *game);
create_arrow_t create_arrow_generic_function(game_t *game, arrow_info_t info);
add_arrow_t *create_node_arrow(game_t *game, add_arrow_t *node,
arrow_info_t info);
int add_node_arrow(game_t *game, arrow_info_t info);
int move_every_arrows(game_t *game);
void blinking_wave_warning(game_t *game);
void draw_warning_wave(game_t *game);
int free_node_arrow(add_arrow_t *tmp);
int walk_through_map(game_t *game);
int hit_box_arrow(game_t *game);
int add_magic_arrow(game_t *game, arrow_info_t info, int i);
add_arrow_t *create_magic_arrow(game_t *game, add_arrow_t *node,
                                                arrow_info_t info, int i);
create_arrow_t create_magic_generic_function(game_t *game, arrow_info_t info);
int throw_magic(add_ennemy_t *tmp1, add_tower_t *tmp2, game_t *game);
create_arrow_t create_magic_generic_function_mini(game_t *game,
                                                        arrow_info_t info);
void draw_pause_menu_buttons(game_t *game);
void draw_pause_menu(game_t *game);
int choose_menu_pause_menu_button(game_t *game, int pos);
void check_mouse_position_pause_menu(game_t *game);
void events_pause_menu(game_t *game);
create_arrow_t create_magic_generic_function_mini(game_t *game,
arrow_info_t info);
int move_ennemy_at_start(game_t *game);
int get_money(game_t *game);
void destroy_node_ennemy(add_ennemy_t **head);
int free_node_ennemy(add_ennemy_t *tmp);
int is_he_out_map(game_t *game);
int resize_button(game_t *game);
int resize_pause_menu(game_t *game);
int upgrade_tower(game_t *game, int i);
int quit_upgrade_sprite(game_t *game);
int do_upgrade_tower(game_t *game);
int display_or_not_sprite_upgrade(game_t *game, int i);
int resize_ui_ig(game_t *game);
int player_is_in_tuto(game_t *game);
int is_ennemy_in_game(game_t *game);
int create_damage_tower(create_tower_t tower);
int free_node_arrow(add_arrow_t *tmp);
void destroy_node_arrow(add_arrow_t **head, game_t *game);
int condition_money_is_enough_for_upgrade(game_t *game, int is_enough);
int check_money_when_upgrade(game_t *game, add_tower_t *current);
int check_money_for_upgrade(game_t *game, add_tower_t *current);
int switch_rect(add_tower_t *current);
int moove_sprite_after_upgrade(add_tower_t *current);
int posing_tower(game_t *game, int i);
int check_mouse_upgrade_tower(game_t *game, int i);
int posing_or_upgrade_tower(game_t *game);
int has_upgrade_tower(game_t *game);
int open_set_shop_buttons_pos_after_animation(game_t *game);
int set_hover_buttons(game_t *game);
int tower_type_for_upgrade(game_t *game);
int wich_tower_type(game_t *game);
sfIntRect choose_tower_rect_when_placing(game_t *game, create_tower_t tower);
char *choose_tower_file(int tower_type);
int set_sprite_positiontwo(game_t *game, sfVector2f vector,
sfVector2f actual_position);
int set_sprite_position_settings_two(game_t *game,
sfVector2f vector, sfVector2f actual_position);
int events_end_menu(game_t *game, char *name);
void draw_end_menu(game_t *game);
void destroy_end_menu(game_t *game);
int end_menu(game_t *game);
int init_end_menu(game_t *game);
int init_ui_end_menu(game_t *game);
int init_text_end_menu(game_t *game);
int create_text_end_menu_pattern(game_t *game, char *string,
                                            sfVector2f position, int pos_tab);
int insert_lign_in_file(game_t *game);
char *create_file_lign(game_t *game, char *line, int k);
char *to_buffer(game_t *game);
int compare_score(game_t *game, int analysed, int wich_lign);
int check_score(game_t *game, int i, int j);
int analyse_high_score_file(game_t *game);
int read_highscore_file(game_t *game, char *buffer, int fd);
int read_file_score(game_t *game);
int place_in_file(game_t *game, char *name);
int set_to_string(game_t *game, char *name);
int analyse_username(game_t *game, char *name);
void draw_tuto(game_t *game);
void events_tuto(game_t *game);
int ui_pause_menu(game_t *game);
int check_if_cheat(game_t *game, char **av);
int is_everything_draw(game_t *game);
int scale_tuto(game_t *game);
int resize_leaderboard_two(game_t *game);
int alloc_path(game_t *game, float *tab);
void draw_tree(game_t *game);
void draw_false_threed(game_t *game);
void usage(void);

#endif /* !MY_DEFENDER_H_ */
