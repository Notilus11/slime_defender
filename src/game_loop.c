/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** game loop
*/

#include "../includes/include.h"

void main_menu(win_t *win, sp_t *sp_array)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event))
        analyse_events(win, sp_array);
    sfVector2f mouse_pos = get_mouse_pos(win->window);
    sfSprite_setPosition(sp_array[13].sp_spr, mouse_pos);
    sfSprite_setRotation(sp_array[1].sp_spr, get_bow_angle(win->window));
    for (int i = 0; i < 14; i++)
        sfRenderWindow_drawSprite(win->window, sp_array[i].sp_spr, NULL);
    sfRenderWindow_display(win->window);
    sfRenderWindow_clear(win->window, sfBlack);
}

void playing_state(win_t *win, sp_t *sp_array)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event))
        analyse_events(win, sp_array);
    for (int i = 2; i < 12; i++) {
        if (sp_array[i].hp == 0 && sp_array[i].sp_rect.left == 160) {
            sp_array[i].hp = win->slime_hp;
            sp_array[i].pos.x = 1000;
            sp_array[i].spawned = 0;
        }
    }
    sfTime time = sfClock_getElapsedTime(win->clock);
    if (time.microseconds / 100000 > 1) {
        for (int i = 2; i < 12; i++) {
            movement(&sp_array[i], win);
        }
        sfClock_restart(win->clock);
    }
    sfVector2f mouse_pos = get_mouse_pos(win->window);
    sfSprite_setPosition(sp_array[13].sp_spr, mouse_pos);
    sfSprite_setRotation(sp_array[1].sp_spr, get_bow_angle(win->window));
    for (int i = 0; i < 14; i++)
        sfRenderWindow_drawSprite(win->window, sp_array[i].sp_spr, NULL);
    sfRenderWindow_display(win->window);
    sfRenderWindow_clear(win->window, sfBlack);
}
//sftext of 5 - elapsed time for bow cooldown

void game_over(win_t *win)
{
    sfRenderWindow_close(win->window);
}
//should display a game over w/ score and close or restart on event

void game_state_loop(win_t win, sp_t *sp_array)
{
    while (sfRenderWindow_isOpen(win.window)) {
        if (win.state == 0)
            main_menu(&win, sp_array);
        if (win.state == 1)
            playing_state(&win, sp_array);
        if (win.state == 2)
            game_over(&win);
    }
}
