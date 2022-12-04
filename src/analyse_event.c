/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** events
*/

#include "../includes/include.h"

void slime_kill(sfMouseButtonEvent mouse, sfClock *cooldown, sp_t *slime)
{
    sfTime time = sfClock_getElapsedTime(cooldown);
    if (time.microseconds / 100000 > 50) {
        if (mouse.y > 520 && mouse.x >= slime->pos.x
        && mouse.x <= slime->pos.x + 80 && mouse.x > 200) {
            slime->hp--;
            slime->sp_rect.left = -80;
            sfClock_restart(cooldown);
        }
    }
}
//market could reduce the cooldown

void play_pressed(sfMouseButtonEvent mouse, win_t *win, sp_t *sp_array)
{
    if (mouse.y > 235 && mouse.y < 365
    && mouse.x > 335 && mouse.x < 665 && win->state == 0) {
        win->state++;
        sp_array[12].pos.x = 1165;
        sp_array[12].pos.y = 665;
        sfSprite_setPosition(sp_array[12].sp_spr, sp_array[12].pos);
    }
}

void analyse_events(win_t *win, sp_t *sp_array)
{
    if (win->event.type == sfEvtClosed)
        sfRenderWindow_close(win->window);
    if (win->event.type == sfEvtKeyPressed) {
        if (win->event.key.code == sfKeyEscape)
            sfRenderWindow_close(win->window);
    }
    if (win->event.type == sfEvtMouseButtonPressed) {
        for (int i = 2; i < 12; i++)
            slime_kill(win->event.mouseButton, win->shoot_cooldown, &sp_array[i]);
        play_pressed(win->event.mouseButton, win, sp_array);
    }
}
