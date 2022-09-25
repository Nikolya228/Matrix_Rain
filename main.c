#include "header.h"

int main(){	
    setlocale(LC_ALL, "ru_UA.UTF-8");
    WINDOW* window = initscr();
	mx_print_matrix(window);
	delwin(window);
	endwin();
	return 0;
}
