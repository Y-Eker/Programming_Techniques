#include <stdio.h>
#include <string.h>

#define NR_MAX 20
#define NC_MAX 20
#define FILENAME_LEN_MAX 50

void read_data(FILE *fin, int mat[NR_MAX][NC_MAX], int nr, int nc);

int main(void) {
    char fin_name[FILENAME_LEN_MAX];
    fgets(fin_name, FILENAME_LEN_MAX, stdin);
    char *p = strchr(fin_name, '\n');
    if (p != NULL) *p = '\0';
    FILE *fin = fopen(fin_name, "r");
    if (!fin) return -1;
    int mat[NR_MAX][NC_MAX];
    int nr, nc;
    fscanf(fin, "%d %d", &nr, &nc);
    
    read_data(fin, mat, nr, nc);

    int points[NR_MAX] = {0};

    for (int match_day = 0; match_day < nc; match_day++) { 
        int i_max = 0;
        for (int team = 0; team < nr; team++) points[team] += mat[team][match_day];
        for (int team = 0; team < nr; team++) if (points[team] > points[i_max]) i_max = team;
        printf("Matchday %d Leader: %d\n", match_day + 1, i_max);
    }


    fclose(fin);
    return 0;
}

void read_data(FILE *fin, int mat[NR_MAX][NC_MAX], int nr, int nc) {
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            fscanf(fin, "%d", &mat[i][j]);
        }
    }
}