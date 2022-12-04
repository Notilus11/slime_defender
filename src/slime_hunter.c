/*
** EPITECH PROJECT, 2022
** my_hunter
** File description:
** main
*/

#include "../includes/include.h"

void description_or_error(int argc, char** argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("The slimes from the forest are attacking the tower\n");
        my_putstr("use the mouse click to shoot at them with your bow\n");
        my_putstr("the bow have a cooldown of 5 seconds\n");
        my_putstr("if they get past you, you lose\n");
        exit(0);
    } else if (argc != 1)
        exit(84);
}

int main(int argc, char** argv)
{
    description_or_error(argc, argv);
    win_t window = init_window();
    sp_t *sp_array = malloc(sizeof(sp_t) * 20);
    sp_array = init_sprite_array(window.window, sp_array);
    sfRenderWindow_setMouseCursorVisible(window.window, sfFalse);
    game_state_loop(window, sp_array);
    sfRenderWindow_destroy(window.window);
    return 0;
}
//should destroy all before closing
//hp display using sprite of green bar with rect scale hp
//coin or clock as score
//rand to move slime at diff speed
//great if market

//coding style, to many fonction here !
