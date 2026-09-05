#include <stdio.h>

void shell_sort(int *arr, int n);

int main(void) {
	int arr[] = {5, 8, 9, 0, 4, 6, 3, 1, 3, 7, 6, 4, 5, 7, 1, 8, 9, 0};
	int n = sizeof(arr) / sizeof(arr[0]);
	shell_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}


void shell_sort(int *arr, int n) {
	int h = 1;
	while (h <= n / 3) h = 3*h + 1;
	for (; h >= 1; h /= 3) {
		for (int i = h; i < n; i++) {
			int num = arr[i];
			int j;
			for (j = i - h; j >= 0 && arr[j] > num; j -= h) {
				arr[j + h] = arr[j];
			}
			arr[j + h] = num;
		}
	}
}