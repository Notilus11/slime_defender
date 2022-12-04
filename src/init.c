/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** init
*/

#include "../includes/include.h"

win_t init_window(void)
{
    win_t window;
    sfVideoMode mode = {1000, 600, 32};
    window.window =
    sfRenderWindow_create(mode, "slime defense", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window.window, 60);
    window.clock = sfClock_create();
    window.spawn = sfClock_create();
    window.shoot_cooldown = sfClock_create();
    sfEvent event;
    window.event = event;
    window.state = 0;
    window.slime_count = 0;
    window.slime_hp = 1;
    return window;
}

sp_t init_sprite(char *filepath, int *array)
{
    sp_t sprite;
    sprite.sp_tex = sfTexture_createFromFile(filepath, NULL);
    sprite.sp_spr = sfSprite_create();
    sfSprite_setTexture(sprite.sp_spr, sprite.sp_tex, sfTrue);
    if (array) {
        sfIntRect rect = {array[0], array[1], array[2], array[3]};
        sfVector2f new_origin = {array[4], array[5]};
        sprite.sp_rect = rect;
        sfSprite_setOrigin(sprite.sp_spr, new_origin);
        sprite.pos.x = array[6];
        sprite.pos.y = array[7];
        sfSprite_setPosition(sprite.sp_spr, sprite.pos);
        sfSprite_setTextureRect(sprite.sp_spr, sprite.sp_rect);
        sprite.hp = array[8];
        sprite.jump = 0;
        sprite.spawned = 0;
    }
    return sprite;
}

sp_t *init_sprite_array(sfRenderWindow *window, sp_t *sp_array)
{
    int arr_bow[9] = {0,0,80,80,40,40,175,335,1};
    int arr_visor[9] = {400,160,80,80,40,40,500,300,1};
    int arr_slime[9] = {0,0,80,80,0,0,1000,520,1};
    int arr_play[9] = {0,0,330,130,165,65,500,300,1};
    sp_array[0] = init_sprite("sprites/background.png", NULL);
    sp_array[1] = init_sprite("sprites/bow.png", arr_bow);
    sp_array[2] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[3] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[4] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[5] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[6] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[7] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[8] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[9] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[10] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[11] = init_sprite("sprites/slime_n_visor.png", arr_slime);
    sp_array[12] = init_sprite("sprites/button_play.png", arr_play);
    sp_array[13] = init_sprite("sprites/slime_n_visor.png", arr_visor);
    sp_array[14] = init_sprite("sprites/grass.png", NULL);
    return sp_array;
}
//better with **int and **char
