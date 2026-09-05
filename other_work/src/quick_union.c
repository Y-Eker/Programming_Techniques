#include <stdio.h>
#define N 10

int main(void) {
    int id[N];
    for (int i = 0; i < N; i++) {
        id[i] = i;
    }

    while (1) {
        int p, q;
        printf("Enter Pairs: \n");
        int scan_state = scanf("%d %d", &p, &q);
        if (scan_state != 2 || p < 0 || p > N - 1 || q < 0 || q > N - 1) {
            break;
        }
        int p_root = p;
        while (id[p_root] != p_root) {
            p_root = id[p_root];
        }
        int q_root = q;
        while (id[q_root] != q_root) {
            q_root = id[q_root];
        }
        if (p_root != q_root) {
            id[p_root] = q_root;
        }
    }

    printf("Result: \n");
    for (int i = 0; i < N; i++) {
        printf("%d ", id[i]);
    }
    printf("\n");
    return 0;
}
