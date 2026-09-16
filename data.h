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

#endif