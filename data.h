#ifndef DATA_H
#define DATA_H

// Doctor Specialties Data Declarations
extern const char *specialtyNames[4];
extern const float baseConsultationFees[4];
extern const int consultationTimes[4];
extern const int dailyPatientCaps[4];

// Hospital Wards Data Declarations
extern const char *wardNames[4];
extern const float wardDailyRates[4];
extern const int wardCapacities[4];

// Bed occupancy matrix declaration
extern int bedOccupancy[4][20];

// Define maximum number of patients for the arrays
// The total daily patient cap across all 4 specialties is 72.
// Therefore, setting MAX_PATIENTS to 100 provides a safe operations.
#define MAX_PATIENTS 100

// Patient Details Arrays 
extern char patientNames[MAX_PATIENTS][100];
extern int patientAges[MAX_PATIENTS];
extern int patientUrgency[MAX_PATIENTS]; // 1 = Normal, 2 = Urgent, 3 = Critical

// Specialty and Admission Details Arrays
extern int patientSpecialtyID[MAX_PATIENTS]; // 1 to 4
extern int patientIsAdmitted[MAX_PATIENTS];  // 1 = Yes, 0 = No
extern int patientWardID[MAX_PATIENTS];      // 1 to 4
extern int patientDaysAdmitted[MAX_PATIENTS];
extern int patientAssignedBed[MAX_PATIENTS]; // To track which bed they got

// Global counters
extern int totalPatients;
extern int specialtyQueueCounts[4]; // To track the queue for waiting time calculations

#endif