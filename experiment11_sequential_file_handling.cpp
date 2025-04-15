// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add a new student record
void addStudent(const string& filename) {
    ofstream file(filename, ios::app); // Open file in append mode
    if (!file) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    Student student;
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    cin.ignore(); // Clear input buffer
    cout << "Enter Name: ";
    getline(cin, student.name);
    cout << "Enter Division: ";
    getline(cin, student.division);
    cout << "Enter Address: ";
    getline(cin, student.address);

    file << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;
    file.close();
    cout << "Student record added successfully." << endl;
}

// Function to delete a student record
void deleteStudent(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    vector<Student> students;
    Student student;
    string line;
    int rollToDelete;
    bool found = false;

    cout << "Enter Roll Number to delete: ";
    cin >> rollToDelete;

    // Read all records into memory
    while (getline(file, line)) {
        stringstream ss(line);
        string roll, name, division, address;
        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, division, ',');
        getline(ss, address, ',');

        student.rollNumber = stoi(roll);
        student.name = name;
        student.division = division;
        student.address = address;

        if (student.rollNumber != rollToDelete) {
            students.push_back(student);
        } else {
            found = true;
        }
    }
    file.close();

    if (!found) {
        cout << "Record not found." << endl;
        return;
    }

    // Write updated records back to the file
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& s : students) {
        outFile << s.rollNumber << "," << s.name << "," << s.division << "," << s.address << endl;
    }
    outFile.close();
    cout << "Student record deleted successfully." << endl;
}

// Function to display a specific student record
void displayStudent(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    int rollToSearch;
    cout << "Enter Roll Number to search: ";
    cin >> rollToSearch;

    Student student;
    string line;
    bool found = false;

    // Search for the record
    while (getline(file, line)) {
        stringstream ss(line);
        string roll, name, division, address;
        getline(ss, roll, ',');
        getline(ss, name, ',');
        getline(ss, division, ',');
        getline(ss, address, ',');

        student.rollNumber = stoi(roll);
        student.name = name;
        student.division = division;
        student.address = address;

        if (student.rollNumber == rollToSearch) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found) {
        cout << "Record not found." << endl;
    }
}

int main() {
    const string filename = "students.txt";
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Student Record\n";
        cout << "2. Delete Student Record\n";
        cout << "3. Display Student Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                deleteStudent(filename);
                break;
            case 3:
                displayStudent(filename);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
