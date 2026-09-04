#include <stdio.h>

void get_input(int* ls);
int euler_gcf(int a, int b);

int main(void) {
    int arr[2];
    get_input(arr);
    int res = euler_gcf(arr[0], arr[1]);
    printf("%d\n", res);
    return 0;
}

void get_input(int* ls) {
    while (1) {
        printf("Enter 2 positive integers: \n");
        int scan_state = scanf("%d %d", &ls[0], &ls[1]);
        if (scan_state == 2 && ls[0] > 0 && ls[1] > 0) {break;}
        printf("Wrong Input. Try Again.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

int euler_gcf(int a, int b) {
    while (a % b != 0) {
        if (a < b) {int t = b; b = a; a = t;}
        a = a % b;
    }
    return b;
}
