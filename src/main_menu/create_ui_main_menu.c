/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** ui design
*/

#include "../../include/my.h"

int create_ui_main_menu(game_t *game)
{
    if (!(game->menu.ui_main_menu = malloc(sizeof(elem_t))))
        return (0);
    game->menu.ui_main_menu[BACK] = create_element(
        game->menu.ui_main_menu[BACK], "png/mainmenu/table.png", 640.5, 139.5);
    return (1);
}
