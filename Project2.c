#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of Students that can be stored
#define MAX_STUDENTS 100

// Define the structure for Student information
struct Student {
    char name[50];
    int rollNumber;
    float marks;
};

// Create an array to store students
struct Student students[MAX_STUDENTS];
int numStudents = 0;

// Function to add a new student
void addStudent() {
    if (numStudents == MAX_STUDENTS)
     {
        printf("Maximum number of students reached!\n");
        return;
    }

    struct Student newStudent;

    printf("Enter student name: ");
    scanf("%s", newStudent.name);

    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);

    printf("Enter marks: ");
    scanf("%f", &newStudent.marks);

    students[numStudents] = newStudent;
    numStudents++;

    printf("Student added successfully!\n");
}

// Function to display all students
void displayStudents() 
{
    if (numStudents == 0) 
    {
        printf("No students found!\n");
        return;
    }

    printf("Student List:\n");
    printf("--------------------------------------------------\n");
    printf("Name\t\tRoll Number\tMarks\n");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < numStudents; i++) {
        printf("%s\t\t%d\t\t%.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
    }

    printf("--------------------------------------------------\n");
}

// Function to search for a student by roll number
void searchStudent() 
{
    if (numStudents == 0) 
    {
        printf("No students found!\n");
        return;
    }

    int rollNumber;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < numStudents; i++) 
    {
        if (students[i].rollNumber == rollNumber) 
        {
            printf("Student found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Marks: %.2f\n", students[i].marks);
            return;
        }
    }

    printf("Student not found!\n");
}

// Function to update a student's information
void updateStudent() 
{
    printf("Enter the Roll number to update the entry: ");
    int rollNumber;
    scanf("%d", &rollNumber);

    for (int i = 0; i < numStudents; i++) 
    {
        if (students[i].rollNumber == rollNumber) 
        {
            printf("1. Name\n2. Roll Number\n3. Marks\n");
            int choice;
            scanf("%d", &choice);

            switch (choice) 
            {
                case 1:
                    printf("Enter the new Name: ");
                    scanf("%s", students[i].name);
                    break;
                case 2:
                    printf("Enter the new Roll Number: ");
                    scanf("%d", &students[i].rollNumber);
                    break;
                case 3:
                    printf("Enter the new Marks: ");
                    scanf("%f", &students[i].marks);
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }

            printf("UPDATED SUCCESSFULLY.\n");
            return;
        }
    }

    printf("Student not found!\n");
}

// Function to delete a student
void deleteStudent() 
{
    if (numStudents == 0) 
    {
        printf("No students found!\n");
        return;
    }

    int rollNumber;
    printf("Enter roll number to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < numStudents; i++) 
    {
        if (students[i].rollNumber == rollNumber) 
        {
            for (int j = i; j < numStudents - 1; j++) 
            {
                students[j] = students[j + 1];
            }
            numStudents--;

            printf("Student deleted successfully!\n");
            return;
        }

    }

    printf("Student not found!\n");

}

// main function for calling 

int main() 
{
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Total number of Students\n");
        printf("7. Students with highest marks\n");
        printf("8. Students with lowest marks\n");
        printf("9. Exit\n");
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
                updateStudent();
                break; 
            case 6:
        // Adding a case for displaying the number of students

             printf("Total number of students: %d\n", numStudents);
        break;
            case 7:
        // now Adding a case for displaying the student with the highest marks
             if (numStudents == 0) 
         {

            printf("No students found!\n");

         } 
        else 
        {
            float maxMarks = students[0].marks;
            int maxIndex = 0;
            for (int i = 1; i < numStudents; i++) 
            {
                if (students[i].marks > maxMarks)
                 {

                    maxMarks = students[i].marks;
                    maxIndex = i;
                }

            }
            printf("Student with the highest marks:\n");
            printf("Name: %s\n", students[maxIndex].name);
            printf("Roll Number: %d\n", students[maxIndex].rollNumber);
            printf("Marks: %.2f\n", students[maxIndex].marks);
        }
        break;
        case 8:
        // Here I am going Add a case for displaying the student with the lowest marks
        if (numStudents == 0) 
        {
            printf("No students found!\n");
        } 
        else 
        {
            float minMarks = students[0].marks;
            int minIndex = 0;
            for (int i = 1; i < numStudents; i++) 
            {
                if (students[i].marks < minMarks) 
                {
                    minMarks = students[i].marks;
                    minIndex = i;
                }

            }
            printf("Student with the lowest marks:\n");
            printf("Name: %s\n", students[minIndex].name);
            printf("Roll Number: %d\n", students[minIndex].rollNumber);
            printf("Marks: %.2f\n", students[minIndex].marks);
        
        case 9:
            exit(0);
            break;
        }
            
        // Add a default case for invalid choices
    
            default:
                printf("Invalid choice! Please try again.\n");
                break; 
        }

    }

    return 0;
}
