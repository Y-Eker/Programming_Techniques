#include <stdio.h>

int main(void) {
    FILE* input_file;
    char c;
    int i;

    input_file = fopen("C:\\Users\\ekery\\CLionProjects\\untitled\\Input.txt", "r");

    if (!input_file) {
        printf("Error: File Not Found\n");
        return -1;
    }

    i = fgetc(input_file);
    while (i != EOF) {
        c = (char) i;
        printf("%c", c);
        i = fgetc(input_file);
    }

    fclose(input_file);
    return 0;
}
