#include <stdio.h>

void binary_representation(unsigned int n, int *bin);

int main(void) {
    unsigned int num = 13;
    int binary[32] = {0};
    binary_representation(num, binary);
    int flag = 0;
    for (int i = 31; i >= 0; i--) {
        if (binary[i] == 1 || i == 0) flag = 1;
        if (flag) {
            printf("%d", binary[i]);
        }
    }
}

void binary_representation(unsigned int n, int *bin) {
    for (int i = 0; i < 32; i++) {
        bin[i] = n % 2;
        n /= 2;
    }
}


