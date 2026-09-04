#include <stdio.h>

void selection_sort(int * arr, int n);

int main(void) {
	int arr[] = {6, 3, 5, 1, 7, 21, 8, 4, 12, 0, 9, 8, 4};
	int n = (int) (sizeof(arr) / sizeof(arr[0]));
	selection_sort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}


void selection_sort(int * arr, int n) {
	if (n <= 0) {return;}
	for (int i = 0; i < n - 1; i++) {
		int i_min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[i_min]) {
				i_min = j;
			}
		}
		int t = arr[i_min];
		arr[i_min] = arr[i];
		arr[i] = t;
	}
}



