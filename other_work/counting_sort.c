#include <stdio.h>

#define N 8
#define K 6

void counting_sort(int *arr, int n, int *result, int k, int *temp);

int main(void) {
	int arr[N] = {2, 5, 3, 0, 2, 3, 0,	3};
	int result[N], temp[K] = {0};
	int n = sizeof(arr) / sizeof(arr[0]);
	counting_sort(arr, n, result, K, temp);
	for (int i = 0; i < n; i++) {
		printf("%d ", result[i]);
	}
	return 0;
}


void counting_sort(int *arr, int n, int *result, int k, int *temp) {
	for (int i = 0; i < k; i++) temp[i] = 0;
	for (int i = 0; i < n; i++) temp[arr[i]]++;
	for (int i = 1; i < k; i++) temp[i] += temp[i - 1];

	for (int i = n - 1; i >= 0; i--) {
		result[temp[arr[i]] - 1] = arr[i];
		temp[arr[i]]--;
	}
	for (int i = 0; i < n; i++) arr[i] = result[i];
}
