#include <stdio.h>
#include "data.h"
#include "billing.h" 
#include "analytics.h"

void displayAnalytics() {
    if (totalPatients == 0) {
        printf("\nno data available for analytics yet. please register patients.\n");
        return;
    }

    int level1 = 0, level2 = 0, level3 = 0;
    float totalRevenue = 0.0, totalDiscounts = 0.0;
    float highestBill = -1.0;
    int highestIdx = -1;

    for (int i = 0; i < totalPatients; i++) {
        // 1. urgency level counts[cite: 1]
        if (patientUrgency[i] == 1) level1++;
        else if (patientUrgency[i] == 2) level2++;
        else if (patientUrgency[i] == 3) level3++;

        float consult = calculateConsultationFee(i);
        float ward = calculateWardCost(i);
        float gross = consult + ward;
        float discount = calculateAgeDiscount(i, gross);
        float net = gross - discount;

        totalRevenue += net;
        totalDiscounts += discount;

        if (net > highestBill) {
            highestBill = net;
            highestIdx = i;
        }
    }

    printf("\n======================================================\n");
    printf("            HOSPITAL PERFORMANCE REPORTS              \n");
    printf("======================================================\n");
    
    printf("[1] PATIENT DEMOGRAPHICS\n");
    printf("Total Patients Registered : %d\n", totalPatients);
    printf(" - Normal (Level 1)       : %d\n", level1);
    printf(" - Urgent (Level 2)       : %d\n", level2);
    printf(" - Critical (Level 3)     : %d\n", level3);
    printf("------------------------------------------------------\n");

    printf("[2] FINANCIAL SUMMARY\n");
    printf("Total Revenue Earned      : LKR %.2f\n", totalRevenue);
    printf("Total Discounts Granted   : LKR %.2f\n", totalDiscounts);
    printf("------------------------------------------------------\n");


    printf("[3] WARD OCCUPANCY\n");
    int capacities[4] = {20, 10, 10, 5};
    for (int ward = 0; ward < 4; ward++) {
        int occupied = 0;
        for (int bed = 0; bed < capacities[ward]; bed++) {
            if (bedOccupancy[ward][bed] == 1) {
                occupied++;
            }
        }
        float percentage = ((float)occupied / capacities[ward]) * 100;
        printf(" - %-18s : %.1f%% ( %d / %d beds )\n", wardNames[ward], percentage, occupied, capacities[ward]);
    }
    printf("------------------------------------------------------\n");

    printf("[4] HIGHEST PAYING PATIENT\n");
    if (highestIdx != -1) {
        printf("Patient Name              : %s (PAT-%d)\n", patientNames[highestIdx], 1001 + highestIdx);
        printf("Total Bill                : LKR %.2f\n", highestBill);
    }
    printf("======================================================\n");
}