#include <stdio.h>
#include <ctype.h>

int file_to_lower(FILE *fin, FILE *fout);
int file_to_upper(FILE *fin, FILE *fout);

int main(int argc, char *argv[]) {
    if (argc != 4 && argc != 2) return -1;
    
    FILE *fin, *fout;
    if (argc == 4) {
        if ((fin = fopen(argv[2], "r")) == NULL) return -2;
        if ((fout = fopen(argv[3], "w")) == NULL) {
            fclose(fin);
            return -3;
        }
    }
    switch (argv[1][1]) {
        case 'l': case 'L':
        if (argc == 4) file_to_lower(fin, fout);        
            break;
        case 'u': case 'U':
        if (argc == 4) file_to_upper(fin, fout);
            break;
        case 'h': case 'H':
            printf("Usage: m2m -<UulL> input.txt output.txt\nm2m -<Hh>\n");
            break;
        
        default: return -4;
    }
    if (argc == 4) {fclose(fin); fclose(fout);}
    return 0;
}


int file_to_lower(FILE *fin, FILE *fout) {
    int res = 0;
    while (1) {
        int c = fgetc(fin);
        if (c == EOF) break;
        fputc(tolower(c), fout);
        res++;
    }
    return res;
}
int file_to_upper(FILE *fin, FILE *fout) {
    int res = 0;
    while (1) {
        int c = fgetc(fin);
        if (c == EOF) break;
        fputc(toupper(c), fout);
        res++;
    }
    return res;
}

