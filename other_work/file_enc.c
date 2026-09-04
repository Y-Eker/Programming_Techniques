#include <stdio.h>

int main(void) {
    // Opening the files
    FILE *fin, *fout, *f_table;
    if ((fin = fopen("../Input.txt", "r")) == NULL) {
        printf("Error while accessing the input file.\n");
        return -1;
    }
    if ((fout = fopen("../Encrypted.txt", "w")) == NULL) {
        printf("Error while opening the output file.\n");
        fclose(fin);
        return -2;
    }
    if ((f_table = fopen("../Table.txt", "r")) == NULL) {
        printf("Error while accessing the table file.\n");
        fclose(fin); fclose(fout);
        return -3;
    }

    // Setting up the lookup table
    int table[256];
    for (int i = 0; i < 256; i++) table[i] = i;
    while (1) {
        int index;
        int val;
        if (fscanf(f_table, "%d %d", &index, &val) != 2) break;
        table[index] = val;
    }

    // Looping through the characters in the input file to encrypt them and write them to the output file
    while (1) {
        int c = fgetc(fin);
        if (c == EOF) break;
        fputc(table[c], fout);
    }

    fclose(fin); fclose(fout); fclose(f_table);
    return 0;
}


