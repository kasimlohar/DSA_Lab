// Name : Kasim Lohar
// Roll No : B-32

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    int roll;
    string name, division, address;
};

void addStudent(const string& filename) {
    ofstream file(filename, ios::app);
    Student s;
    cout << "Enter Roll No: ";
    cin >> s.roll;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Division: ";
    getline(cin, s.division);
    cout << "Enter Address: ";
    getline(cin, s.address);
    file << s.roll << "," << s.name << "," << s.division << "," << s.address << endl;
    file.close();
    cout << "Record added.\n";
}

void searchStudent(const string& filename) {
    ifstream file(filename);
    int roll;
    cout << "Enter Roll No to search: ";
    cin >> roll;
    string line;
    bool found = false;
    while (getline(file, line)) {
        int pos = line.find(',');
        int r = stoi(line.substr(0, pos));
        if (r == roll) {
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
    string filename = "students.txt";
    int ch;
    do {
        cout << "\n1. Add\n2. Search\n3. Display All\n4. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch) {
            case 1: addStudent(filename); break;
            case 2: searchStudent(filename); break;
            case 3: displayAll(filename); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (ch != 4);
    return 0;
}
