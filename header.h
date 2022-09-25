#ifndef HEADER_H
#define HEADER_H

#define _XOPEN_SOURCE 500
#include <ncurses.h>
#include<unistd.h>
#include <stdlib.h>
#include <locale.h>

typedef struct s_cols_in_matrix {
    int head;
    int tail;
    int len; 
    wchar_t* col;
}               t_col;

void mx_print_matrix(WINDOW* window);
wchar_t mx_get_random_symbol();

#endif
