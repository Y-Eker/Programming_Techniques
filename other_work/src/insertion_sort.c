#include <stdio.h>

void insertion_sort(int *arr, int n);

int main(void) {
	int arr[] = {6, 3, 5, 1, 7, 21, 8, 4, 12, 0, 9, 8, 4};
	int n = sizeof(arr) / sizeof(arr[0]);
	insertion_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void insertion_sort(int *arr, int n) {
	if (n < 2) return;
	for (int i = 1; i < n; i++) {
		int num = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > num) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = num;
	}
}
