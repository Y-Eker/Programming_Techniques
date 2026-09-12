#include <stdio.h>

char* my_strcpy(char* dest, const char* src);

int main(void) {
    char* s = "Yigit";
    char s_cpy[50];
    printf("Original %s, Copy: %s\n", s, my_strcpy(s_cpy, s));
}

char* my_strcpy(char* dest, const char* src) {
    char* d;
    for (d = dest; *src != '\0'; dest++) {
        *dest = *src++;
    }
    *dest = '\0';
    return d;
}
