#include <stdio.h>

#define N 8
#define K 10

void radix_sort(int *arr, int n, int *temp, int k, int *result);
void counting_sort(int *arr, int n, int *temp, int k, int *result, int curr_d);

int main(void) {
	int arr[] = {170, 45, 2375, 90, 802, 24, 2, 66};
	int n = sizeof(arr) / sizeof(arr[0]);
	int result[N], temp[K];
	radix_sort(arr, n, temp, K, result);
	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}
	return 0;
}

void radix_sort(int *arr, int n, int *temp, int k, int *result) {
	// find the max num
	int max = arr[0];
	for (int i = 0; i < n; i++) {
		if (max < arr[i]) max = arr[i];
	}
	// find how much time we'll loop (however many digits the max num has)
	int d;
	for (d = 1; max / 10 != 0; max /= 10) d++;
	// main loop for our radix sort
	for (int i = 1; i <= d; i++) {
		counting_sort(arr, n, temp, k, result, i);
	}

}

void counting_sort(int *arr, int n, int *temp, int k, int *result, int curr_d) {
	for (int i = 0; i < k; i++) temp[i] = 0;
	for (int i = 0; i < n; i++) {
		int digit;
		temp[arr[i]]++;
	}
}
