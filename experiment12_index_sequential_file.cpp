// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employee {
    int id;
    string name, designation;
    double salary;
};

void addEmployee(const string& filename) {
    ofstream file(filename, ios::app);
    Employee e;
    cout << "Enter Employee ID: ";
    cin >> e.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, e.name);
    cout << "Enter Designation: ";
    getline(cin, e.designation);
    cout << "Enter Salary: ";
    cin >> e.salary;
    file << e.id << "," << e.name << "," << e.designation << "," << e.salary << endl;
    file.close();
    cout << "Record added.\n";
}

void searchEmployee(const string& filename) {
    ifstream file(filename);
    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;
    string line;
    bool found = false;
    while (getline(file, line)) {
        int pos = line.find(',');
        int eid = stoi(line.substr(0, pos));
        if (eid == id) {
            cout << "Record: " << line << endl;
            found = true;
            break;
        }
    }
    if (!found) cout << "Record not found.\n";
    file.close();
}

void displayAll(const string& filename) {
    ifstream file(filename);
    string line;
    cout << "All Records:\n";
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

int main() {
    string filename = "employees.txt";
    int ch;
    do {
        cout << "\n1. Add\n2. Search\n3. Display All\n4. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: addEmployee(filename); break;
            case 2: searchEmployee(filename); break;
            case 3: displayAll(filename); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (ch != 4);
    return 0;
}
