#include <stdio.h>
#include <string.h> 
#include "data.h"
#include "registration.h"

void registerPatient() {

    if (totalPatients >= MAX_PATIENTS) {
        printf("\nerror: maximum system capacity reached for today.\n");
        return;
    }

    int i = totalPatients;

    printf("\n--- Patient Registration ---\n");

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter patient name: ");
    fgets(patientNames[i], 100, stdin);
    patientNames[i][strcspn(patientNames[i], "\n")] = 0;

    printf("Enter patient age: ");
    scanf("%d", &patientAges[i]);

    printf("Enter urgency level (1 = normal, 2 = urgent, 3 = critical): ");
    scanf("%d", &patientUrgency[i]);

    printf("Enter specialty ID (1 to 4): ");
    scanf("%d", &patientSpecialtyID[i]);
    
    specialtyQueueCounts[patientSpecialtyID[i] - 1]++;

    printf("Is patient admitted to ward? (1 = yes, 0 = no): ");
    scanf("%d", &patientIsAdmitted[i]);

    if (patientIsAdmitted[i] == 1) {
        printf("Enter ward ID (1 to 4): ");
        scanf("%d", &patientWardID[i]);
        printf("Enter days admitted: ");
        scanf("%d", &patientDaysAdmitted[i]);

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

    totalPatients++;
    printf("\nRegistration complete!\n");
}