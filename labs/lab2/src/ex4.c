#include <stdio.h>
#include <ctype.h>

int encode(FILE *fin, FILE *fout);
int decode(FILE *fin, FILE *fout);

int main(void) {
    char ans;
    printf("(E)ncode or (D)ecode?\n");
    scanf(" %c", &ans);

    /* Acquiring Input via keyboard
    char fin_name[100], fout_name[100];
    printf("Name of Input File: \n");
    scanf(" %s", fin_name);
    printf("Name of Output File: \n");
    scanf(" %s", fout_name); */

    char fin_name[100] = "../src/Encoded.txt";
    char fout_name[100] = "../src/Input1.txt";

    FILE *fin, *fout;
    if ((fin = fopen(fin_name, "r")) == NULL) {
        printf("Error while accessing input file.\n");
        return -1;
    }
    if ((fout = fopen(fout_name, "w")) == NULL) {
        printf("Error while opening output file.\n");
        fclose(fin);
        return -2;
    }

    if (ans == 'E') {
        int res = encode(fin, fout);
        if (res == 0) {
            printf("Error while encoding. / File is Empty.\n");
            fclose(fin); fclose(fout);
            return -4;
        }
        printf("Successfully printed %d characters.\n", res);
    }
    else if (ans == 'D') {
        int res = decode(fin, fout);
        if (res == 0) {
            printf("Error while decoding. / File is Empty.\n");
            fclose(fin); fclose(fout);
            return -5;
        }
        printf("Successfully printed %d characters.\n", res);
    }
    else {
        printf("Unidentified Input.\n");
        fclose(fin); fclose(fout);
        return -3;
    }

    fclose(fin); fclose(fout);
    return 0;
}

int encode(FILE *fin, FILE *fout) {
    int printed_chars = 0;
    int last_char = EOF;
    int k = 0;
    int h;
    while (1) {
        int c = fgetc(fin);
        if (c == EOF) break;
        int char_to_print;
        if (isdigit(c)) {
            char_to_print = c + k % 10;
            if (char_to_print > '9') {char_to_print -= ('9' - '0' + 1);} // '9' - '0' + 1 == 10 always
            k++;
            fputc(char_to_print, fout);
            printed_chars++;
        }
        else if (isalpha(c)) {
            if (isalpha(last_char)) {
                if (isupper(last_char)) {
                    h = (last_char - 'A') % 26;
                    char_to_print = c + h;
                }
                else {
                    h = (last_char - 'a') % 26;
                    char_to_print = c + h;
                }
                if (isupper(c)) {
                    if (char_to_print > 'Z') {char_to_print -= ('Z' - 'A' + 1);}
                }
                else {
                    if (char_to_print > 'z') {char_to_print -= ('z' - 'a' + 1);}
                }
            }
            else {
                char_to_print = c;
            }
            fputc(char_to_print, fout);
            printed_chars++;
        }
        else {
            fputc(c, fout);
            printed_chars++;
        }
        last_char = c;
    }

    return printed_chars;
}
int decode(FILE *fin, FILE *fout) {
    int printed_chars = 0;
    int last_char = EOF;
    int k = 0;
    int h;
    while (1) {
        int c = fgetc(fin);
        if (c == EOF) {break;}
        int char_to_print;
        if (isdigit(c)) {
            char_to_print = c - k % 10;
            if (char_to_print < '0') {char_to_print += '9' - '0' + 1;}
            fputc(char_to_print, fout);
            printed_chars++;
            k++;
        }
        else if (isalpha(c)) {
            if (isalpha(last_char)) {
                if (isupper(last_char)) {h = (last_char - 'A') % 26;}
                else {h = (last_char - 'a') % 26;}
                char_to_print = c - h;
                if (isupper(c)) {
                    if (char_to_print < 'A') {char_to_print += 26;}
                }
                else {
                    if (char_to_print < 'a') {char_to_print += 26;}
                }
                fputc(char_to_print, fout);
                printed_chars++;
            }
            else {
                char_to_print = c;
                fputc(char_to_print, fout);
                printed_chars++;
            }
        }
        else {
            char_to_print = c;
            fputc(char_to_print, fout);
            printed_chars++;
        }
        last_char = char_to_print;
    }

    return printed_chars;
}

