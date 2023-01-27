/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-quentin.cialone
** File description:
** init_hunter.c
*/

#include "../my.h"

void init_game(game_t *game)
{
    game->mode = (sfVideoMode){1920, 1080, 32};
    game->window = sfRenderWindow_create(game->mode, "f", sfFullscreen, NULL);
    game->sprite = sfSprite_create();
    game->texture = sfTexture_createFromFile("./assets/back.jpg", NULL);
    game->background = (sfVector2f){0.5, 0.5};
    sfSprite_setTexture(game->sprite, game->texture, sfFalse);
    game->page1 = 1;
    game->cl_game = sfClock_create();
    game->music1 = sfMusic_createFromFile("./assets/music.ogg");
    game->is_hit = 0;
    game->compteur = 0;
}

void init_menu(menu_t *menu)
{
    int in_window = 0;
    menu->mode = (sfVideoMode){1920, 1080, 32};
    menu->sprite = sfSprite_create();
    menu->texture = sfTexture_createFromFile("./assets/menu.png", NULL);
    menu->background = (sfVector2f){0.5, 0.5};
    sfSprite_setTexture(menu->sprite, menu->texture, sfFalse);
    menu->page = 0;
    menu->music2 = sfMusic_createFromFile("./assets/pirate.ogg");
}

void init_play(play_t *play)
{
    play->spt_play = sfSprite_create();
    play->txt_play = sfTexture_createFromFile("./assets/play.png", NULL);
    play->v_play = (sfVector2f){0.3, 0.3};
    play->pos_play = (sfVector2f){150, 900};
    sfSprite_setScale(play->spt_play, play->v_play);
    sfSprite_setPosition(play->spt_play, play->pos_play);
    sfSprite_setTexture(play->spt_play, play->txt_play, sfFalse);
}

void init_fish(fish_t *fish)
{
    fish->spt_fish = sfSprite_create();
    fish->txt_fish = sfTexture_createFromFile("./assets/fish.png", NULL);
    fish->v_fish = (sfVector2f){0.4, 0.4};
    fish->pos_fish = (sfVector2f){1720, rand() % 1080};
    fish->it_fish = (sfIntRect){0, 0, 498, 327};
    fish->x = 1750;
    fish->y = rand() % 800;
    sfSprite_setTexture(fish->spt_fish, fish->txt_fish, sfFalse);
    sfSprite_setTextureRect(fish->spt_fish, fish->it_fish);
}
