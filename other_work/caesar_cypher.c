#include <stdio.h>

int main(void) {
    FILE *input_file, *output_file;
    char new_c;
    int c, key;
    input_file = fopen("C:\\Users\\ekery\\CLionProjects\\untitled\\Input.txt", "r");
    output_file = fopen("C:\\Users\\ekery\\CLionProjects\\untitled\\Output.txt", "w");

    if (!input_file || !output_file) {
        printf("Error while accessing the files.\n");
        return -1;
    }

    printf("The Key: \n");
    scanf("%d", &key);

    c = fgetc(input_file);
    while (c != EOF) {
        if (c >= 65 && c <= 90) {
            c = c + key;
            if (c > 90) c = c % 90 + 64;
        }
        else if (c >= 97 && c <= 122) {
            c = c + key;
            if (c > 122) c = c % 122 + 96;
        }
        new_c = (char) c;
        fputc(new_c, output_file);
        c = fgetc(input_file);
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}
