#include <stdio.h>


int main(void) {
    FILE *fp_read, *fp_write;
    char choice;
    fp_read = fopen("Guide.txt", "r");
    if (!fp_read) {
        printf("Error while accessing input file.\n");
        return -1;
    }
    printf("Print on console (C) or file (F)? \n");
    scanf(" %c", &choice);
    int file_char = fgetc(fp_read);
    switch (choice) {
        case 'C':
            while (file_char != EOF) {
                // Idk why we print this sentence every character but it's what it is.
                printf("Character printed: %c\n", file_char);
                file_char = fgetc(fp_read);
            }
            break;
        case 'F':
            fp_write = fopen("Output.txt", "w");
            if (!fp_write) {
                printf("Error while opening output file.\n");
                return -2;
            }
            while (file_char != EOF) {
                // Idk why we print to the console even though the user asked for the file :d.
                printf("Character saved: %c\n", file_char);
                fputc(file_char, fp_write);
                file_char = fgetc(fp_read);
            }
            fclose(fp_write);
            break;
        default:
            printf("Wrong choice.\n");
            fclose(fp_read);
            return -3;
    }
    fclose(fp_read);
    return 0;
}
