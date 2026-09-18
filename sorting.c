#include <stdio.h>
#include <string.h>
#include "data.h"
#include "sorting.h"

void displayPriorityQueue() {
    if (totalPatients == 0) {
        printf("\n no patients registered in the system yet.\n");
        return;
    }

    // created a temporary array of indices representing each registered patient
    int sortedIndices[100];
    for (int i = 0; i < totalPatients; i++) {
        sortedIndices[i] = i;
    }

    for (int i = 0; i < totalPatients - 1; i++) {
        for (int j = 0; j < totalPatients - i - 1; j++) {
            int currentIdx = sortedIndices[j];
            int nextIdx = sortedIndices[j + 1];
            
         
            if (patientUrgency[currentIdx] < patientUrgency[nextIdx]) {
                int temp = sortedIndices[j];
                sortedIndices[j] = sortedIndices[j + 1];
                sortedIndices[j + 1] = temp;
            }

        }
    }


    printf("\n======================================================\n");
    printf("              PRIORITY SORTING QUEUE                  \n");
    printf("======================================================\n");
    printf("%-12s | %-20s | %-12s\n", "PATIENT ID", "PATIENT NAME", "URGENCY");
    printf("------------------------------------------------------\n");
    
    for (int i = 0; i < totalPatients; i++) {
        int p = sortedIndices[i];
        
        char urgencyStr[15];
        if (patientUrgency[p] == 1) strcpy(urgencyStr, "1 (Normal)");
        else if (patientUrgency[p] == 2) strcpy(urgencyStr, "2 (Urgent)");
        else if (patientUrgency[p] == 3) strcpy(urgencyStr, "3 (Critical)");
        
        printf("PAT-%-8d | %-20s | %-12s\n", 1001 + p, patientNames[p], urgencyStr);
    }
    printf("======================================================\n");
}