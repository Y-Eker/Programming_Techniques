#include <string.h>
#include <stdio.h>

#define FIN_NAME_MAXLEN 21
#define SELECTOR_MAXLEN 11
#define DIRECTION_MAXLEN 11
#define NR_MAX 30
#define NC_MAX 30

void rotate_row(int mat[NR_MAX][NC_MAX], int nr, int nc, int index, int dir, int amount);
void rotate_col(int mat[NR_MAX][NC_MAX], int nr, int nc, int index, int dir, int amount);
void print_matrix(int mat[NR_MAX][NC_MAX], int nr, int nc);

int main(void) {
    // Get the filename
    printf("Insert the name of the input file: \n");
    char fin_name[FIN_NAME_MAXLEN];
    fscanf(stdin, "%20s", fin_name);
    // Open file
    FILE *fin = fopen(fin_name, "r");
    if (!fin) {printf("Error while accessing the input file.\n"); return 1;}
    // Get the dimensions of the matrix
    int matrix[NR_MAX][NC_MAX];
    int nr, nc;
    fscanf(fin, "%d %d", &nr, &nc);
    // Read data into matrix
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }
    print_matrix(matrix, nr, nc); // print the original matrix
    // Ask user for isntructions, apply and print the result
    while (1) {
        printf("Instruction: \n");
        char selector[SELECTOR_MAXLEN], direction[DIRECTION_MAXLEN];
        int index, locations;
        fscanf(stdin, "%10s", selector);
        if (strcmp(selector, "end") == 0) {
            break;
        }
        fscanf(stdin, "%d %10s %d", &index, direction, &locations);
        
        if (strcmp(selector, "row") == 0) {
            int dir;
            if (strcmp(direction, "right") == 0) dir = 1;
            else if (strcmp(direction, "left") == 0) dir = -1;
            else {
                printf("Wrong direction, usage is <selector> <index> <direction> <locations> where direction is right or left\n");
                continue;
            }
            rotate_row(matrix, nr, nc, index - 1, dir, locations);
        }
        else if (strcmp(selector, "column") == 0) {
            int dir;
            if (strcmp(direction, "down") == 0) dir = 1;
            else if (strcmp(direction, "up") == 0) dir = -1;
            else {
                printf("Wrong direction, usage is <selector> <index> <direction> <locations> where direction is up or down\n");
                continue;
            }
            rotate_col(matrix, nr, nc, index - 1, dir, locations);
        }
        else {
            printf("Wrong selector, usage is <selector> <index> <direction> <locations> where selector is row column or end\n");
            continue;
        }
        print_matrix(matrix, nr, nc);
    }
    // Close the files and finish the program
    fclose(fin);
    return 0;
}

void rotate_row(int mat[NR_MAX][NC_MAX], int nr, int nc, int index, int dir, int amount) {
    if (amount < 0) {printf("Amount must be positive\n"); return;}
    if (index < 0 || index >= nr) {printf("Index must be valid\n"); return;}
    amount %= nc;
    if (dir == 1) {
        for (int i = 0; i < amount; i++) {
            int temp = mat[index][nc - 1];
            for (int j = nc - 1; j > 0; j--) {
                mat[index][j] = mat[index][j - 1];
            }
            mat[index][0] = temp;
        }
    }
    else {
        for (int i = 0; i < amount; i++) {
            int temp = mat[index][0];
            for (int j = 0; j < nc - 1; j++) {
                mat[index][j] = mat[index][j + 1];
            }
            mat[index][nc - 1] = temp;
        }
    }
}

void rotate_col(int mat[NR_MAX][NC_MAX], int nr, int nc, int index, int dir, int amount) {
    if (amount < 0) {printf("Amount must be positive\n"); return;}
    if (index < 0 || index >= nc) {printf("Index must be valid\n"); return;}
    amount %= nr;
    if (dir == 1) {
        for (int i = 0; i < amount; i++) {
            int temp = mat[nr - 1][index];
            for (int j = nr - 1; j > 0; j--) {
                mat[j][index] = mat[j - 1][index];
            }
            mat[0][index] = temp;
        }
    }
    else {
        for (int i = 0; i < amount; i++) {
            int temp = mat[0][index];
            for (int j = 0; j < nr - 1; j++) {
                mat[j][index] = mat[j + 1][index];
            }
            mat[nr - 1][index] = temp;
        }
    }
}

void print_matrix(int mat[NR_MAX][NC_MAX], int nr, int nc) {
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}
