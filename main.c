#include <stdio.h>
#include <stdlib.h>

// -Lookup Table Constants-

// Doctor specialties data
const char *specialtyNames[4] = {"General Practice (OPD)", "Paediatrics", "Cardiology", "Neurology"};
const float baseConsultationFees[4] = {1500.00, 2500.00, 4500.00, 5000.00};
const int consultationTimes[4] = {15, 20, 30, 30}; // in minutes
const int dailyPatientCaps[4] = {30, 20, 12, 10};

// Hospital Wards Data
const char *wardNames[4] = {"General Ward", "Paediatric Ward", "Surgical Ward", "ICU"};
const float wardDailyRates[4] = {3000.00, 6000.00, 12000.00, 25000.00};
const int wardCapacities[4] = {20, 10, 10, 5};

int main() {
    printf("===========================================\n");
    printf(" Smart Hospital & Resource Allocation System\n");
    printf("===========================================\n");
    printf("System initializing...\n");

    return 0;
}
