/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** move
*/

#include "../includes/include.h"

void move_rect(sp_t *slime, int offset, int max_value)
{
    if (slime->sp_rect.left >= max_value - offset)
        slime->sp_rect.left = 0;
    else
        slime->sp_rect.left += offset;
}

int new_slime(sp_t *slime, sfClock *spawn, int sl_count)
{
    sfTime time = sfClock_getElapsedTime(spawn);
    if (time.microseconds / 100000 > 40) {
        slime[sl_count].spawned = 1;
        sfClock_restart(spawn);
        return 1;
    }
    return 0;
}

void movement(sp_t *slime, win_t *win)
{
    int speed = 10;
    if (new_slime(slime, win->spawn, win->slime_count) == 1)
        win->slime_count++;
    if (win->slime_count == 10) {
        win->slime_count = 0;
        win->slime_hp++;
    }
    if (slime->hp <= 0) {
        slime->sp_rect.top = 160;
        move_rect(slime, 80, 240);
    } else {
        slime->sp_rect.top = 0;
        move_rect(slime, 80, 160);
    }
    if (slime->spawned == 1)
        slime->pos.x -= speed;
    if (slime->pos.x < 0 && slime->hp != 0) {
        //win->state++;
    }
    sfSprite_setPosition(slime->sp_spr, slime->pos);
    sfSprite_setTextureRect(slime->sp_spr, slime->sp_rect);
}
