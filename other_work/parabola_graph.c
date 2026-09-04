#include <stdio.h>
#include <math.h>

#define H 20
#define W 80

int main (void) {
	float a, b, c, x_min, x_max, y_min, y_max;
	/*printf("a*x^2 + b*x + c = 0\n");
	printf("please input a, b, c, x_min, x_max, y_min, y_max:\n");
	scanf("%f %f %f %f %f %f %f", &a, &b, &c, &x_min, &x_max, &y_min, &y_max);*/
	a = 1.0f, b = 2.0f, c = 1.0f, x_min = -1.0f, x_max = 4.0f, y_min = -1.0f, y_max = 10.0f;
	char matrix[H][W];
	for (int i = 0; i < H; i++) {
		for (int j = 0;  j < W; j++) matrix[i][j] = ' ';
	}

	float x_step = (x_max - x_min) / (W - 1);
	float y_step = (y_max - y_min) / (H - 1);
	float x_val = x_min;
	for (int i = 0; i < W; i++) {
		float y_val = a * x_val * x_val + b * x_val + c;
		if (y_val <= y_max && y_val >= y_min) {
			int row = H - (int) ((y_val - y_min) / y_step) - 1;
			matrix[row][i] = '*';
		}
		x_val += x_step;
	}

	FILE *fout;
	if ((fout = fopen("../graph.txt", "w")) == NULL) {printf("Error while opening file.\n"); return -1;}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			fputc(matrix[i][j], fout);
		}
		fputc('\n', fout);
	}
	fclose(fout);
	return 0;
}
