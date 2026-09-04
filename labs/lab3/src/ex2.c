#include <stdio.h>
#include <ctype.h>

typedef enum {
	def, number, open_bracket, closed_bracket, operator
} flag;

int is_operator(int c);

int main(void) {
	FILE *fin = fopen("../src/expr.txt", "r");
	if (!fin) {printf("Error while accessing the file.\n"); return -1;}
	char expression[256];

	int line_count = 0;
	while (fgets(expression, sizeof(expression), fin) != NULL) {
		int excessive_brackets = 0;
		int state = def;
		int space_after_num = 0;
		int exit_flag = 0;
		for (int i = 0; i < sizeof(expression) && expression[i] != '\0'; i++) {
			if (expression[i] == '(') {
				space_after_num = 0; excessive_brackets++;
				if (state != def && state != open_bracket && state != operator) {
					printf("Error in expression %d\n", line_count + 1);
					exit_flag = 1;
					break;
				}
				state = open_bracket;
			}
			if (expression[i] == ')') {
				space_after_num = 0; excessive_brackets--;
				if (state != closed_bracket && state != number) {
					printf("Error in expression %d\n", line_count + 1);
					exit_flag = 1;
					break;
				}
				state = closed_bracket;
			}
			if (excessive_brackets < 0) break;
			if (isdigit(expression[i])) {
				if (space_after_num) {
					printf("Error in expression %d\n", line_count + 1);
					exit_flag = 1;
					break;
				}
				if (state == closed_bracket) {
					printf("Error in expression %d\n", line_count + 1);
					exit_flag = 1;
					break;
				}
				space_after_num = 0;
				state = number;
			}
			if (is_operator(expression[i])) {
				if (state != closed_bracket && state != number) {
					printf("Error in expression %d\n", line_count + 1);
					exit_flag = 1;
					break;
				}
				state = operator;
				space_after_num = 0;
			}
			if (expression[i] == ' ') {
				if (state == number) space_after_num = 1;
			}
		}
		if (!exit_flag) {
			if (excessive_brackets != 0) {
				printf("Error in expression %d\n", line_count + 1);
			}
			else if (state == operator || state == def) printf("Error in expression %d\n", line_count + 1);
		}
		line_count++;
	}

	fclose(fin);
	return 0;
}

int is_operator(int c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}
