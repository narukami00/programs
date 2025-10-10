#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float grades[5];
} Student;

Student students[100];
int studentCount = 0;

void inputStudent() {
    printf("Input student ID: ");
    scanf("%d", &students[studentCount].id);
    printf("Input student name: ");
    scanf(" %[^\n]", students[studentCount].name);
    printf("Input student grades: ");
    for (int i = 0; i < 5; i++) {
        scanf("%f", &students[studentCount].grades[i]);
    }
    studentCount++;
}

void displayStudents() {
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Grades: ");
        for (int j = 0; j < 5; j++) {
            printf("%.2f . ", students[i].grades[j]);
        }
        printf("\n");
    }
}

void writeToFile() {
    FILE *file = fopen("2207006.txt", "w");
    if (file == NULL) {
        printf("Error! Unable to open file.\n");
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "ID: %d\n", students[i].id);
        fprintf(file, "Name: %s\n", students[i].name);
        fprintf(file, "Grades: ");
        for (int j = 0; j < 5; j++) {
            fprintf(file, "%.2f . ", students[i].grades[j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void findStudent() {
    int id;
    printf("Input the ID of the student to search: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Grades: ");
            for (int j = 0; j < 5; j++) {
                printf("%.2f ", students[i].grades[j]);
            }
            printf("\n");
            return;
        }
    }
    printf("No student found with ID %d\n", id);
}

void modifyStudent() {
    int id;
    printf("Input the ID of the student to edit: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Input new student name: ");
            scanf(" %[^\n]", students[i].name);
            printf("Input new student grades: ");
            for (int j = 0; j < 5; j++) {
                scanf("%f", &students[i].grades[j]);
            }
            printf("Student record updated successfully.\n");
            return;
        }
    }
    printf("No student found with ID %d\n", id);
}

void computeAverageGrade() {
    int id;
    printf("Input the ID of the student to calculate the average grade: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            float sum = 0;
            for (int j = 0; j < 5; j++) {
                sum += students[i].grades[j];
            }
            float average = sum / 5;
            printf("The average grade of the student is %.2f\n", average);
            return;
        }
    }
    printf("No student found with ID %d\n", id);
}

int proceedInput() {
    char choice;
    printf("Do you want to proceed? (Y/N): ");
    scanf(" %c", &choice);
    return (choice == 'Y' || choice == 'y');
}



int main() {
    int choice;
    do {
        printf("1. Register New Student\n");
        printf("2. Display Student List\n");
        printf("3. Edit Student Information\n");
        printf("4. Search for a Student\n");
        printf("5. Compute Average Student Grade\n");
        printf("6. Save Student List to File\n");
        printf("7. Exit Program\n");
        printf("Please enter your selection: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                modifyStudent();
                break;
            case 4:
                findStudent();
                break;
            case 5:
                computeAverageGrade();
                break;
            case 6:
                writeToFile();
                break;
            case 7:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid selection! Please try again.\n");
        }
    } while (choice != 7 && proceedInput());
    return 0;
}

