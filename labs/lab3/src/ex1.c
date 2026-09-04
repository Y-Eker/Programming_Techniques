#include <stdio.h>
#include <ctype.h>

#define fin_name "../src/input.txt"
#define fout_name "../src/output.txt"

int main(void) {
	FILE *fin, *fout;
	if ((fin = fopen(fin_name, "r")) == NULL) {
		printf("Error while accessing input file.\n");
		return -1;
	}
	if ((fout = fopen(fout_name, "w")) == NULL) {
		printf("Error while opening output file.\n");
		fclose(fin);
		return -2;
	}

	int line_len = 0;
	int add_space = 0;
	int to_capitalize = 0;
	while (1) {
		if (line_len >= 25) {
			fprintf(fout, " | c:25\n");
			line_len = 0;
		}
		int c = fgetc(fin);
		if (c == EOF) {
			if (line_len > 0) {
				for (int i = 0; i < 25 - line_len; i++) fputc(' ', fout);
				fprintf(fout, " | c:%d\n", line_len);
				line_len = 0;
			}
			break;
		}
		if (add_space && !isspace(c) && !ispunct(c)) {
			fputc(' ', fout);
			line_len++;
			add_space = 0;
		}
		if (line_len >= 25) {
			fprintf(fout, " | c:25\n");
			line_len = 0;
		}
		if (c == '.' || c == '!' || c == '?') {
			to_capitalize = 1;
		}
		if (isdigit(c)) {
			fputc('*', fout);
			line_len++;
		}
		else if (ispunct(c)) {
			fputc(c, fout);
			add_space = 1;
			line_len++;
		}
		else if (isspace(c)) {
			add_space = 0;
			if (c != '\n') {fputc(c, fout); line_len++;}
			else {
				if (line_len > 0) {
					for (int i = 0; i < 25 - line_len; i++) fputc(' ', fout);
					fprintf(fout, " | c:%d\n", line_len);
					line_len = 0;
				}
			}
		}
		else {
			if (to_capitalize) {
				fputc(toupper(c), fout);
				to_capitalize = 0;
			}
			else {
				fputc(c, fout);
			}
			line_len++;
		}

	}

	fclose(fin); fclose(fout);
	return 0;
}
