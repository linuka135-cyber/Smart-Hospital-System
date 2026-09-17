#ifndef BILLING_H
#define BILLING_H

// function to calculate estimated waiting time in minutes
int calculateWaitTime(int patientIndex);

// function to calculate the consultation fee with urgency surcharges
float calculateConsultationFee(int patientIndex);

// function to calculate total ward stay cost
float calculateWardCost(int patientIndex);

// function to calculate age-based subsidy discount
float calculateAgeDiscount(int patientIndex, float grossTotal);

// function to print the patient receipt
void generateBill(int patientIndex);

#endif