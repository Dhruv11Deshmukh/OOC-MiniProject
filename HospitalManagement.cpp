#include "HospitalManagement.h"

// Function Definitions
void Patient::add_patient() {
    cout << "Enter Patient ID: ";
    cin >> id;
    cout << "Enter Patient Name: ";
    cin >> name;
    cout << "Enter Patient Age: ";
    cin >> age;
    cout << "Enter Disease: ";
    cin >> disease;
}

void Patient::show_patient() const {
    ofstream file("hospital_data.txt", ios::app);
    file << left << setw(10) << id << setw(20) << name << setw(10) << age << setw(20) << disease << "\n";
    file.close();
}

void Doctor::add_doctor() {
    cout << "Enter Doctor ID: ";
    cin >> id;
    cout << "Enter Doctor Name: ";
    cin >> name;
    cout << "Enter Specialty: ";
    cin >> specialty;
}

void Doctor::show_doctor() const {
    cout << left << setw(20) << id << setw(20) << name << setw(20) << specialty << "\n";
}

void Appointment::schedule_appointment() {
    cout << "Enter Patient ID: ";
    cin >> patient_id;
    cout << "Enter Doctor ID: ";
    cin >> doctor_id;
    cout << "Enter Appointment Date (DD/MM/YYYY): ";
    cin >> date;
}

void Appointment::show_appointment() const {
    cout << left << setw(20) << patient_id << setw(20) << doctor_id << setw(20) << date << "\n";
}

void Billing::generate_bill() {
    cout << "Enter Patient ID: ";
    cin >> patient_id;
    cout << "Enter Amount: ";
    cin >> amount;
}

void Billing::show_bill() const {
    ofstream file("hospital_data.txt", ios::app);
    file << left << setw(20) << patient_id << setw(15) << amount << "\n";
    file.close();
}

void Hospital::load_data() {
    ifstream file("hospital_data.txt");
    if (!file) return;

    int num_patients, num_doctors, num_appointments, num_bills;
    file >> num_patients >> num_doctors >> num_appointments >> num_bills;

    patients.resize(num_patients);
    for (Patient &p : patients) {
        file >> p.id >> p.name >> p.age >> p.disease;
    }

    doctors.resize(num_doctors);
    for (Doctor &d : doctors) {
        file >> d.id >> d.name >> d.specialty;
    }

    appointments.resize(num_appointments);
    for (Appointment &a : appointments) {
        file >> a.patient_id >> a.doctor_id >> a.date;
    }

    bills.resize(num_bills);
    for (Billing &b : bills) {
        file >> b.patient_id >> b.amount;
    }

    file.close();
}

void Hospital::save_data() {
    ofstream file("hospital_data.txt");

    file << patients.size() << " " << doctors.size() << " " << appointments.size() << " " << bills.size() << endl;

    for (const Patient &p : patients) {
        file << left << setw(10) << p.id << setw(20) << p.name << setw(10) << p.age << setw(20) << p.disease << endl;
    }

    for (const Doctor &d : doctors) {
        file << left << setw(20) << d.id << setw(20) << d.name << setw(20) << d.specialty << endl;
    }

    for (const Appointment &a : appointments) {
        file << left << setw(20) << a.patient_id << setw(20) << a.doctor_id << setw(20) << a.date << endl;
    }

    for (const Billing &b : bills) {
        file << left << setw(20) << b.patient_id << setw(15) << b.amount << endl;
    }

    file.close();
}

void Hospital::add_patient() {
    Patient p;
    p.add_patient();
    patients.push_back(p);
    save_data();
}

void Hospital::add_doctor() {
    Doctor d;
    d.add_doctor();
    doctors.push_back(d);
    save_data();
}

void Hospital::schedule_appointment() {
    Appointment a;
    a.schedule_appointment();
    appointments.push_back(a);
    save_data();
}

void Hospital::generate_bill() {
    Billing b;
    b.generate_bill();
    bills.push_back(b);
    save_data();
}

void Hospital::show_all_patients() const {
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Age" << setw(20) << "Disease" << endl;
    for (const Patient &p : patients) {
        p.show_patient();
    }
}

void Hospital::show_all_doctors() const {
    cout << left << setw(20) << "Doctor ID" << setw(20) << "Doctor Name" << setw(20) << "Specialty" << endl;
    for (const Doctor &d : doctors) {
        d.show_doctor();
    }
}

void Hospital::show_all_appointments() const {
    cout << left << setw(20) << "Patient ID" << setw(20) << "Doctor ID" << setw(20) << "Appointment Date" << endl;
    for (const Appointment &a : appointments) {
        a.show_appointment();
    }
}

void Hospital::show_all_bills() const {
    cout << left << setw(20) << "Patient ID" << setw(15) << "Amount" << endl;
    for (const Billing &b : bills) {
        b.show_bill();
    }
}
