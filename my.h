/*
** EPITECH PROJECT, 2022
** bsq my.h
** File description:
** Untitled-1
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <SFML/Config.h>

#ifndef MY_H
    #define MY_H


typedef struct game {

    sfVideoMode mode;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    sfClock *cl_game;
    sfVector2f background;
    sfMusic *music1;
    int in_window;
    int page1;
    int is_hit;
    int compteur;

} game_t ;

typedef struct fish {

    sfSprite *spt_fish;
    sfTexture *txt_fish;
    sfVector2f v_fish;
    sfIntRect it_fish;
    sfVector2f pos_fish;
    int x;
    int y;

} fish_t ;

typedef struct play {

    sfSprite *spt_play;
    sfTexture *txt_play;
    sfVector2f pos_play;
    sfVector2f v_play;

} play_t ;

typedef struct menu {

    sfVideoMode mode;
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    sfVector2f background;
    int page;
    sfMusic *music2;

} menu_t ;

void init_game(game_t *game);
void init_menu(menu_t *menu);
void init_play(play_t *play);
void init_fish(fish_t *fish);
void set_menu(menu_t *menu, play_t *play, game_t *game);
void set_window(game_t *game, fish_t *fish);
void kill_fish(game_t *game, sfEvent event, play_t *play, fish_t *fish);
void hit_fish(game_t *game, sfEvent event, fish_t *fish);
void moving_fish(fish_t *fish, sfEvent event, game_t *game);
int my_putstr(char const *str);

#endif
