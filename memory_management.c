#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_SIZE 10 // Initial number of students
#define NEW_SIZE 6   // New size after shrinking
#define EMAIL_LENGTH 100 // Maximum length for each email

int main() {
    // Allocate memory for INIT_SIZE pointers to char (for emails)
    char **emails = (char **) malloc(INIT_SIZE * sizeof(char *));
    if (emails == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input email addresses
    for (int i = 0; i < INIT_SIZE; ++i) {
        // Allocate memory for each email
        emails[i] = (char *) malloc(EMAIL_LENGTH * sizeof(char));
        printf("Enter email for student %d: ", i+1);
        scanf("%s", emails[i]);
    }

    // Shrink array to size 6 using realloc
    char **shrunk = (char **) realloc(emails, NEW_SIZE * sizeof(char *));
    if (shrunk == NULL) {
        printf("Memory reallocation failed!\n");
    } else {
        emails = shrunk;
        printf("\nAfter shrinking, stored emails:\n");
        // Print only the first NEW_SIZE emails
        for (int i = 0; i < NEW_SIZE; ++i) {
            printf("Student %d: %s\n", i+1, emails[i]);
        }
    }

    // Free memory for each email
    for (int i = 0; i < NEW_SIZE; ++i) {
        free(emails[i]);
    }
    // Free the array of pointers
    free(emails);

    return 0;
}
