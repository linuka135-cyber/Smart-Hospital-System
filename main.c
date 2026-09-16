#include <stdio.h>
#include <stdlib.h>
#include "data.h"


int main() {

    // Initialize the bed occupancy matrix to 0 - Available 
    for (int ward = 0; ward < 4; ward++) {
        for (int bed = 0; bed < 20; bed++) {
            bedOccupancy[ward][bed] = 0;
        }
    }

    printf("===========================================\n");
    printf(" Smart Hospital & Resource Allocation System\n");
    printf("===========================================\n");
    printf("System initializing...\n");

    return 0;
}
