#include <stdio.h>


int main(void) {
    printf("Select operation (+ - * /)\n");
    int op = getchar();
    float op1, op2, ans;
    printf("First operand: \n");
    scanf(" %f", &op1);
    printf("Second operand: \n");
    scanf(" %f", &op2);

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
                return -2;
            }
            else {
                ans = op1 / op2;
            }
            break;

        default:
            printf("Unrecognized operation.\n");
            return -1;
    }
    printf("%c %.2f", op, ans);
}
