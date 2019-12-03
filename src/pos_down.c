/*
** EPITECH PROJECT, 2019
** undefined
** File description:
** new_pos.c
*/

#include <ncurses.h>
#include <stdlib.h>
#include "my.h"

void pos_down(int *x, int *y, char ch, char *map)
{
    int size = get_lenght_n(map);

    if (ch == (char)KEY_DOWN) {
        (*y)++;
        if (map[*x + *y * size] == '#')
            (*y)--;
        if (map[*x + *y * size] == 'X' && map[*x + (*y+1) * size] != '#' &&
            map[*x + (*y+1) * size] != 'X') {
            map[*x + *y * size] = ' ';
            map[*x + (*y+1) * size] = 'X';
        }
        if ((map[*x + (*y+1) * size] == '#' && map[*x + *y * size] == 'X') ||
            (map[*x + (*y+1) * size] == 'X' && map[*x + *y * size] == 'X'))
            (*y)--;
    }
    pos_left(x, y, ch, map);
}