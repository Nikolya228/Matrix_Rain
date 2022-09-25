#include "../inc/header.h"

void mx_print_matrix(WINDOW* window) {
    int rows;
    int cols;
    getmaxyx(window, cols, rows);


    start_color();
	
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    wbkgd(window, COLOR_PAIR(1));

    usleep(15000);
    char* messages[4] = {
        "Wake up , Neo..",
        "The Matrix has you..",
        "Follow the white rabbit",
        "Knock, knock, Neo"
        };
    
	
    if(cols < 16 && rows < 32) {
        exit(-1);
    }
    int mes_point_x = cols / 8;
    int mes_point_y = rows / 64;
    for (int i = 0; i < 4; i++){
        int ch_i = 0;
        
        while (messages[i][ch_i] != '\0') {
            mvwaddch(window, mes_point_y + 1, mes_point_x + ch_i, messages[i][ch_i]);
            refresh();
            usleep(150000);
            ch_i++;
        }
        wclear(window);
        usleep(100000);
    }

   
    t_col* matrix_arr = (t_col*)malloc(sizeof(t_col) * rows);

    for (int i = 0; i < rows; i++){
        matrix_arr[i].col = (wchar_t*)malloc(sizeof(wchar_t) * cols);

        for (int c = 0; c < cols; c++) {
            matrix_arr[i].col[c] = mx_get_random_symbol();
        }
        matrix_arr[i].len = rand() % cols;
        matrix_arr[i].head = 0 - matrix_arr[i].len - matrix_arr[i].len;
        matrix_arr[i].tail = 0 - matrix_arr[i].len;
        
    }

    wbkgd(window, COLOR_PAIR(1));
    wclear(window);
    int color = 1;
    int SPEED = 50;

    while (true) {	
        wtimeout(window, 101 - SPEED);
        switch(getch()) {
            case '-':
                if (SPEED > 20)
                    SPEED -= 10;
                break;
            case '+':
                if (SPEED < 70)
                    SPEED += 10;
                break;
            case 'g':
                color = 1;
                break;
            case 'r':
                color = 3;
                break;
            case 'y':
                color = 4;
                break;
            case 'b':
                color = 5;
                break;
            case 'm':
                color = 6;
                break;
            case 'c':
                color = 7;
                break;
            case 'q':
                wclear(window);
                refresh();
                delwin(window);
	            endwin();
                exit(0);
                break;
        }

        wclear(window);

        for (int i = 0; i < rows / 2; i++){

            for (int c = 0; c < cols; c++) {
                if(c >= matrix_arr[i].head && c <= matrix_arr[i].tail) {
                    if(matrix_arr[i].tail == c) {
                        attroff(COLOR_PAIR(color));
                        attron(COLOR_PAIR(2));
                    }

                    mvprintw(c, i * 2, "%lc", matrix_arr[i].col[c]);
                    
                    if(matrix_arr[i].tail == c) {
                        attroff(COLOR_PAIR(2));
                        attron(COLOR_PAIR(color));
                    }
                } else {
                    matrix_arr[i].col[c] = mx_get_random_symbol();
                }

                
            }
            matrix_arr[i].tail += 1;
            matrix_arr[i].head += 1;
            if(matrix_arr[i].head > cols) {
                matrix_arr[i].len = rand() % cols;
                matrix_arr[i].head = 0 - matrix_arr[i].len - matrix_arr[i].len;
                matrix_arr[i].tail = 0 - matrix_arr[i].len ;
            }
        }
        refresh();
    }
   

    for (int i = 0; i < rows; i++) {
        free(matrix_arr[i].col);
    }
    free(matrix_arr);
    
    
	refresh();
    getch();
}
