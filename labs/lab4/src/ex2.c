#include <stdio.h>
#define MAX_N 30

void rotate(int *arr, int n, int p, int dir);

int main(void) {
	int arr[MAX_N], n;
	printf("N (max 30): \n");
	scanf("%d", &n);
	printf("values: \n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	while (1) {
		printf("p and dir:\n");
		int p, dir;
		scanf("%d %d", &p, &dir);
		if (p == 0) break;
		rotate(arr, n, p, dir);
		for (int i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}

void rotate(int *arr, int n, int p, int dir) {
	for (int i = 0; i < p; i++) {
		if (dir == -1) {
			int t = arr[n - 1];
			for (int j = n - 1; j > 0; j--) {
				arr[j] = arr[j - 1];
			}
			arr[0] = t;
		}
		else {
			int t = arr[0];
			for (int j = 0; j < n - 1; j++) {
				arr[j] = arr[j + 1];
			}
			arr[n - 1] = t;
		}
	}
}
