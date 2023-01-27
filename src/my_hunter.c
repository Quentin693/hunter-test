/*
** EPITECH PROJECT, 2022
** B-MUL-100-LYN-1-1-myhunter-quentin.cialone
** File description:
** my_hunter.c
*/

#include "../my.h"

void gestion_event(game_t *game, sfEvent event, play_t *play, menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(menu->window);
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window);
        if (mouse.x >= 158 && mouse.x <= 502 && mouse.y >= 897
        && mouse.y <= 1000 &&
        sfMouse_isButtonPressed(sfMouseLeft)) {
            menu->page = 1;
        }
    }
}

void musique(sfEvent event, game_t *game, menu_t *menu)
{
    if (!game->in_window) {
        sfMusic_stop(menu->music2);
        sfMusic_play(game->music1);
    }
}

void all(fish_t *fish, game_t *game, menu_t *menu, play_t *play)
{
    init_menu(menu);
    init_game(game);
    init_fish(fish);
    init_play(play);
    sfMusic_play(menu->music2);
}

int presentation(void)
{
    my_putstr("echap = quitter le jeu\n");
    my_putstr("clic gauche = toucher le poisson pour le tuer \n");
    my_putstr("Le but du jeu est de tirer sur des poissons\n");
    my_putstr("Plus on touche de poissons plus leur vitesse augmente\n");
    my_putstr("Il faut également avoir le meilleur score\n");
    my_putstr("Toutefois, faite attention le monde marin");
    my_putstr("est rempli de créatures..\n");
    return 0;
}

int main(int argc, char **argv)
{
    sfEvent event; 
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        return presentation();
    menu_t *menu = malloc(sizeof(menu_t));
    game_t *game = malloc(sizeof(game_t));
    fish_t *fish = malloc(sizeof(fish_t));
    play_t *play = malloc(sizeof(play_t));
    all(fish, game, menu, play);
    while (sfRenderWindow_isOpen(game->window)) {
        gestion_event(game, game->event, play, menu);
        if (menu->page == 0) {
            set_menu(menu, play, game);
        } else {
            musique(event, game, menu);
            game->in_window = 1;
            set_window(game, fish);
            moving_fish(fish, event, game);
            kill_fish(game, event, play, fish);
        }
    } sfMusic_stop(game->music1);
    return 0;
}
