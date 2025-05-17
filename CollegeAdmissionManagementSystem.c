#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student
{
    int roll;
    char name[50];
    char program[30];
    float marks;
};

// Array to hold multiple students
struct Student students[MAX];
int count = 0;

// Function to add a new student
void addStudent()
{
    if (count >= MAX)
    {
        printf("Student limit reached!\n");
        return;
    }

    struct Student s;
    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);
    getchar(); // Clear buffer

    printf("Enter Name: ");
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
void displayStudents()
{
    if (count == 0)
    {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No: %d\n", students[i].roll);
        printf("Name: %s\n", students[i].name);
        printf("Program: %s\n", students[i].program);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

// Function to search a student
void searchStudent()
{
    int roll;
    printf("Enter Roll Number to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
        {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", students[i].roll);
            printf("Name: %s\n", students[i].name);
            printf("Program: %s\n", students[i].program);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

// Function to delete a student
void deleteStudent()
{
    int roll, found = 0;
    printf("Enter Roll Number to delete: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++)
    {
        if (students[i].roll == roll)
        {
            for (int j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }
}

// Save students to file
void saveToFile()
{
    FILE *fp = fopen("students.dat", "wb");
    if (fp == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(students, sizeof(struct Student), count, fp);
    fclose(fp);
    printf("Data saved to file successfully.\n");
}

// Load students from file
void loadFromFile()
{
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL)
    {
        printf("No previous data found. Starting fresh.\n");
        return;
    }

    fread(&count, sizeof(int), 1, fp);
    fread(students, sizeof(struct Student), count, fp);
    fclose(fp);
    printf("Data loaded from file successfully.\n");
}

void showSummary()
{
    if (count == 0)
    {
        printf("No data available to summarize.\n");
        return;
    }

    int pass = 0, fail = 0;
    float totalMarks = 0.0;

    for (int i = 0; i < count; i++)
    {
        totalMarks += students[i].marks;
        if (students[i].marks >= 50)
            pass++;
        else
            fail++;
    }

    printf("\n--- Summary ---\n");
    printf("Total Students: %d\n", count);
    printf("Passed: %d\n", pass);
    printf("Failed: %d\n", fail);
    printf("Average Marks: %.2f\n", totalMarks / count);
}

void exportToTextFile() {
    FILE *fp = fopen("students.txt", "w");
    if (fp == NULL) {
        printf("Unable to create text file.\n");
        return;
    }

    fprintf(fp, "--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "Roll No: %d\n", students[i].roll);
        fprintf(fp, "Name: %s\n", students[i].name);
        fprintf(fp, "Program: %s\n", students[i].program);
        fprintf(fp, "Marks: %.2f\n\n", students[i].marks);
    }

    fclose(fp);
    printf("Student data exported to students.txt successfully.\n");
}

// Main Menu
int main()
{
    int choice;

    loadFromFile();

    do
    {
        printf("\n--- College Admission System Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Save to File\n");
        printf("6. Show Summary\n");
        printf("7. Export Data to Text File\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            saveToFile();
            break;
        case 6:
            showSummary();
            break;
        case 7:
            exportToTextFile(); 
            break;
        case 8:
            printf("Saving data and exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}