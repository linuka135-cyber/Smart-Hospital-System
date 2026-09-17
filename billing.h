#ifndef BILLING_H
#define BILLING_H

// function to calculate estimated waiting time in minutes
int calculateWaitTime(int patientIndex);

// function to calculate the consultation fee with urgency surcharges
float calculateConsultationFee(int patientIndex);

#endif