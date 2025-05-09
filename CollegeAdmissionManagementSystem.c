#include <stdio.h>

// Define the structure for a student
struct Student {
    int roll;
    char name[50];
    char program[30];
    float marks;
};

int main() {
    struct Student s;

    // Taking input from the user
    printf("Enter Student Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Student Name: ");
    getchar(); // Clear newline from buffer
    fgets(s.name, sizeof(s.name), stdin);

    printf("Enter Program (e.g., BSc, BBA): ");
    scanf("%s", s.program);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    // Displaying the entered student data
    printf("\n--- Student Details ---\n");
    printf("Roll Number: %d\n", s.roll);
    printf("Name: %s", s.name);  // already includes newline from fgets
    printf("Program: %s\n", s.program);
    printf("Marks: %.2f\n", s.marks);
return 0;
}