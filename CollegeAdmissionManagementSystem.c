#include <stdio.h>
#include <string.h>

#define MAX 100

// Structure for student data
struct Student {
    int roll;
    char name[50];
    char program[30];
    float marks;
};

// Array to hold multiple students
struct Student students[MAX];
int count = 0;

// Function to add a new student
void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    struct Student s;

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    getchar(); // Clear buffer
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0'; // Remove newline

    printf("Enter Program: ");
    scanf("%s", s.program);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    students[count++] = s;
    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Program: %s\n", students[i].program);
        printf("Marks: %.2f\n", students[i].marks);
    }
}