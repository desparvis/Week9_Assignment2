#include <stdio.h>
#include <string.h>

#define SIZE 20
#define LENGTH 30

// Function to sort names in ascending (A–Z) order
void sortAscending(char names[][LENGTH], int count) {
    char temp[LENGTH];
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

// Function to sort names in descending (Z–A) order
void sortDescending(char names[][LENGTH], int count) {
    char temp[LENGTH];
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) < 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}

// Function to display the list of names
void showNames(char names[][LENGTH], int count) {
    printf("\nSorted Names:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, names[i]);
    }
}

int main() {
    // Predefined list of names (mix of biblical and international)
    char nameList[SIZE][LENGTH] = {
        "David", "Mary", "Daniel", "Ruth", "Samuel",
        "Esther", "Joseph", "Naomi", "John", "Sarah",
        "Michael", "Abel", "Isaac", "Leah", "Jacob",
        "Paul", "Peter", "Anna", "Lydia", "Elijah"
    };

    int option;
    void (*sortFunction)(char[][LENGTH], int);  // Function pointer

    printf("Name Sorting System\n");
    printf("-------------------\n");
    printf("1. Sort in Ascending order (A–Z)\n");
    printf("2. Sort in Descending order (Z–A)\n");
    printf("Choose sorting option (1 or 2): ");
    scanf("%d", &option);

    if (option == 1) {
        sortFunction = sortAscending;
    } else if (option == 2) {
        sortFunction = sortDescending;
    } else {
        printf("Invalid choice.\n");
        return 0;
    }

    // Call the selected sorting function via function pointer
    (*sortFunction)(nameList, SIZE);

    // Display final sorted list
    showNames(nameList, SIZE);

    return 0;
}
