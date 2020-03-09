/*
** EPITECH PROJECT, 2020
** defender project
** File description:
** settings menu ui
*/

#include "../../include/my.h"
#include "../../include/settings_menu.h"



// ? Remplit le tableau du settings menu pour les boutons de résolution.

int fill_tab_res_button(game_t *game)
{
    game->button.settings_menu_tab[0][X] = 612.0;
    game->button.settings_menu_tab[0][Y] = 680.0;
    game->button.settings_menu_tab[1][X] = 862.0;
    game->button.settings_menu_tab[1][Y] = 680.0;
    game->button.settings_menu_tab[2][X] = 1122.0;
    game->button.settings_menu_tab[2][Y] = 680.0;
    return (1);
}


// ? Create rectangle shape for resolution text.

int create_rectangle_sm_text(game_t *game, sfVector2f position, int i, int size)
{
    game->game_text.rect_settings_text[i].color = sfTransparent;
    game->game_text.rect_settings_text[i].rect_size.x = size;
    game->game_text.rect_settings_text[i].rect_size.y = 80;
    game->game_text.rect_settings_text[i].rect = sfRectangleShape_create();
    sfRectangleShape_setSize(game->game_text.rect_settings_text[i].rect,
                        game->game_text.rect_settings_text[i].rect_size);
    sfRectangleShape_setFillColor(game->game_text.rect_settings_text[i].rect,
                        game->game_text.rect_settings_text[i].color);
    sfRectangleShape_setPosition(game->game_text.rect_settings_text[i].rect,
                        position);
    return (1);
}


// ? Création du etxte du settings menu suite.

int set_text_settings_menu_next(game_t *game, sfVector2f position, int size)
{
    position.x = 730;
    position.y = 430;
    create_text_settings_menu(game, "MUSIC", position, SM_MUSIC);
    position.x = 860;
    position.y = 570;
    create_text_settings_menu(game, "RESOLUTION", position, SM_RES);
    position.x = 612;
    position.y = 680;
    size = 200;
    create_rectangle_sm_text(game, position, 0, size);
    create_text_settings_menu(game, "720 * 480", position, SM_RES_DVD);
    return (1);
}
// ? Création du texte du settinsg menu.

int set_text_settings_menu(game_t *game)
{
    sfVector2f position;
    int size = 0;

    set_text_settings_menu_next(game, position, size);
    position.x = 862;
    position.y = 680;
    size = 220;
    create_rectangle_sm_text(game, position, 1, size);
    create_text_settings_menu(game, "1280 * 720", position, SM_RES_HD_READY);
    position.x = 1122;
    position.y = 680;
    size = 230;
    create_rectangle_sm_text(game, position, 2, size);
    create_text_settings_menu(game, "1920 * 1080", position, SM_RES_HD);
    fill_tab_res_button(game);
    return (1);
}


// ? Création table des options et du texte des résolutions.

int create_ui_settings_menu(game_t *game)
{
    if (!(game->menu.ui_settings_menu = malloc(sizeof(elem_t) * 2)))
        return (0);
    game->menu.ui_settings_menu[0] = create_element(
                    game->menu.ui_settings_menu[0],
                    "png/settingsmenu/settings_menu_table.png", 506.5, 218.5);
    game->menu.ui_settings_menu[1] = create_element(
                    game->menu.ui_settings_menu[1],
                    "png/settingsmenu/res_selection.png", game->window->pos,
                    760);
    if (!(game->game_text.settings_text = malloc(sizeof(string_t) * 5)))
        return (0);
    if (!(game->game_text.rect_settings_text = malloc(sizeof(rectangle_t) * 3)))
        return (0);
    set_text_settings_menu(game);
    return (1);
}