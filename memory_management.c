#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define START_SIZE 10
#define TARGET_SIZE 6
#define EMAIL_SIZE 100

// Display function: prints all emails
void showEmails(char **list, int count) {
    printf("\nList of Email Addresses:\n");
    for (int i = 0; i < count; i++) {
        if (list[i] != NULL) {
            printf("%d. %s\n", i + 1, list[i]);
        }
    }
}

// Function to remove duplicate email entries
void deleteDuplicates(char ***list, int *count) {
    for (int i = 0; i < *count; i++) {
        for (int j = i + 1; j < *count; j++) {
            if ((*list)[i] != NULL && (*list)[j] != NULL &&
                strcmp((*list)[i], (*list)[j]) == 0) {
                free((*list)[j]);
                (*list)[j] = NULL;
            }
        }
    }

    // Compact array by skipping NULL entries
    int index = 0;
    for (int i = 0; i < *count; i++) {
        if ((*list)[i] != NULL) {
            (*list)[index] = (*list)[i];
            index++;
        }
    }

    *count = index;
    *list = (char **)realloc(*list, (*count) * sizeof(char *));
}

int main() {
    // Allocate space for 10 student emails
    char **emailList = (char **)malloc(START_SIZE * sizeof(char *));
    if (emailList == NULL) {
        printf("Error: Initial memory allocation failed.\n");
        return 1;
    }

    // predefined student emails (with one duplicate)
    char defaultEmails[START_SIZE][EMAIL_SIZE] = {
        "david.johnson@alustudent.com",
        "mary.williams@alustudent.com",
        "michael.brown@alustudent.com",
        "sarah.davis@alustudent.com",
        "james.wilson@alustudent.com",
        "rebecca.miller@alustudent.com",
        "daniel.garcia@alustudent.com",
        "mary.williams@alustudent.com", // the duplicate
        "joshua.martinez@alustudent.com",
        "rachel.anderson@alustudent.com"
    };

    // Allocate memory for each string and copy values
    for (int i = 0; i < START_SIZE; i++) {
        emailList[i] = (char *)malloc(EMAIL_SIZE * sizeof(char));
        if (emailList[i] == NULL) {
            printf("Error: Allocation failed for email %d.\n", i + 1);
            return 1;
        }
        strcpy(emailList[i], defaultEmails[i]);
    }

    int currentCount = START_SIZE;

    // Declare function pointers
    void (*printFunc)(char **, int) = showEmails;
    void (*removeFunc)(char ***, int *) = deleteDuplicates;

    printf("Initial Email List:\n");
    printFunc(emailList, currentCount);

    // Remove duplicates through function pointer
    removeFunc(&emailList, &currentCount);

    printf("\nAfter Removing Duplicates:");
    printFunc(emailList, currentCount);

    // Reduce array size to 6 using realloc
    if (currentCount > TARGET_SIZE) {
        for (int i = TARGET_SIZE; i < currentCount; i++) {
            free(emailList[i]);
        }
        emailList = (char **)realloc(emailList, TARGET_SIZE * sizeof(char *));
        currentCount = TARGET_SIZE;

        printf("\nAfter Reducing to %d Students:", TARGET_SIZE);
        printFunc(emailList, currentCount);
    }

    // Clean up memory
    for (int i = 0; i < currentCount; i++) {
        free(emailList[i]);
    }
    free(emailList);

    printf("\nMemory has been freed successfully.\n");
    return 0;
}
