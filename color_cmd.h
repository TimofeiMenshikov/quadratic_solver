/*!
\file
contains function calls and enum related to color painting on the command line
*/


#ifndef COLOR_CMD_H
#define COLOR_CMD_H

    #ifdef COLOR_COMANDLINE

        #include <windows.h>



        void color_cmd(short unsigned int text_color);
        void remove_color_cmd();



    #endif /* COLOR_COMANDLINE */

    enum colors_enum
    {
        red         =   4,
        light_green =  10,
        white       =  15
    };

    void colored_print(const char* text, short unsigned int text_color);

#endif /* COLOR_CMD_H */


