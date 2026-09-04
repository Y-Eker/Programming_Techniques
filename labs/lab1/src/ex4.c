#include <stdio.h>
#define PI 3.14

int main(void) {
    printf("Square (Q) or Circle (I)\n");
    printf("If Square, Diagonal (D) or Side (S)\n");
    printf("If Circle, Diameter (D) or Radius (R)\n");
    printf("Lastly, give the length as an integer.\n");
    printf("Your Input Please (ex. QD10 for a square with 10 units diagonal length)\n");
    char shape, len_type;
    int len;
    float area;
    scanf(" %c%c%d", &shape, &len_type, &len);
    switch (shape) {
        case 'Q':
            switch (len_type) {
            case 'D':
                    area = (float) len * (float) len / 2.0;
                    break;
            case 'S':
                    area = (float) len * (float) len;
                    break;

            default:
                    printf("Unidentified length type\n");
                    return -2;
            }
            break;
        case 'I':
            switch (len_type) {
            case 'D':
                    area = PI * (float) len * (float) len / 4.0;
                    break;
            case 'R':
                    area = PI * (float) len * (float) len;
                    break;

            default:
                    printf("Unidentified length type\n");
                    return -2;
            }
            break;

        default:
            printf("Unidentified shape\n");
            return -1;
    }
    printf("Area: %.1f", area);
}


