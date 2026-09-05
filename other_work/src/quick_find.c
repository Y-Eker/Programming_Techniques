#include <stdio.h>
# define N 10

int main(void) {
    int id[N];
    for (int i = 0; i < N; i++) {
        id[i] = i;
    }
    printf("Initial state: 0 1 2 3 4 5 6 7 8 9\n          ids: 0 1 2 3 4 5 6 7 8 9\n");
    while (1) {
        int p, q;
        printf("Enter Pairs: \n");
        int scan_return = scanf("%d %d", &p, &q);
        if (scan_return != 2 || p < 0 || p > N - 1 || q < 0 || q > N - 1) {
            break;
        }
        if (id[p] != id[q]) {
            int a = id[p];
            for (int i = 0; i < N; i++) {
                if (id[i] == a) {
                    id[i] = id[q];
                }
            }
        }
        printf("The elements: ");
        for (int i = 0; i < N; i++) {
            printf("%d ", id[i]);
        }
        printf("\n     The ids: 0 1 2 3 4 5 6 7 8 9\n");
    }

    return 0;
}
