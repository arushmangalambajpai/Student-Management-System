#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int s = 0;

struct student {
    char first_name[100];
    char last_name[100];
    int roll_no;
    float cgpa;
    int courseid[5];
    int fee;  // 0 for unpaid, 1 for paid
} stud[50]; 

void addstudent() {
    printf("You have selected 'Add a new student' as option.\n");
    printf("Add details of students below:\n");
    printf("Enter the first name of the student:\n");
    scanf("%s", stud[s].first_name);
    printf("Enter the last name of the student:\n");
    scanf("%s", stud[s].last_name);
    printf("Enter the roll number to be assigned:\n");
    scanf("%d", &stud[s].roll_no);
    printf("Enter the CGPA of the student:\n");
    scanf("%f", &stud[s].cgpa);
    printf("Enter the course Id of each course:\n");

    for (int j = 0; j < 5; j++) {
        scanf("%d", &stud[s].courseid[j]);
    }
    stud[s].fee = 0;  // Unpaid by default
    s++;
    printf("The fee is set to unpaid for the new student.\n");
}

void displayinfo(int rn) {
    for (int i = 0; i < s; i++) {
        if (rn == stud[i].roll_no) {
            printf("First name of the student is %s\n", stud[i].first_name);
            printf("Last name of the student is %s\n", stud[i].last_name);
            printf("The CGPA of the student is %.2f\n", stud[i].cgpa);
            printf("Given course ids followed by the student:\n");
            for (int j = 0; j < 5; j++) {
                printf("The course id is %d\n", stud[i].courseid[j]);
            }
            printf("The fee status is %s\n", stud[i].fee ? "paid" : "unpaid");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rn);
}

void findbyrollno() {
    int rn;
    printf("Enter the roll no. of the student:\n");
    scanf("%d", &rn);

    for (int j = 0; j < s; j++) {
        if (rn == stud[j].roll_no) {
            printf("The student's details are as follows:\n");
            displayinfo(rn);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rn);
}

void countstudent() {
    printf("The total number of students is %d\n", s);
}

void deletestudent() {
    int rn;
    printf("Enter the roll number you want to delete:\n");
    scanf("%d", &rn);

    for (int j = 0; j < s; j++) {
        if (rn == stud[j].roll_no) {
            for (int k = j; k < s - 1; k++) {
                stud[k] = stud[k + 1];
            }
            s--;
            printf("The student is removed successfully\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rn);
}

void updatestudent() {
    printf("Enter the roll number to update the entry:\n");
    int x;
    scanf("%d", &x);
    for (int j = 0; j < s; j++) {
        if (stud[j].roll_no == x) {
            printf("1. First name\n"
                   "2. Last name\n"
                   "3. Roll number\n"
                   "4. CGPA\n"
                   "5. Courses\n");
            int z;
            scanf("%d", &z);
            switch (z) {
                case 1:
                    printf("Enter the new first name:\n");
                    scanf("%s", stud[j].first_name);
                    break;
                case 2:
                    printf("Enter the new last name:\n");
                    scanf("%s", stud[j].last_name);
                    break;
                case 3:
                    printf("Enter the new roll number:\n");
                    scanf("%d", &stud[j].roll_no);
                    break;
                case 4:
                    printf("Enter the new CGPA:\n");
                    scanf("%f", &stud[j].cgpa);
                    break;
                case 5:
                    printf("Enter the new courses:\n");
                    for (int k = 0; k < 5; k++) {
                        scanf("%d", &stud[j].courseid[k]);
                    }
                    break;
                default:
                    printf("Invalid option.\n");
                    return;
            }
            printf("Updated successfully.\n");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", x);
}

void findbyname() {
    char search[100];
    printf("Enter the first name of the student:\n");
    scanf("%s", search);
    for (int j = 0; j < s; j++) {
        if (!strcmp(stud[j].first_name, search)) {
            displayinfo(stud[j].roll_no);
            return;
        }
    }
    printf("Student with first name %s not found.\n", search);
}

void coursestudent() {
    int id;
    printf("Enter the course ID to find out about:\n");
    scanf("%d", &id);

    int found = 0;
    for (int j = 0; j < s; j++) {
        for (int d = 0; d < 5; d++) {
            if (id == stud[j].courseid[d]) {
                displayinfo(stud[j].roll_no);
                found = 1;
                break;
            }
        }
    }
    if (!found) {
        printf("No student found with course ID %d.\n", id);
    }
}

void checkfee() {
    int rn;
    printf("Enter the roll number to check the fee status:\n");
    scanf("%d", &rn);
    for (int i = 0; i < s; i++) {
        if (rn == stud[i].roll_no) {
            printf("The fee status for roll number %d is %s\n", rn, stud[i].fee ? "paid" : "unpaid");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rn);
}

void updatefee() {
    int rn;
    printf("Enter the roll number to update the fee status:\n");
    scanf("%d", &rn);
    for (int i = 0; i < s; i++) {
        if (rn == stud[i].roll_no) {
            printf("Enter 1 for paid, 0 for unpaid:\n");
            int fee_status;
            scanf("%d", &fee_status);
            stud[i].fee = fee_status;
            printf("The fee status for roll number %d is now %s\n", rn, stud[i].fee ? "paid" : "unpaid");
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rn);
}

int main() {
    int choice;
    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Find Student by Roll Number\n");
        printf("3. Count Students\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Find Student by Name\n");
        printf("7. Find Students by Course ID\n");
        printf("8. Check Fee Status\n");
        printf("9. Update Fee Status\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addstudent();
                break;
            case 2:
                findbyrollno();
                break;
            case 3:
                countstudent();
                break;
            case 4:
                deletestudent();
                break;
            case 5:
                updatestudent();
                break;
            case 6:
                findbyname();
                break;
            case 7:
                coursestudent();
                break;
            case 8:
                checkfee();
                break;
            case 9:
                updatefee();
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}
