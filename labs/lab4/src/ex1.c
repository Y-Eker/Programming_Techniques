#include <stdio.h>

#define N_MAX 30

void print_longest_subarr_without_zeros(int *arr, int n);

int main(void) {
	int arr[N_MAX] = {1, 3, 4, 0, 1, 0, 9, 4, 2, 0}; // n = 10
	printf("Please enter the amount of integers (max 30):\n");
	int n;
	scanf("%d", &n);
	/*
	printf("Please enter the numbers seperated by space or return:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}*/
	print_longest_subarr_without_zeros(arr, n);
}

void print_longest_subarr_without_zeros(int *arr, int n) {
	int max_len = 0;
	int curr_len = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			if (curr_len > max_len) max_len = curr_len;
			curr_len = 0;
		}
		else {curr_len++;}
	}
	if (curr_len > max_len) max_len = curr_len;
	if (max_len == 0) return;
	curr_len = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) {
			if (curr_len == max_len) {
				for (int j = i - curr_len; j < i; j++) {
					printf("%d ", arr[j]);
				}
				printf("\n");
			}
			curr_len = 0;
		}
		else curr_len++;
	}

	if (curr_len == max_len) {
		for (int j = n - curr_len; j < n; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");
	}
}
