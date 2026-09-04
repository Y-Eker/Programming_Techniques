#include <stdio.h>
#include <string.h>

#define NR_MAX 20
#define NC_MAX 20

int print_sub_matrix(int arr[NR_MAX][NC_MAX], int dim, int x, int y);

int main(void) {
	// Grab the filename from user
	/*char filename[21];
	printf("Filename: \n");
	fgets(filename, sizeof(filename), stdin);
	*strrchr(filename, '\n') = '\0';*/
	char* filename = "../src/input.txt";
	// Open the file
	FILE *fin = fopen(filename, "r");
	if (!fin) {
		printf("Error while accessing file.\n");
		return -1;
	}
	// Read the file contents into a matrix
	int matrix[NR_MAX][NC_MAX];
	int nr, nc;
	fscanf(fin, "%d %d", &nr, &nc);
	for (int i = 0; i < nr; i++) {
		for (int j = 0; j < nc; j++) {
			fscanf(fin, "%d", &matrix[i][j]);
		}
	}
	fclose(fin);
	// calculate the max val dim can take
	int maxdim;
	if (nr < nc) maxdim = nr;
	else maxdim = nc;
	// repeatedly asking the user for dim
	while (1) {
		int dim;
		printf("dim: \n");
		scanf("%d", &dim);
		if (dim < 1 || dim > maxdim) break;
		printf("The square sub-matrices of dimension %d are: \n", dim);
		int t_max = 0, x_max = 0, y_max = 0, first = 1;
		for (int top_left_y = 0; top_left_y + dim - 1 < nr; top_left_y++) {
			for (int top_left_x = 0; top_left_x + dim - 1 < nc; top_left_x++) {
				int t = print_sub_matrix(matrix, dim, top_left_x, top_left_y);
				if (t > t_max || first) {
					t_max = t;
					x_max = top_left_x;
					y_max = top_left_y;
					first = 0;
				}
				printf("\n");
			}
		}
		printf("the sub_matrix with maximum sum of elements (%d) is: \n", t_max);
		print_sub_matrix(matrix, dim, x_max, y_max);
	}
	return 0;
}

int print_sub_matrix(int arr[NR_MAX][NC_MAX], int dim, int x, int y) {
	int total = 0;
	for (int i = 0; i < dim; i++) {
		for (int j = 0; j < dim; j++) {
			printf("%d ", arr[i + y][j + x]);
			total += arr[i + y][j + x];
		}
		printf("\n");
	}
	return total;
}
