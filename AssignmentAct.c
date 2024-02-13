#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Define a struct for student information.
struct Student {
    int id_number;
    char firstname[50];
    char middlename[50];
    char lastname[50];
    char program[50];
    int year;
};

//Function to display Menu.
void displayMenu() {
    printf("\n--------------Menu-------------\n");
    printf("1. Add New Student\n");
    printf("2. Display Specific Student\n");
    printf("3. Display All Students\n");
    printf("4. Exit\n");
    printf("\nEnter your Choice:  ");
}

void addNewStudent(struct Student student[], int *count) {
    printf("Enter your ID number: ");
    scanf("%d", &student[*count].id_number);
    printf("Enter your first name: ");
    fflush(stdin);
    scanf("%[^\n]s", student[*count].firstname);
    printf("Enter your middle name: ");
    fflush(stdin);
    scanf("%[^\n]s", student[*count].middlename);
    printf("Enter your last name: ");
    fflush(stdin);
    scanf("%[^\n]s", student[*count].lastname);
    printf("Enter your program: ");
    fflush(stdin);
    scanf("%[^\n]s", student[*count].program);
    printf("Enter your year: ");
    scanf("%d", &student[*count].year);

    (*count)++;
    printf("\nStudent added successfully!\n");
}

void displaySpecificStudent(struct Student student[], int count, int id) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (student[i].id_number == id) {
            found = 1;
            printf("\n--- Student Details ---\n");
            printf("ID: %d\n", student[i].id_number);
            printf("Name: %s %s %s\n", student[i].firstname, student[i].middlename, student[i].lastname);
            printf("Program: %s\n", student[i].program);
            printf("Year: %d\n", student[i].year);
            printf("\n");
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void displayAllStudents(struct Student student[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- All Students ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", student[i].id_number);
        printf("Name: %s %s %s\n", student[i].firstname, student[i].middlename, student[i].lastname);
        printf("Program: %s\n", student[i].program);
        printf("Year: %d\n", student[i].year);
        printf("\n");
    }
}

int main () {
    struct Student student[10];
    int choice;
    int count = 0;
    int id;

    do {
        //To display menu.
        displayMenu();

        //to choose a number of choices.
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addNewStudent(student, &count); //to add the new student.
                break;
            case 2:
                printf("Enter the ID number of the student: ");
                scanf("%d", &id);
                displaySpecificStudent(student, count, id);// to search for displaying specific student.
                break;
            case 3:
                displayAllStudents(student, count);
                break;
            case 4:
                printf("\nEXITING.....\n");
                printf("\nThank You\n");
                break;
            default:
                printf("Invalid. Please try again\n");
        }
    } while(choice != 4);

    return 0;
}
