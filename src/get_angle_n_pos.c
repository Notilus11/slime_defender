/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** angle n mouse pos
*/

#include "../includes/include.h"

float get_bow_angle(sfRenderWindow *window)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (mouse.x < 175) {
        if (mouse.y < 335)
            return -90;
        return 90;
    }
    float adj = mouse.x - 175;
    float opp = mouse.y - 335;
    float angle = atan(opp / adj) * (180 / PI);
    return angle + 5;
}

sfVector2f get_mouse_pos(sfRenderWindow *window)
{
    sfVector2f mouse_pos;
    mouse_pos.x = sfMouse_getPositionRenderWindow(window).x;
    mouse_pos.y = sfMouse_getPositionRenderWindow(window).y;
    return mouse_pos;
}
