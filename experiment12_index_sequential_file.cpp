// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

// Structure to represent an employee record
struct Employee {
    int id;
    string name;
    string designation;
    double salary;
};

// Function to load the index from the primary file
void loadIndex(const string& primaryFile, map<int, streampos>& index) {
    ifstream file(primaryFile);
    if (!file) {
        cerr << "Error opening primary file for reading." << endl;
        return;
    }

    index.clear();
    string line;
    streampos pos = file.tellg();

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr;
        getline(ss, idStr, ',');
        int id = stoi(idStr);
        index[id] = pos;
        pos = file.tellg();
    }

    file.close();
}

// Function to add a new employee record
void addEmployee(const string& primaryFile, map<int, streampos>& index) {
    ofstream file(primaryFile, ios::app); // Open file in append mode
    if (!file) {
        cerr << "Error opening primary file for writing." << endl;
        return;
    }

    Employee emp;
    cout << "Enter Employee ID: ";
    cin >> emp.id;
    cin.ignore(); // Clear input buffer
    cout << "Enter Name: ";
    getline(cin, emp.name);
    cout << "Enter Designation: ";
    getline(cin, emp.designation);
    cout << "Enter Salary: ";
    cin >> emp.salary;

    if (index.find(emp.id) != index.end()) {
        cout << "Error: Employee ID already exists." << endl;
        return;
    }

    streampos pos = file.tellp();
    file << emp.id << "," << emp.name << "," << emp.designation << "," << emp.salary << endl;
    file.close();

    index[emp.id] = pos; // Update the index
    cout << "Employee record added successfully." << endl;
}

// Function to delete an employee record
void deleteEmployee(const string& primaryFile, map<int, streampos>& index) {
    ifstream file(primaryFile);
    if (!file) {
        cerr << "Error opening primary file for reading." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile) {
        cerr << "Error creating temporary file." << endl;
        return;
    }

    int idToDelete;
    cout << "Enter Employee ID to delete: ";
    cin >> idToDelete;

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr;
        getline(ss, idStr, ',');
        int id = stoi(idStr);

        if (id == idToDelete) {
            found = true;
        } else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    if (found) {
        remove(primaryFile.c_str());
        rename("temp.txt", primaryFile.c_str());
        index.erase(idToDelete); // Update the index
        cout << "Employee record deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Record not found." << endl;
    }
}

// Function to search and display an employee record by ID
void searchEmployee(const string& primaryFile, const map<int, streampos>& index) {
    int idToSearch;
    cout << "Enter Employee ID to search: ";
    cin >> idToSearch;

    auto it = index.find(idToSearch);
    if (it == index.end()) {
        cout << "Record not found." << endl;
        return;
    }

    ifstream file(primaryFile);
    if (!file) {
        cerr << "Error opening primary file for reading." << endl;
        return;
    }

    file.seekg(it->second);
    string line;
    getline(file, line);

    stringstream ss(line);
    string idStr, name, designation, salaryStr;
    getline(ss, idStr, ',');
    getline(ss, name, ',');
    getline(ss, designation, ',');
    getline(ss, salaryStr, ',');

    cout << "Employee ID: " << idStr << endl;
    cout << "Name: " << name << endl;
    cout << "Designation: " << designation << endl;
    cout << "Salary: " << salaryStr << endl;

    file.close();
}

int main() {
    const string primaryFile = "employees.txt";
    map<int, streampos> index;

    // Load the index from the primary file
    loadIndex(primaryFile, index);

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Employee Record\n";
        cout << "2. Delete Employee Record\n";
        cout << "3. Search Employee Record\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(primaryFile, index);
                break;
            case 2:
                deleteEmployee(primaryFile, index);
                break;
            case 3:
                searchEmployee(primaryFile, index);
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
