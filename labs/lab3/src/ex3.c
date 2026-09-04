#include <stdio.h>

#define fin_name "../src/numbers.txt"

int is_valid(int a, int b, int c);

int main(void) {
	FILE *fin = fopen(fin_name, "r");
	if (!fin) {printf("Error while accessing the file.\n"); return -1;}

	int x_i_2;
	if (fscanf(fin, "%d", &x_i_2) != 1) {
		printf("File doesn't have enough numbers.\n");
		fclose(fin);
		return -2;
	}
	int x_i_1;
	if (fscanf(fin, "%d", &x_i_1) != 1) {
		printf("File doesn't have enough numbers.\n");
		fclose(fin);
		return -2;
	}
	int min, max;
	if (x_i_1 < x_i_2) {
		min = x_i_1;
		max = x_i_2;
	}
	else {
		min = x_i_2;
		max = x_i_1;
	}
	int x_i;
	int num_discarded = 0;
	while (fscanf(fin, "%d", &x_i) == 1) {
		if (is_valid(x_i_2, x_i_1, x_i)) {
			x_i_2 = x_i_1;
			x_i_1 = x_i;
			if (x_i < min) {min = x_i;}
			if (x_i > max) {max = x_i;}
		}
		else {
			num_discarded++;
		}
	}

	if (num_discarded == 0) printf("The sequence only had valid numbers.\n");
	else printf("# of discarded values: %d\n", num_discarded);
	printf("Maximum value: %d\n", max);
	printf("Minimum value: %d\n", min);
	fclose(fin);
	return 0;
}

int is_valid(int a, int b, int c) {
	if (b == 0) return (c == a + b || c == a - b || c == a * b);
	return (c == a + b || c == a - b || c == a * b || c == a / b);
}

