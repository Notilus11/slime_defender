/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** include
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define NULL ((void *)0)

typedef struct window_params {
    sfRenderWindow *window;
    sfClock *clock;
    sfClock *score;
    sfClock *shoot_cooldown;
    sfClock *spawn;
    sfEvent event;
    int slime_count;
    int state;
    int coin;
    int attack;
    int slime_hp;
} win_t;
//if bow upgrade attack might be useful

typedef struct sprite_params {
    sfTexture *sp_tex;
    sfSprite *sp_spr;
    sfIntRect sp_rect;
    sfVector2f pos;
    int hp;
    int jump;
    int spawned;
} sp_t;
//for jump reduce speed? need go back and forth in spsheeet so maybe go -5 to 5
//all slime waiting at 1000 520, the x first are used,
//incr x when x slime has been killed ?
//the x slimes taht are displayed need to be send at diff time not superposed
//with this 10 - 15 slimes seems already a lot as they will be reused
//so slime_arr[x] need to be reset just after his dead, with more hp ?
//sould incr hp for a round completed, like each 10 slimes or after x sec

void my_put_nbr(int nb);
void my_putstr(char const *str);
void my_putchar(int c);
win_t init_window(void);
sp_t *init_sprite_array(sfRenderWindow *window, sp_t *sp_array);
sfIntRect init_rect(int top, int left, int width, int height);
void analyse_events(win_t *win, sp_t *sp_array);
void movement(sp_t *slime, win_t *win);
void game_state_loop(win_t win, sp_t *sp_array);
float get_bow_angle(sfRenderWindow *window);
sfVector2f get_mouse_pos(sfRenderWindow *window);
