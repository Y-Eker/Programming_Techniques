#include <string.h>
#include <stdio.h>

#define FIN_NAME "log.txt"
#define MAXLEN 31
#define MAX_TRIPS 1000

typedef struct {
    char route_code[MAXLEN];
    char departure[MAXLEN];
    char destination[MAXLEN];
    char date[11];
    char time_dep[9];
    char time_arr[9];
    int delay;
} Trip; 

int main(void) {
    // Open the file
    FILE *fin = fopen(FIN_NAME, "r");
    if (!fin) {printf("Unable to access the input file.\n"); return 1;}
    // Read data into an array of struct Trips
    Trip trips[MAX_TRIPS];
    int num_of_trips;
    fscanf(fin, "%d", &num_of_trips);
    for (int i = 0; i < num_of_trips && (fscanf(fin, "%30s %30s %30s %10s %8s %8s %d", trips[i].route_code, trips[i].departure, 
        trips[i].destination, trips[i].date, trips[i].time_dep, trips[i].time_arr, &trips[i].delay) == 7); i++);
    // Main menu loop
    while (1) {
        // Get the instruction input
        printf("Instruction (date, departure, destination, delay, tot-delay, end): \n");
        char instruction[MAXLEN];
        fgets(instruction, sizeof(instruction), stdin);
        char *p = strchr(instruction, '\n');
        if (p != NULL) *p = '\0';
        // Check it against instruction commands
        if (strcmp(instruction, "date") == 0) {
            printf("Date 1 and Date 2: \n");
            char date1[11], date2[11];
            fscanf(stdin, "%10s %10s", date1, date2);
            for (int i = 0; i < num_of_trips; i++) {
                if (strcmp(trips[i].date, date1) >= 0 && strcmp(trips[i].date, date2) <= 0)
                    printf("%s %s %s %s %s %s %d\n", trips[i].route_code, trips[i].departure, 
                    trips[i].destination, trips[i].date, trips[i].time_dep, trips[i].time_arr, trips[i].delay);
            }
        } else if (strcmp(instruction, "departure") == 0) {
            printf("Departure: \n");
            char departure[MAXLEN];
            fscanf(stdin, "%30s", departure);
            for (int i = 0; i < num_of_trips; i++) {
                if (strcmp(trips[i].departure, departure) == 0)
                    printf("%s %s %s %s %s %s %d\n", trips[i].route_code, trips[i].departure, 
                    trips[i].destination, trips[i].date, trips[i].time_dep, trips[i].time_arr, trips[i].delay);
            }
        } else if (strcmp(instruction, "destination") == 0) {
            printf("Destination: \n");
            char destination[MAXLEN];
            fscanf(stdin, "%30s", destination);
            for (int i = 0; i < num_of_trips; i++) {
                if (strcmp(trips[i].destination, destination) == 0)
                    printf("%s %s %s %s %s %s %d\n", trips[i].route_code, trips[i].departure, 
                    trips[i].destination, trips[i].date, trips[i].time_dep, trips[i].time_arr, trips[i].delay);
            }
        } else if (strcmp(instruction, "delay") == 0) {
            printf("Date 1 and Date 2: \n");
            char date1[11], date2[11];
            fscanf(stdin, "%10s %10s", date1, date2);
            for (int i = 0; i < num_of_trips; i++) {
                if (strcmp(trips[i].date, date1) >= 0 && strcmp(trips[i].date, date2) <= 0 && trips[i].delay > 0)
                    printf("%s %s %s %s %s %s %d\n", trips[i].route_code, trips[i].departure, 
                    trips[i].destination, trips[i].date, trips[i].time_dep, trips[i].time_arr, trips[i].delay);
            }
        } else if (strcmp(instruction, "tot-delay") == 0) {
            printf("Route code: \n");
            char route_code[MAXLEN];
            fscanf(stdin, "%30s", route_code);
            int tot_delay = 0;
            int flag = 0;
            for (int i = 0; i < num_of_trips; i++) {
                if (strcmp(trips[i].route_code, route_code) == 0) {
                    tot_delay += trips[i].delay;
                    flag = 1;
                }
            }
            if (flag)
                printf("Total delay of %s: %d\n", route_code, tot_delay);
            else
                printf("Cannot find Route %s\n", route_code);
        } else if (strcmp(instruction, "end") == 0) {
            break;
        } else {printf("Unidentified instruction please use one of (date, departure, destination, delay, tot-delay, end): \n"); continue;}
        // Clear the input buffer
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }
    // Close the file and exit
    fclose(fin);
    return 0;
}
