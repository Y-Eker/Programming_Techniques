#include <stdio.h>
#include <string.h>

#define FIN_NAME_LEN 51
#define MAX_NR 50
#define MAX_NC 50

typedef struct {
    int h;
    int w;
    int row;
    int col;
} Rectangle;

int main(void) {
    // get the filename
    printf("Please enter the filename: \n");
    char fin_name[FIN_NAME_LEN];
    fgets(fin_name, FIN_NAME_LEN, stdin);
    char *c_ptr = strchr(fin_name, '\n');
    if (c_ptr) *c_ptr = '\0';
    // open the file
    FILE *fin;
    if ((fin = fopen(fin_name, "r")) == NULL) {printf("Error while accessing the input file.\n"); return 1;}
    // read the data onto a matrix
    int matrix[MAX_NR][MAX_NC];
    int nr, nc;
    fscanf(fin, "%d %d", &nr, &nc);
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            fscanf(fin, "%d", &matrix[i][j]);
        }
    }
    // loop the matrix to identify rectangles and check if they're the current max rect in height, width, or area
    Rectangle rect_max_h = {0}, rect_max_w = {0}, rect_max_area = {0};
    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            if (matrix[i][j] == 1) {
                // check if the left of the curr element is a frame
                int is_left_frame = j - 1 < 0 || matrix[i][j - 1] == 0;
                // check if the top of the curr element is a frame
                int is_top_frame = i - 1 < 0 || matrix[i - 1][j] == 0;
                // if both the top and the left is a frame, then we have a root element at hand, initialize a new rectangle 
                if (is_top_frame && is_left_frame) {
                    int h = 0, w = 0;
                    for (int k = i; k < nr && matrix[k][j]; k++) h++;
                    for (int k = j; k < nc && matrix[i][k]; k++) w++;
                    if (rect_max_h.h < h) {
                        rect_max_h.h = h;
                        rect_max_h.w = w;
                        rect_max_h.row = i;
                        rect_max_h.col = j;
                    }
                    if (rect_max_w.w < w) {
                        rect_max_w.h = h;
                        rect_max_w.w = w;
                        rect_max_w.row = i;
                        rect_max_w.col = j;
                    }
                    if (rect_max_area.h * rect_max_area.w < h * w) {
                        rect_max_area.h = h;
                        rect_max_area.w = w;
                        rect_max_area.row = i;
                        rect_max_area.col = j;
                    }
                }
            }
        }
    }
    // print the acquired rects
    printf("Max height region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n", rect_max_h.row, rect_max_h.col, rect_max_h.h, rect_max_h.w, rect_max_h.w * rect_max_h.h);
    printf("Max width region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n", rect_max_w.row, rect_max_w.col, rect_max_w.h, rect_max_w.w, rect_max_w.w * rect_max_w.h);
    printf("Max area region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n", rect_max_area.row, rect_max_area.col, rect_max_area.h, rect_max_area.w, rect_max_area.w * rect_max_area.h);
    // close the file and exit
    fclose(fin);
    return 0;
}
