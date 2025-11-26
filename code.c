#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Employee {
    int id;
    char name[50];
    int presentDays;
    int absentDays;
    int leaveDays;
};

void addEmployee();
void markAttendance();
void applyLeave();
void displayEmployees();

char dataFile[] = "employees.dat";

int main() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf(" ATTENDANCE & LEAVE MANAGEMENT\n");
        printf("==============================\n");
        printf("1. Add Employee\n");
        printf("2. Mark Attendance\n");
        printf("3. Apply Leave\n");
        printf("4. Display Employee Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addEmployee();
            break;
        case 2:
            markAttendance();
            break;
        case 3:
            applyLeave();
            break;
        case 4:
            displayEmployees();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
}

void addEmployee() {
    FILE *fp = fopen(dataFile, "ab");
    struct Employee e;

    printf("\nEnter Employee ID: ");
    scanf("%d", &e.id);
    printf("Enter Name: ");
    scanf("%s", e.name);

    e.presentDays = 0;
    e.absentDays = 0;
    e.leaveDays = 0;

    fwrite(&e, sizeof(struct Employee), 1, fp);
    fclose(fp);
    printf("Employee Added Successfully!\n");
}

void markAttendance() {
    int id, found = 0, choice;

    FILE *fp = fopen(dataFile, "rb+");
    struct Employee e;

    printf("\nEnter Employee ID to mark attendance: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.id == id) {
            found = 1;

            printf("\n1. Present\n2. Absent\nEnter attendance: ");
            scanf("%d", &choice);

            if (choice == 1)
                e.presentDays++;
            else if (choice == 2)
                e.absentDays++;
            else
                printf("Invalid option!\n");

            fseek(fp, -sizeof(e), SEEK_CUR);
            fwrite(&e, sizeof(e), 1, fp);
            printf("Attendance Updated.\n");
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Employee Not Found.\n");
}

void applyLeave() {
    int id, days, found = 0;

    FILE *fp = fopen(dataFile, "rb+");
    struct Employee e;

    printf("\nEnter Employee ID for leave: ");
    scanf("%d", &id);

    while (fread(&e, sizeof(e), 1, fp)) {
        if (e.id == id) {
            found = 1;

            printf("Enter number of leave days: ");
            scanf("%d", &days);

            e.leaveDays += days;

            fseek(fp, -sizeof(e), SEEK_CUR);
            fwrite(&e, sizeof(e), 1, fp);

            printf("Leave Updated.\n");
            break;
        }
    }
    fclose(fp);

    if (!found)
        printf("Employee Not Found.\n");
}

void displayEmployees() {
    FILE *fp = fopen(dataFile, "rb");
    struct Employee e;

    printf("\n==========================================\n");
    printf("             EMPLOYEE RECORDS             \n");
    printf("==========================================\n");
    printf("%-10s %-15s %-10s %-10s %-10s\n", 
           "ID", "Name", "Present", "Absent", "Leave");

    while (fread(&e, sizeof(e), 1, fp)) {
        printf("%-10d %-15s %-10d %-10d %-10d\n",
               e.id, e.name, e.presentDays, e.absentDays, e.leaveDays);
    }

    fclose(fp);
}
