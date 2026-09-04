#include <stdio.h>

int binary_search(int arr[], int N, int target);

int main(void) {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int res = binary_search(arr, 6, -2);
    printf("%d", res);
}

int binary_search(int arr[], int N, int target) {
    int l = 0, r = N - 1;
    while (r >= l) {
        int m = l + (r - l) / 2;
        if (arr[m] == target) return m;

        if (arr[m] < target) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}
