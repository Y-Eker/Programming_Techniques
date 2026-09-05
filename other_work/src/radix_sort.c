#include <stdio.h>

#define N 8
#define K 10

void radix_sort(int *arr, int n, int *temp, int k, int *result);
void counting_sort_wrt_digit(int *arr, int n, int *temp, int k, int *result, int d);
int get_digit(int num, int digit);

int main(void) {
    int arr[] = {170, 45, 2375, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result[N], temp[K];
    radix_sort(arr, n, temp, K, result);
    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}


void radix_sort(int *arr, int n, int *temp, int k, int *result) {
    // Find the max number
    int max = arr[0];
    for (int i = 0; i < n; i++) if (arr[i] > max) max = arr[i];
    // Find for how many digits we execute the loop
    int max_digits;
    for (max_digits = 1; max / 10 > 0; max /= 10) max_digits++;
    // Loop and sort for each digit, i=0 represents units, 1 represents ones ...
    for (int i = 0; i < max_digits; i++) {
        counting_sort_wrt_digit(arr, n, temp, k, result, i);
    }
}

void counting_sort_wrt_digit(int *arr, int n, int *temp, int k, int *result, int d) {
    for (int i = 0; i < k; i++) temp[i] = 0;
    for (int i = 0; i < n; i++) {
        int digit = get_digit(arr[i], d);
        temp[digit]++;
    }
    for (int i = 1; i < k; i++) temp[i] += temp[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        int digit = get_digit(arr[i], d);
        result[temp[digit] - 1] = arr[i];
        temp[digit]--;
    }
    for (int i = 0; i < n; i++) arr[i] = result[i];
}

int get_digit(int num, int digit) {
    for (int i = 0; i < digit; i++) num /= 10;
    return num % 10;
}
