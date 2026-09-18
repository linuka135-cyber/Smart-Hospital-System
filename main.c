#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "registration.h"
#include "sorting.h"


int main() {
    // Initialize the bed occupancy matrix to 0 - Available
    for (int ward = 0; ward < 4; ward++) {
        for (int bed = 0; bed < 20; bed++) {
            bedOccupancy[ward][bed] = 0;
        }
    }

    int choice;
    do {
        printf("\n===========================================\n");
        printf(" Smart Hospital & Resource Allocation System\n");
        printf("===========================================\n");
        printf("1. Register New Patient\n");
        printf("2. View Priority Queue\n");
        printf("3. Generate Performance Reports\n");
        printf("4. Exit System\n");
        printf("===========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerPatient();
                printf("\n>> Press Enter to return to the main menu...\n");
                system("pause > nul");
                break;

            case 2:
                displayPriorityQueue();
                printf("\n>> Press Enter to return to the main menu...\n");
                system("pause > nul");
                break;

            case 3:
                printf("\n--- Performance Analytics ---\n");





                break;
            case 4:
                printf("\nExiting system. Have a great day!\n");



                break;
            default:
                printf("\nInvalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
