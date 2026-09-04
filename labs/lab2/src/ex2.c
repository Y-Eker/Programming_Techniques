#include <stdio.h>

int fibonacci(int n);
int fibonacci_mult(int n);

int main(void) {
    int n;
    printf("Nth Fibonacci Number: \n");
    scanf("%d", &n);
    int result = fibonacci_mult(n);
    printf("#%d Fibonacci Number is %d\n", n, result);
}


int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacci_mult(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) * fibonacci(n-2);
}
