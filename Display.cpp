#include <iostream>
#include "Display.h"

using namespace std;

void display_all_patients(const Hospital& hospital) {
    cout << "Displaying all patients:\n";
    hospital.show_all_patients();  
}

void display_all_doctors(const Hospital& hospital) {
    cout << "Displaying all doctors:\n";
    hospital.show_all_doctors();  
}

void display_all_appointments(const Hospital& hospital) {
    cout << "Displaying all appointments:\n";
    hospital.show_all_appointments(); 
}

void display_all_bills(const Hospital& hospital) {
    cout << "Displaying all bills:\n";
    hospital.show_all_bills();      
}
