#include "data.h"

// Doctor Specialties Data
const char *specialtyNames[4] = {"General Practice (OPD)", "Paediatrics", "Cardiology", "Neurology"};
const float baseConsultationFees[4] = {1500.00, 2500.00, 4500.00, 5000.00};
const int consultationTimes[4] = {15, 20, 30, 30}; 
const int dailyPatientCaps[4] = {30, 20, 12, 10};

// Hospital Wards Data
const char *wardNames[4] = {"General Ward", "Paediatric Ward", "Surgical Ward", "ICU"};
const float wardDailyRates[4] = {3000.00, 6000.00, 12000.00, 25000.00};
const int wardCapacities[4] = {20, 10, 10, 5};

// Bed occupancy matrix Definition
int bedOccupancy[4][20];

// Patient Details arrays definition
char patientNames[MAX_PATIENTS][100];
int patientAges[MAX_PATIENTS];
int patientUrgency[MAX_PATIENTS];

// Specialty and admission details arrays definition
int patientSpecialtyID[MAX_PATIENTS];
int patientIsAdmitted[MAX_PATIENTS];
int patientWardID[MAX_PATIENTS];
int patientDaysAdmitted[MAX_PATIENTS];
int patientAssignedBed[MAX_PATIENTS];

// Global counters
int totalPatients = 0;
int specialtyQueueCounts[4] = {0, 0, 0, 0};