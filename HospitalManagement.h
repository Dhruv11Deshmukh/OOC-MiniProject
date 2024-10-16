#ifndef HOSPITAL_MANAGEMENT_H
#define HOSPITAL_MANAGEMENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class Patient {
public:
    int id;
    string name;
    int age;
    string disease;

    void add_patient();
    void show_patient() const;
};

class Doctor {
public:
    int id;
    string name;
    string specialty;

    void add_doctor();
    void show_doctor() const;
};

class Appointment {
public:
    int patient_id;
    int doctor_id;
    string date;

    void schedule_appointment();
    void show_appointment() const;
};

class Billing {
public:
    int patient_id;
    float amount;

    void generate_bill();
    void show_bill() const;
};

class Hospital {
public:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    vector<Billing> bills;

    void load_data();
    void save_data();
    void add_patient();
    void add_doctor();
    void schedule_appointment();
    void generate_bill();
    void show_all_patients() const;
    void show_all_doctors() const;
    void show_all_appointments() const;
    void show_all_bills() const;
};

#endif
