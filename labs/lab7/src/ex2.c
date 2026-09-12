// TO BE CONT.D


#include <stdio.h>
#include <stdlib.h>

#define FIN_NAME "sort.txt"

typedef struct {
    int num_swaps;
    int num_outer;
    int num_inner;
    int tot_iters;
} Sort_Data;

void selection_sort(int *arr, int *seq, int n, Sort_Data *data);

int main(void) {
    // open the file
    FILE *fin = fopen(FIN_NAME, "r");
    if (!fin) {printf("Error while opening %s\n", FIN_NAME); return 1;}
    // read the file, apply the sorting algos for each line, and grab their statistics
    int n_seq;
    fscanf(fin, "%d", &n_seq);
    for (int i = 0; i < n_seq; i++) {
        Sort_Data selection = {0}, insertion = {0}, shell = {0};
        int n_elems;
        fscanf(fin, "%d", &n_elems);
        int *sequence = malloc(n_elems * sizeof(int));
        for (int j = 0; j < n_elems; j++) {
            fscanf(fin, "%d", sequence + j);
        }
        int *seq = malloc(n_elems * sizeof(int));
        selection_sort(sequence, seq, n_elems, &selection);
        free(seq);
        free(sequence);
    }
    // close the file and exit
    fclose(fin);
    return 0;
}

void selection_sort(int *arr, int *seq, int n, Sort_Data *data) {
    for (int i = 0; i < n; i++) seq[i] = arr[i];
    for (int i = 0; i < n - 1; i++) {
        int index_min = i;
        (*data).num_inner = 0;
        for (int j = i + 1; j < n; j++) {
            if (seq[index_min] > seq[j]) index_min = j;
            (*data).num_inner++;
            (*data).tot_iters++;
        }

        (*data).num_outer++;
        if (i != index_min) {
            int t = seq[i];
            seq[i] = seq[index_min]; 
            seq[index_min] = t;
            (*data).num_swaps++;
        }
        printf("Inner Loop Amount: %d", (*data).num_inner);
    }
}
