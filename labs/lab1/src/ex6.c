#include <stdio.h>

int main(void) {
    FILE *fin, *fout;
    fin = fopen("Operations.txt", "r");
    fout = fopen("Results.txt", "w");

    if (!fin) {
        printf("Error while accessing input file.\n");
        return -1;
    }
    if (!fout) {
        printf("Error while opening output file.\n");
        return -2;
    }

    char buffer[256];
    // Is there a better (or just another) way of doing this? I don't like calling functions in loop conditionals.
    while (fgets(buffer, sizeof(buffer), fin) != NULL) {
        char op;
        float op1, op2, ans;
        sscanf(buffer, " %c %f %f", &op, &op1, &op2);
        switch (op) {
            case '+':
                ans = op1 + op2;
                break;
            case '-':
                ans = op1 - op2;
                break;
            case '*':
                ans = op1 * op2;
                break;
            case '/':
                if (op2 == 0) {
                    printf("Division by zero\n");
                    fclose(fin); fclose(fout);
                    return -4;
                }
                else {
                    ans = op1 / op2;
                }
                break;

            default:
                printf("Unrecognized operation.\n");
                return -3;
        }
        fprintf(fout, "%c %.2f\n", op, ans);
    }

    fclose(fin); fclose(fout);
    return 0;
}
