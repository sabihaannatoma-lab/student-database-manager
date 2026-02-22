

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Project: Student Record Management System
   Description: This program takes student details and saves them into a text file.
*/

struct Student {
    int roll;
    char name[50];
    float gpa;
};

int main() {
    struct Student s1;
    FILE *fp;

    printf("--- Student Record Management System ---\n\n");

    // Taking input from user
    printf("Enter Student Full Name: ");
    fgets(s1.name, sizeof(s1.name), stdin);
    s1.name[strcspn(s1.name, "\n")] = 0; // Removing the trailing newline character

    printf("Enter Roll Number: ");
    scanf("%d", &s1.roll);

    printf("Enter GPA: ");
    scanf("%f", &s1.gpa);

    // Opening file in append mode
    fp = fopen("students.txt", "a");

    if (fp == NULL) {
        printf("Error! File could not be opened.\n");
        return 1;
    }

    // Writing data to the file
    fprintf(fp, "Roll: %d | Name: %s | GPA: %.2f\n", s1.roll, s1.name, s1.gpa);
    
    // Closing the file
    fclose(fp);

    printf("\n------------------------------------\n");
    printf("Success! Data saved to 'students.txt'\n");
    printf("------------------------------------\n");

    return 0;
}
