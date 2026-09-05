#include <stdio.h>

void merge_sort(int *arr, int *temp, int n);
void merge(int *arr, int *temp, int i, int m, int n);
int min(int a, int b);

int main(void) {
	int arr[] = {12, 6, 4, 5, 9, 2, 3, 1};
	int temp[] = {12, 6, 4, 5, 9, 2, 3, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	merge_sort(arr, temp, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}


void merge_sort(int *arr, int* temp, int n) {
	for (int m = 1; m < n; m *= 2) {
		for (int i = 0; i < n - m; i += 2*m) {
			merge(arr, temp, i, m, n);
		}
	}
}

void merge(int *arr, int *temp, int i, int m, int n) {
	int l_1 = i;
	int l_2 = i + m;
	int r = min(l_2 + m, n);
	for (int k = i; k < r; k++) {
		if (l_1 >= i + m) {
			temp[k] = arr[l_2++];
		}
		else if (l_2 >= r) {
			temp[k] = arr[l_1++];
		}
		else if (arr[l_1] <= arr[l_2]) {
			temp[k] = arr[l_1++];
		}
		else {
			temp[k] = arr[l_2++];
		}
	}
	for (int k = i; k < r; k++) {
		arr[k] = temp[k];
	}
}

int min(int a, int b) {
	if (a <= b) return a;
	return b;
}
