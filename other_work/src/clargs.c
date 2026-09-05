#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) return -1;
    int n = atoi(argv[1]);
    int d = atoi(argv[2]);
    for (int i = d; i <= n; i += d) printf("%d ", i);
    printf("\n");
}
