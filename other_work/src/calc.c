#include <stdio.h>

char get_operation(void);
double get_num(int n);
double apply_operation(double n1, double n2, char op);

int main(void) {
    double num1 = get_num(1);
    char operation = get_operation();
    double num2 = get_num(2);
    double result = apply_operation(num1, num2, operation);
    if (result != -1) printf("%f", result);
}

char get_operation(void) {
    char operation;
    printf("Desired operation (+, -, /, *)\n");
    scanf(" %c", &operation);
    return operation;
}

double get_num(int n) {
    double num;
    if (n == 1) {
        printf("1st number: \n");
    }
    else if (n == 2) {
        printf("2nd number: \n");
    }
    scanf("%lf", &num);
    return num;
}

double apply_operation(double n1, double n2, char op) {
    switch (op) {
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        case '/': return n1 / n2;
        case '*': return n1 * n2;
        default:
            printf("Undefined operation");
            return -1;
    }
}
