#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[50];
    int age;
    struct student* next;
} student;

void printStudent(student* s) {
    printf("\tName: %s\t", s->name);
    printf("Age: %d\n", s->age);
}

void printStudentList(student* s) {
    printf("Printing student list\n");
    while (s != NULL) {
        printStudent(s);
        s = s->next;
    }
}

int main() {
    student* waitingList = NULL;
    student* lastStudent = NULL;

    // Allocate memory for a student
    student* s1 = (student*) malloc(sizeof(student));
    strcpy(s1->name, "John");
    s1->age = 20;
    s1->next = NULL;

    waitingList = s1;
    lastStudent = s1;

    printStudentList(waitingList);
    
    // Allocate memory for a new student
    student* s2 = (student*) malloc(sizeof(student));
    strcpy(s2->name, "Mary");
    s2->age = 21;
    s2->next = NULL;

    // Add the new student to the list
    lastStudent->next = s2;
    lastStudent = s2;        

    printStudentList(waitingList);

    // ask user to input a new student
    student* s3 = (student*) malloc(sizeof(student));
    printf("Please enter the name of the new student: ");
    scanf("%s", s3->name);
    printf("Please enter the age of the new student: ");
    scanf("%d", &s3->age);
    s3->next = NULL;

    // add the new student to the list
    lastStudent->next = s3;
    printStudentList(waitingList);
    
}