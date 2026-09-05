#include <stdio.h>

void bubble_sort(int *arr, int n);

int main(void) {
	int arr[] = {6, 5, 3, 1, 2};
	int n = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void bubble_sort(int *arr, int n) {
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int t = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = t;
			}
		}
	}
}
