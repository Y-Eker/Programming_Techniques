#include <stdio.h>
#include <string.h>


typedef struct {
    int is_initialized;
    unsigned int matricola;
    char name[100];
    char major[100];
    int age;
    double gpa;
} Student;


int main(void) {
    Student student1;
    student1.is_initialized = 1;
    student1.age = 19;
    student1.matricola = 351448;
    student1.gpa = 3.85;
    strcpy(student1.name, "Yigit Eker");
    strcpy(student1.major, "Computer Engineering");

    Student student2;
    student2.is_initialized = 1;
    student2.age = 20;
    student2.matricola = 357448;
    student2.gpa = 3.94;
    strcpy(student2.name, "Mario the Plumber");
    strcpy(student2.major, "Civil Engineering");

    Student student3 = {1, 313131, "Tung Tung", "ChemEng", 100, 2.6};

    Student classroom[30];
    classroom[0] = student1;
    classroom[1] = student2;
    classroom[5] = student3;

    double avg_gpa = 0.0;
    int counter = 0;
    for (int i = 0; i < 30; i++) {
        if (classroom[i].is_initialized == 1) {
            avg_gpa += classroom[i].gpa;
            counter += 1;
        }
    }
    printf("Average GPA: %f\n", avg_gpa / counter);
}


