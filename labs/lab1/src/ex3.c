#include <stdio.h>


int main(void) {
    FILE *fin, *odd_fout, *even_fout;
    char file_s[100], name[20];
    int counter = 0;

    if ((fin = fopen("Bronte.txt", "r")) == NULL) {
        printf("Error while accessing the input file.\n");
        return -1;
    }
    if ((odd_fout = fopen("Output_odd.txt", "w")) == NULL) {
        printf("Error while opening the output file.\n");
        return -2;
    }
    if ((even_fout = fopen("Output_even.txt", "w")) == NULL) {
        printf("Error while opening the output file.\n");
        return -3;
    }
    printf("What's your name? \n");
    gets(name);

    while (!feof(fin)) {
        counter++;
        if (counter % 2 == 0) {


            if (!feof(fin)) {
                fscanf(fin, " %[^\n] ", file_s);
                printf("%s\nI'm reading:\n%s\n\n", name, file_s);
                fprintf(even_fout, "%s\n", file_s);
            }
        }
        else {
            fgets(file_s, sizeof(file_s), fin);
            if (!feof(fin)) {
                puts(name);
                puts("I'm reading:");
                puts(file_s);
                fputs(file_s, odd_fout);
            }
        }
    }
    fclose(fin); fclose(odd_fout); fclose(even_fout);
    return 0;
}
