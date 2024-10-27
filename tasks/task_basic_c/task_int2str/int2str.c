#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* int2str(int x) {
    if (x == -2147483648) {
        return "-2147483648";
    }
    bool y = false;
    if (x == 0) {
        return "0";
    }
    if (x < 0) {
        y = true;
        x = -x;
    }
    int len = 0;
    int z = x;
    while (z != 0) {
        z /= 10;
        len++;
    }
    char *str = (char*)malloc(len + y + 1);
    str[len + y] = '\0';
    for (int i = len + y - 1; i >= y; i--) {
        str[i] = (x % 10) + '0';
        x /= 10;
    }
    if (y) {
        str[0] = '-';
    }
    return str;
}

