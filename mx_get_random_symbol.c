#include "../inc/header.h"

wchar_t mx_get_random_symbol() {
    wchar_t* ua_letters = L"йцукенгшщзхїфівапролджєячсмитьбюЙЦУКЕНГШЩЗХЇФІВАПРОЛДЖЄЯЧСМИТЬБЮ";
    return ua_letters[rand() % 64];
    
}
