#include <stdio.h>

int compress(FILE *fin, FILE *fout);
int decompress(FILE *fin, FILE *fout);

int main(void) {
    char ans;
    printf("(C)ompression or (D)ecompression: \n");
    scanf(" %c", &ans);
    FILE *fin, *fout;
    switch (ans) {
        case 'C': {
            if ((fin = fopen("../src/Source.txt", "r")) == NULL) {
                printf("Error while accessing the source file.\n");
                return -1;
            }
            if ((fout = fopen("../src/Compressed.txt", "w")) == NULL) {
                printf("Error while opening the compression file.\n");
                return -2;
            }

            int res = compress(fin, fout);
            if (res == 0) {
                printf("Error while compression / Empty File.\n");
                return -5;
            }
            printf("Successfully printed %d characters.\n", res);
            break;
        }
        case 'D': {
            if ((fin = fopen("../src/Compressed.txt", "r")) == NULL) {
                printf("Error while accessing the compressed file.\n");
                return -3;
            }
            if ((fout = fopen("../src/Source2.txt", "w")) == NULL) {
                printf("Error while opening the decompression file.\n");
                return -4;
            }

            int res = decompress(fin, fout);
            if (res == 0) {
                printf("Error while decompression / Empty file.\n");
                return -6;
            }
            printf("Successfully printed %d characters.\n", res);
            break;
        }
        default:
            printf("Unidentified Input\n");
            return -7;
    }
}


int compress(FILE *fin, FILE *fout) {
    int chars_printed = 0;
    int last_char = EOF;
    int repetitions = 0;
    while (1) {
        int c = fgetc(fin);
        if (last_char != EOF) {
            if (last_char != c) {
                if (repetitions == 0) {
                    fputc(last_char, fout);
                    chars_printed++;
                }
                else if (repetitions == 1) {
                    fputc(last_char, fout);
                    fputc(last_char, fout);
                    chars_printed += 2;
                }
                else {
                    fprintf(fout, "%c!%d", last_char, repetitions);
                    chars_printed += 3;
                }
                repetitions = 0;
            }
            else {
                repetitions++;
                if (repetitions == 9) {
                    fprintf(fout, "%c!%d", last_char, repetitions);
                    chars_printed += 3;
                    repetitions = 0;
                    last_char = EOF;
                    continue;
                }
            }
        }
        last_char = c;
        if (c == EOF) break;
    }

    fclose(fin);
    fclose(fout);
    return chars_printed;
}
int decompress(FILE *fin, FILE *fout) {
    int chars_printed = 0;
    int last_char = EOF;
    int char_to_print = EOF;
    int rep_amount = 0;
    while (1) {
        int c = fgetc(fin);
        if (last_char != EOF) {
            if (last_char != '!') {
                char_to_print = last_char;
                fputc(char_to_print, fout);
                chars_printed++;
            }
            else {
                rep_amount = c - '0';
                for (int i = 0; i < rep_amount; i++) {
                    fputc(char_to_print, fout);
                    chars_printed++;
                }
                last_char = EOF;
                continue;
            }
        }


        last_char = c;
        if (c == EOF) break;
    }

    fclose(fin);
    fclose(fout);
    return chars_printed;
}
