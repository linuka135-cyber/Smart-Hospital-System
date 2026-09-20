#include <stdio.h>
#include "data.h"
#include "billing.h"
#include "files.h"


void loadBedStatus() {
    FILE *file = fopen("beds_status.txt", "r");
    
   
    if (file == NULL) {
        return; 
    }

    for (int ward = 0; ward < 4; ward++) {
        for (int bed = 0; bed < 20; bed++) {
            fscanf(file, "%d", &bedOccupancy[ward][bed]);
        }
    }
    
    fclose(file);
    printf(">> System loaded previous bed occupancy data.\n");
}

void saveBedStatus() {
    FILE *file = fopen("beds_status.txt", "w"); 
    
    if (file == NULL) {
        printf(">> Error: Could not save bed status!\n");
        return;
    }

    
    for (int ward = 0; ward < 4; ward++) {
        for (int bed = 0; bed < 20; bed++) {
            fprintf(file, "%d ", bedOccupancy[ward][bed]);
        }
        fprintf(file, "\n");
    }
    
    fclose(file);
    printf(">> Bed occupancy saved successfully.\n");
}


void savePatientRecord(int i) {
    FILE *file = fopen("patient_records.txt", "a");
    
    if (file == NULL) {
        printf("\n>> Error: Could not update patient_records.txt\n");
        return;
    }

    
    float consult = calculateConsultationFee(i);
    float wardCost = calculateWardCost(i);
    float gross = consult + wardCost;
    float discount = calculateAgeDiscount(i, gross);
    float net = gross - discount;


    fprintf(file, "PAT-%d | Name: %s | Age: %d | Ward: %d | Total Bill: LKR %.2f\n", 
            1001 + i, patientNames[i], patientAges[i], patientWardID[i], net);
            
    fclose(file);
}