#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int SECRET_NUM = 7;

int main(void) {
    int guess = -1;
    while (guess != SECRET_NUM) {
        printf("Guess a number (-1 to quit):\n");
        scanf("%d", &guess);
        if (guess == -1) {
            printf("Unlucky!");
            return -1;
        }
    }
    printf("Congratulations! the secret number was %d", SECRET_NUM);
    return 0;
}

