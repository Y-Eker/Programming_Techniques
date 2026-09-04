#include <stdio.h>
#define N 10

int main(void) {
    // Init arrays
    int id[N], sz[N];
    for (int i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    // Main Loop
    while (1) {
        int p, q;
        printf("Enter Pairs: \n");
        int scan_res = scanf("%d %d", &p, &q);
        if (scan_res != 2 || p < 0 || p > N - 1 || q < 0 || q > N - 1) {
            break;
        }

        int p_root = p, q_root = q;
        while (id[p_root] != p_root) {
            p_root = id[p_root];
        }
        while (id[q_root] != q_root) {
            q_root = id[q_root];
        }
        if (p_root != q_root) {
            if (sz[p_root] > sz[q_root]) {
                id[q_root] = p_root;
                sz[p_root] += sz[q_root];
            }
            else {
                id[p_root] = q_root;
                sz[q_root] += sz[p_root];
            }
        }
    }

    // Print results
    printf("Id: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", id[i]);
    }
    printf("\nSz: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", sz[i]);
    }
    printf("\n");
    return 0;
}

