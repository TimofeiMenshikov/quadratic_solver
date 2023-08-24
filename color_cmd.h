#ifndef COLOR_CMD_H
#define COLOR_CMD_H

#ifdef COLOR_COMANDLINE

#include <windows.h>

enum colors_enum
{
    red         =   4,
    light_green =  10,
    white       =  15
};

void color_cmd(short unsigned int text_color);
void remove_color_cmd();


#endif /* COLOR_COMANDLINE */

#endif /* COLOR_CMD_H */