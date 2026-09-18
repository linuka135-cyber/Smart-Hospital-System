#include <stdio.h>
#include <string.h> 
#include "data.h"
#include "registration.h"
#include "billing.h"

void registerPatient() {

    if (totalPatients >= MAX_PATIENTS) {
        printf("\nerror: maximum system capacity reached for today.\n");
        return;
    }

    int i = totalPatients;
    int check;

    printf("\n--- Patient Registration ---\n");


    printf("Enter patient name: ");
    fgets(patientNames[i], 100, stdin);
    patientNames[i][strcspn(patientNames[i], "\n")] = 0;

    do {
        printf("Enter patient age: ");
        check = scanf("%d", &patientAges[i]);
        while (getchar() != '\n'); 

        if (check != 1 || patientAges[i] < 0 || patientAges[i] > 200) {
            printf(">> error: please enter a valid age (0-200).\n");
        } else {
            break;
        }
    } while (1);

    do {
        printf("Enter urgency level (1 = normal, 2 = urgent, 3 = critical): ");
        check = scanf("%d", &patientUrgency[i]);
        while (getchar() != '\n'); 

        if (check != 1 || patientUrgency[i] < 1 || patientUrgency[i] > 3) {
            printf(">> error: please enter 1, 2, or 3.\n");
        } else {
            break;
        }
    } while (1);

    do {
        printf("Enter specialty ID (1 to 4): ");
        check = scanf("%d", &patientSpecialtyID[i]);
        while (getchar() != '\n'); 

        if (check != 1 || patientSpecialtyID[i] < 1 || patientSpecialtyID[i] > 4) {
            printf(">> error: please enter a valid ID between 1 and 4.\n");
        } else {
            break;
        }
    } while (1);
    
    specialtyQueueCounts[patientSpecialtyID[i] - 1]++;

    do {
        printf("Is patient admitted to ward? (1 = yes, 0 = no): ");
        check = scanf("%d", &patientIsAdmitted[i]);
        while (getchar() != '\n'); 

        if (check != 1 || (patientIsAdmitted[i] != 0 && patientIsAdmitted[i] != 1)) {
            printf(">> error: please enter 1 for yes or 0 for no.\n");
        } else {
            break;
        }
    } while (1);

    if (patientIsAdmitted[i] == 1) {
        do {
            printf("Enter ward ID (1 to 4): ");
            check = scanf("%d", &patientWardID[i]);
            while (getchar() != '\n'); 

            if (check != 1 || patientWardID[i] < 1 || patientWardID[i] > 4) {
                printf(">> error: please enter a valid ward ID between 1 and 4.\n");
            } else {
                break;
            }
        } while (1);


        do {
            printf("Enter days admitted: ");
            check = scanf("%d", &patientDaysAdmitted[i]);
            while (getchar() != '\n'); 

            if (check != 1 || patientDaysAdmitted[i] <= 0) {
                printf(">> error: please enter a number greater than 0.\n");
            } else {
                break;
            }
        } while (1);

        // bed allocation
        int wardIndex = patientWardID[i] - 1;
        int bedAssigned = -1;

        for (int bed = 0; bed < wardCapacities[wardIndex]; bed++) {
            if (bedOccupancy[wardIndex][bed] == 0) {
                bedOccupancy[wardIndex][bed] = 1; 
                bedAssigned = bed + 1; 
                break; 
            }
        }

        if (bedAssigned != -1) {
            patientAssignedBed[i] = bedAssigned;
            printf("\n>> success: patient assigned to ward %d, bed #%02d\n", patientWardID[i], bedAssigned);
        } else {
            printf("\n>> warning: no beds available in ward %d! patient waitlisted.\n", patientWardID[i]);
            patientAssignedBed[i] = 0;
        }
    } else {
        patientWardID[i] = 0;
        patientDaysAdmitted[i] = 0;
        patientAssignedBed[i] = 0;
    }


    generateBill(i); 
    
    totalPatients++;
    printf("\nRegistration complete!\n");
}