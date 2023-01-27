/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-quentin.cialone
** File description:
** set_hunter.c
*/

#include "../my.h"

void set_window(game_t *game, fish_t *fish)
{
    sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
    sfSprite_setScale(fish->spt_fish, fish->v_fish);
    sfRenderWindow_drawSprite(game->window, fish->spt_fish, NULL);
    sfRenderWindow_display(game->window);
}

void set_menu(menu_t *menu, play_t *play, game_t *game)
{
    sfRenderWindow_drawSprite(game->window, menu->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, play->spt_play, NULL);
    sfRenderWindow_display(game->window);
}
