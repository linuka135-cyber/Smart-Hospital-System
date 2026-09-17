#include <stdio.h>
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