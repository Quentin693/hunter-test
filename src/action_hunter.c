/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-quentin.cialone
** File description:
** action_hunter.c
*/

#include "../my.h"

void animate_fish(game_t *game, sfEvent event, play_t *play, fish_t *fish)
{
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->cl_game)) > 0.05) {
        if (fish->it_fish.left == 1494) {
            fish->it_fish.left = 0;
        } else {
            fish->it_fish.left += 498;
        }
        fish->y -= 50;
        fish->pos_fish = (sfVector2f){fish->x, fish->y};
        sfSprite_setPosition(fish->spt_fish, fish->pos_fish);
        sfSprite_setTextureRect(fish->spt_fish, fish->it_fish);
        sfClock_restart(game->cl_game);
        if (fish->y < -130)
            game->is_hit = 3;
    }
}

void kill_fish(game_t *game, sfEvent event, play_t *play, fish_t *fish)
{
    if (game->is_hit == 1) {
        sfSprite_setRotation(fish->spt_fish, 180);
        sfClock_restart(game->cl_game);
        game->is_hit = 2;
    }
    if (game->is_hit == 2) {
        animate_fish(game, event, play, fish);
    }
    if (game->is_hit == 3) {
        fish->y = rand() % 900;
        fish->x = 1900;
        fish->pos_fish = (sfVector2f){fish->x, fish->y};
        game->is_hit = 0;
        sfSprite_setRotation(fish->spt_fish, 0);
    }
}


void hit_fish(game_t *game, sfEvent event, fish_t *fish)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(game->window);
    if ((mouse.x >= fish->pos_fish.x && mouse.x <= fish->pos_fish.x + 200)
    && (mouse.y >= fish->pos_fish.y && mouse.y <= fish->pos_fish.y + 130)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            game->compteur += 1;
            game->is_hit = 1;
        }
    }
}

void moving_fish(fish_t *fish, sfEvent event, game_t *game)
{
    if (game->is_hit != 0)
        return;
    if (fish->x < 0) {
        fish->x = 1800;
        fish->y = rand() % 900;
    }
    if (sfTime_asSeconds(sfClock_getElapsedTime(game->cl_game)) > 0.01) {
        if (fish->it_fish.left == 1494) {
            fish->it_fish.left = 0;
        } else {
            fish->it_fish.left += 498;
        }
        fish->x -= 10 + game->compteur;
        fish->pos_fish = (sfVector2f){fish->x, fish->y};
        hit_fish(game, event, fish);
        sfSprite_setPosition(fish->spt_fish, fish->pos_fish);
        sfSprite_setTextureRect(fish->spt_fish, fish->it_fish);
        sfClock_restart(game->cl_game);
    } sfSprite_setRotation(fish->spt_fish, 0);
    set_window(game, fish);
}
