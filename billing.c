#include <stdio.h>
#include <string.h>
#include "data.h"
#include "billing.h"

int calculateWaitTime(int patientIndex) {
    int specialtyIndex = patientSpecialtyID[patientIndex] - 1;
    
    int peopleAhead = specialtyQueueCounts[specialtyIndex] - 1;
    
    if (peopleAhead < 0) {
        peopleAhead = 0;
    }

    int minsPerPatient = consultationTimes[specialtyIndex];
    return peopleAhead * minsPerPatient;
}

float calculateConsultationFee(int patientIndex) {
    int specialtyIndex = patientSpecialtyID[patientIndex] - 1;
    float baseFee = baseConsultationFees[specialtyIndex];
    float finalFee = baseFee;


    int urgency = patientUrgency[patientIndex];

    if (urgency == 2) {
        finalFee = baseFee + (baseFee * 0.20);
    } else if (urgency == 3) {
        finalFee = baseFee + (baseFee * 0.50);
    }

    return finalFee;
}

float calculateWardCost(int patientIndex) {
    // if patient is opd, ward cost is 0
    if (patientIsAdmitted[patientIndex] == 0) {
        return 0.00;
    }
    
    int wardIndex = patientWardID[patientIndex] - 1;
    float dailyRate = wardDailyRates[wardIndex];
    int days = patientDaysAdmitted[patientIndex];
    
    return dailyRate * days;
}

float calculateAgeDiscount(int patientIndex, float grossTotal) {
    int age = patientAges[patientIndex];
    

    if (age < 5 || age > 65) {
        return grossTotal * 0.15; 
    }
    
    return 0.00;
}

void generateBill(int patientIndex) {
    int specialtyIndex = patientSpecialtyID[patientIndex] - 1;
    int wardIndex = patientWardID[patientIndex] - 1;
    int urgency = patientUrgency[patientIndex];
    int age = patientAges[patientIndex];
    int days = patientDaysAdmitted[patientIndex];
    

    float baseFee = baseConsultationFees[specialtyIndex];
    float consultationFee = calculateConsultationFee(patientIndex);
    float surcharge = consultationFee - baseFee;
    float wardCost = calculateWardCost(patientIndex);
    float grossTotal = consultationFee + wardCost;
    float discount = calculateAgeDiscount(patientIndex, grossTotal);
    float netTotal = grossTotal - discount;
    int waitTime = calculateWaitTime(patientIndex);


    char urgencyText[20];
    int surchargePercent = 0;
    if (urgency == 1) { strcpy(urgencyText, "Normal"); surchargePercent = 0; }
    else if (urgency == 2) { strcpy(urgencyText, "Urgent"); surchargePercent = 20; }
    else if (urgency == 3) { strcpy(urgencyText, "Critical"); surchargePercent = 50; }


    printf("\n====================================================\n");
    printf(" SMART HOSPITAL ADMISSION & BILL\n");
    printf("----------------------------------------------------------------------------------------\n");
    printf("Patient ID : PAT-%d\n", 1001 + patientIndex);
    printf("Patient Name : %s\n", patientNames[patientIndex]);
    
    if (age < 5 || age > 65) {
        printf("Age : %d Years (15%% Subsidy Eligible)\n", age);
    } else {
        printf("Age : %d Years\n", age);
    }
    
    printf("Specialty : %s\n", specialtyNames[specialtyIndex]);
    
    if (patientIsAdmitted[patientIndex] == 1) {
        printf("Assigned Ward : %s (Bed #%02d)\n", wardNames[wardIndex], patientAssignedBed[patientIndex]);
    } else {
        printf("Assigned Ward : Not Admitted (OPD)\n");
    }

    printf("Urgency Level : Level %d (%s)\n", urgency, urgencyText);
    printf("----------------------------------------------------------------------------------------\n");
    
    printf("Base Consultation Fee : LKR %.2f\n", baseFee);
    
    if (surchargePercent > 0) {
        printf("Emergency Surcharge : LKR %.2f (%d%%)\n", surcharge, surchargePercent);
    } else {
        printf("Emergency Surcharge : LKR 0.00\n");
    }
    
    if (patientIsAdmitted[patientIndex] == 1) {
        printf("Ward Stay Cost (%d Days) : LKR %.2f\n", days, wardCost);
    } else {
        printf("Ward Stay Cost (0 Days) : LKR 0.00\n");
    }

    printf("----------------------------------------------------------------------------------------\n");
    printf("Gross Total Bill : LKR %.2f\n", grossTotal);
    
    if (discount > 0) {
        printf("Age Subsidy Discount : LKR -%.2f (15%%)\n", discount);
    } else {
        printf("Age Subsidy Discount : LKR 0.00\n");
    }
    
    printf("----------------------------------------------------------------------------------------\n");
    printf("Final Payable Amount : LKR %.2f\n", netTotal);
    
    if (waitTime == 0) {
        printf("Estimated Waiting Time : 0.00 mins (Immediate Attention)\n");
    } else {
        printf("Estimated Waiting Time : %d.00 mins\n", waitTime);
    }
    printf("====================================================\n");
}