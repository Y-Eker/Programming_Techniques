#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 202
#define fin1_name "ex2_source.txt"
#define fin2_name "ex2_dict.txt"
#define fout_name "ex2_output.txt"

typedef struct {
    char original[MAX_LEN];
    char replacement[MAX_LEN];
    int len_of_original;
    int len_of_replacement;
} Encoding;

int main(void) {
    // open the files
    FILE *fin1, *fin2, *fout;
    if ((fin1 = fopen(fin1_name, "r")) == NULL) {
        printf("Error while accessing the source file.\n");
        return 1;
    }
    if ((fin2 = fopen(fin2_name, "r")) == NULL) {
        printf("Error while accessing the dictionary file.\n");
        fclose(fin1);
        return 2;
    }
    if ((fout = fopen(fout_name, "w")) == NULL) {
        printf("Error while opening the output file.\n");
        fclose(fin1); fclose(fin2);
        return 3;
    }
    // read all replacements into an array of Encoding
    int num_of_replacements;
    fscanf(fin2, "%d", &num_of_replacements);
    Encoding *replacements = malloc(num_of_replacements * sizeof(Encoding));
    for (int i = 0; i < num_of_replacements && fscanf(fin2, "%s %s", replacements[i].replacement, replacements[i].original) == 2; i++) {
        replacements[i].len_of_original = strlen(replacements[i].original);
        replacements[i].len_of_replacement = strlen(replacements[i].replacement);
    }
    // read all lines one by one, then go over them char by char to check for replacements.
    char str[MAX_LEN];
    while (fgets(str, MAX_LEN, fin1) != NULL) {
        int len = strlen(str);
        for (int i = 0; i < len; i++) {
            int replacement_found = 0;
            for (int j = 0; j < num_of_replacements; j++) {
                char next_chars[MAX_LEN];
                if (i + replacements[j].len_of_original <= len) {
                    for (int k = i; k < i + replacements[j].len_of_original; k++) {
                        next_chars[k - i] = str[k];
                    }
                    next_chars[replacements[j].len_of_original] = '\0';
                    if (strcmp(next_chars, replacements[j].original) == 0) {
                        fprintf(fout, "%s", replacements[j].replacement);
                        i += replacements[j].len_of_original - 1;
                        replacement_found = 1;
                        break;
                    }
                }
            }
            if (!replacement_found) {
                fputc(str[i], fout);
            }
        }
    }
    // close the files and exit
    fclose(fin1); fclose(fin2); fclose(fout);
    free(replacements);
    return 0;
}
