#include <stdio.h>

#define N_MAX 100

int read_data(float *data, int n, char *filename);
void normalize_data(float *data, float *result, int n);
int print_data(float *result, int n, char* filename);

int main(void) {
    float data[N_MAX], result[N_MAX];
    int n = read_data(data, N_MAX, "../Input.txt");
    if (n <= 1) {
        printf("Unable to read file. / File contents too short\n"); return -1;
    }
    normalize_data(data, result, n);
    if (print_data(result, n, "../Normalized.txt") == -1) {
        printf("Unable to open output file.\n"); return -2;
    }
    return 0;
}

int read_data(float *data, int n, char *filename) {
    FILE *fin = fopen(filename, "r");
    if (!fin) return -1;
    int i;
    for (i = 0; i < n; i++) {
        if (fscanf(fin, "%f", &data[i]) != 1) {
            break;
        }
    }
    fclose(fin);
    return i;
}
void normalize_data(float *data, float *result, int n) {
    float sum[N_MAX];
    sum[0] = data[0];
    for (int i = 1; i < n; i++) {
        sum[i] = data[i] + sum[i-1];
    }
    float stot = sum[n-1];
    result[0] = (0.0f + data[0] + (stot - sum[0]) / (float) (n - 1)) / 3.0f;
    result[n - 1] = (sum[n-2] / (float) (n - 1) + data[n - 1] + 0.0f) / 3.0f;
    for (int i = 1; i < (n - 1); i++) {
        result[i] = (sum[i-1] / i + data[i] + (stot - sum[i]) / (float) (n - i - 1)) / 3.0f;
    }
}
int print_data(float *result, int n, char* filename) {
    FILE *fout = fopen(filename, "w");
    if (!fout) return -1;
    for (int i = 0; i < n; i++) {
        fprintf(fout, "%.2f ", result[i]);
    }
    fclose(fout);
    return 0;
}

