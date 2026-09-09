#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define FSEQ_NAME "sequences.txt"
#define FIN_NAME "text.txt"
#define MAX_SEQ_NUM 20
#define MAX_SEQ_LEN 6
#define LINE_LEN 201
#define WORD_LEN 26
#define MAX_MATCHES_PER_SEQ 100

typedef struct {
    char sequence[MAX_SEQ_LEN];
    char word[WORD_LEN];
    int position;
} Match;

void to_lower_str(char* s, char *result);

int main(void) {
    // open the files
    FILE *fin, *fseq;
    if ((fin = fopen(FIN_NAME, "r")) == NULL) return 1;
    if ((fseq = fopen(FSEQ_NAME, "r")) == NULL) {fclose(fin); return 2;}
    // read sequences into an array
    int n_seq;
    char sequences[MAX_SEQ_NUM][MAX_SEQ_LEN];
    fscanf(fseq, "%d", &n_seq);
    for (int i = 0; i < n_seq; i++) {
        fscanf(fseq, "%5s", sequences[i]);
    }
    // loop all words, add matches to the matches arr
    Match matches[MAX_SEQ_NUM * MAX_MATCHES_PER_SEQ];
    int match_index = 0;
    char curr_word[WORD_LEN];
    int index = 0;
    int word_counter = 0;
    while (1) {
        int c = fgetc(fin);
        if (c == EOF) {
            curr_word[index] = '\0';
            for (int i = 0; i < n_seq; i++) {
                char t1[WORD_LEN]; char t2[WORD_LEN];
                to_lower_str(curr_word, t1); to_lower_str(sequences[i], t2);
                if (strstr(t1, t2)) {
                    Match m;
                    strcpy(m.sequence, sequences[i]);
                    strcpy(m.word, curr_word);
                    m.position = word_counter + 1;
                    matches[match_index] = m;
                    match_index++;
                }
            }
            if (index > 0) word_counter++;
            index = 0;
            break;
        }
        if (isalnum(c)) curr_word[index++] = c;
        if (ispunct(c) || isspace(c)) {
            curr_word[index] = '\0';
            for (int i = 0; i < n_seq; i++) {
                char t1[WORD_LEN]; char t2[WORD_LEN];
                to_lower_str(curr_word, t1); to_lower_str(sequences[i], t2);
                if (strstr(t1, t2)) {
                    Match m;
                    strcpy(m.sequence, sequences[i]);
                    strcpy(m.word, curr_word);
                    m.position = word_counter + 1;
                    matches[match_index] = m;
                    match_index++;
                }
            }
            if (index > 0) word_counter++;
            index = 0;
        }
    }
    // Iterate over sequences and print related matches if there's any
    for (int i = 0; i < n_seq; i++) {
        int flag = 0;
        for (int j = 0; j < match_index; j++) {
            if (strcmp(sequences[i], matches[j].sequence) == 0) {
                if (!flag) printf("Sequence '%s' found in: \n", sequences[i]);
                flag = 1;
            }
        }
        int n_printed = 0;
        for (int j = 0; j < match_index; j++) {
            if (strcmp(sequences[i], matches[j].sequence) == 0 && n_printed < 10) {
                printf("> %s (Position %d)\n", matches[j].word, matches[j].position);
                n_printed++;
            }
        }
    }
    // close the files and exit
    fclose(fin); fclose(fseq);
    return 0;
}

void to_lower_str(char* s, char *result) {
    int i;
    for (i = 0; s[i] != '\0'; i++) {
        result[i] = tolower(s[i]);
    }
    result[i] = '\0';
}
