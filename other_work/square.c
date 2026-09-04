#include <stdio.h>

void print_square(int len);

int main(void)
{
    int len;
    printf("Length of one side of the square: \n");
    scanf("%d", &len);
    if (len <= 0)
    {
        printf("Invalid Input.\n");
        return -1;
    }
    print_square(len);
}

void print_square(int len)
{
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == len - 1 || i == 0) {
                printf("*");
            }
            else {
                if (j == len - 1 || j == 0) {
                    printf("*");
                }
                else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
