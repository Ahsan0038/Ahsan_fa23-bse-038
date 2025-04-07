#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Structure to represent a patient
struct Patient {
    string name;
    string condition;
    int emergencyLevel; // Lower = higher priority
    int arrivalOrder;   // To maintain order among same-priority patients

    Patient(string n, string c, int e, int a)
        : name(n), condition(c), emergencyLevel(e), arrivalOrder(a) {}
};

// Custom comparator for priority queue
struct ComparePriority {
    bool operator()(const Patient& p1, const Patient& p2) {
        if (p1.emergencyLevel == p2.emergencyLevel)
            return p1.arrivalOrder > p2.arrivalOrder; // Earlier arrival = higher priority
        return p1.emergencyLevel > p2.emergencyLevel; // Lower emergency level = higher priority
    }
};

// Function to print the current queue
void printQueue(priority_queue<Patient, vector<Patient>, ComparePriority> pq) {
    cout << "\n--- Current Treatment Order ---\n";
    cout << left << setw(15) << "Name"
         << setw(25) << "Condition"
         << "Priority\n";
    cout << "----------------------------------------------\n";
    while (!pq.empty()) {
        Patient p = pq.top();
        cout << left << setw(15) << p.name
             << setw(25) << p.condition
             << p.emergencyLevel << "\n";
        pq.pop();
    }
    cout << "----------------------------------------------\n";
}

int main() {
    priority_queue<Patient, vector<Patient>, ComparePriority> patientQueue;

    // Patient data (arrival order matters)
    vector<Patient> patients = {
        {"Patient A", "Fever", 3, 1},
        {"Patient B", "Heart Attack", 1, 2},
        {"Patient C", "Broken Leg", 2, 3},
        {"Patient D", "Mild Cold", 4, 4},
        {"Patient E", "Severe Burn", 2, 5},
        {"Patient F", "Small Cut", 4, 6},
        {"Patient G", "Stroke", 1, 7},
        {"Patient H", "Food Poisoning", 3, 8},
        {"Patient I", "Fractured Arm", 2, 9},
        {"Patient J", "Migraine", 3, 10}
    };

    for (const auto& patient : patients) {
        cout << "\nAdding " << patient.name << " (" << patient.condition
             << ", Priority: " << patient.emergencyLevel << ") to the queue.\n";
        patientQueue.push(patient);
        printQueue(patientQueue);
    }

    return 0;
}
