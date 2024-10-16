#include "HospitalManagement.h"
#include "Display.h"

void admin_functions(Hospital& hospital) {
    int admin_choice;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Patient\n2. Add Doctor\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> admin_choice;

        switch (admin_choice) {
            case 1:
                hospital.add_patient();
                break;
            case 2:
                hospital.add_doctor();
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (admin_choice != 3);
}

void doctor_functions(Hospital& hospital) {
    int doctor_choice;
    do {
        cout << "\nDoctor Menu:\n";
        cout << "1. Show All Appointments\n2. Generate Bill\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> doctor_choice;

        switch (doctor_choice) {
            case 1:
                display_all_appointments(hospital);
                break;
            case 2:
                hospital.generate_bill();
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (doctor_choice != 3);
}

void receptionist_functions(Hospital& hospital) {
    int receptionist_choice;
    do {
        cout << "\nReceptionist Menu:\n";
        cout << "1. Schedule Appointment\n2. Show All Patients\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> receptionist_choice;

        switch (receptionist_choice) {
            case 1:
                hospital.schedule_appointment();
                break;
            case 2:
                display_all_patients(hospital);
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (receptionist_choice != 3);
}

void patient_functions(Hospital& hospital) {
    int patient_choice;
    do {
        cout << "\nPatient Menu:\n";
        cout << "1. View Bills\n2. Exit\n";
        cout << "Enter your choice: ";
        cin >> patient_choice;

        switch (patient_choice) {
            case 1:
                display_all_bills(hospital);
                break;
            case 2:
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (patient_choice != 2);
}

int main() {
    Hospital hospital;
    hospital.load_data();
    string role;

    cout << "Enter your role (admin/doctor/receptionist/patient): ";
    cin >> role;

    if (role == "admin") {
        admin_functions(hospital);
    } else if (role == "doctor") {
        doctor_functions(hospital);
    } else if (role == "receptionist") {
        receptionist_functions(hospital);
    } else if (role == "patient") {
        patient_functions(hospital);
    } else {
        cout << "Invalid role!\n";
    }

    return 0;
}
