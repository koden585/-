/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Equipment {
public:
    string name;
    int quantity;
};

class Employee {
public:
    string name;
    vector<Equipment> equipmentList;
};

class Program {
public:
    vector<Employee> employeeList;

    void addEquipment(string employeeName, string equipmentName, int quantity) {
        for (int i = 0; i < employeeList.size(); i++) {
            if (employeeList[i].name == employeeName) {
                for (int j = 0; j < employeeList[i].equipmentList.size(); j++) {
                    if (employeeList[i].equipmentList[j].name == equipmentName) {
                        employeeList[i].equipmentList[j].quantity += quantity;
                        return;
                    }
                }
                Equipment newEquipment;
                newEquipment.name = equipmentName;
                newEquipment.quantity = quantity;
                employeeList[i].equipmentList.push_back(newEquipment);
                return;
            }
        }
        Employee newEmployee;
        newEmployee.name = employeeName;
        Equipment newEquipment;
        newEquipment.name = equipmentName;
        newEquipment.quantity = quantity;
        newEmployee.equipmentList.push_back(newEquipment);
        employeeList.push_back(newEmployee);
    }

    void removeEquipment(string employeeName, string equipmentName, int quantity) {
        for (int i = 0; i < employeeList.size(); i++) {
            if (employeeList[i].name == employeeName) {
                for (int j = 0; j < employeeList[i].equipmentList.size(); j++) {
                    if (employeeList[i].equipmentList[j].name == equipmentName) {
                        if (employeeList[i].equipmentList[j].quantity >= quantity) {
                            employeeList[i].equipmentList[j].quantity -= quantity;
                            if (employeeList[i].equipmentList[j].quantity == 0) {
                                employeeList[i].equipmentList.erase(employeeList[i].equipmentList.begin() + j);
                            }
                            return;
                        }
                        else {
                            cout << "Not enough " << equipmentName << " for " << employeeName << endl;
                            return;
                        }
                    }
                }
                cout << employeeName << " does not have " << equipmentName << endl;
                return;
            }
        }
        cout << "Employee " << employeeName << " not found" << endl;
    }

    void filterByEmployee(string employeeName) {
        for (int i = 0; i < employeeList.size(); i++) {
            if (employeeList[i].name == employeeName) {
                cout << employeeName << " has the following equipment: " << endl;
                for (int j = 0; j < employeeList[i].equipmentList.size(); j++) {
                    cout << employeeList[i].equipmentList[j].name << ": " << employeeList[i].equipmentList[j].quantity << endl;
                }
                return;
            }
        }
        cout << "Employee " << employeeName << " not found" << endl;
    }

    void checkLadderAndDrill() {
        bool hasLadder = false;
        bool hasDrill = false;
        for (int i = 0; i < employeeList.size(); i++) {
            for (int j = 0; j < employeeList[i].equipmentList.size(); j++) {
                if (employeeList[i].equipmentList[j].name == "Ladder") {
                    hasLadder = true;
                }
                if (employeeList[i].equipmentList[j].name == "Drill") {
                    hasDrill = true;
                }
            }
        }
        if (hasLadder && hasDrill) {
            cout << "At least one employee has both a ladder and a drill" << endl;
        }
        else {
            cout << "No employee has both a ladder and a drill" << endl;
        }
    }
};

int main() {
    Program program;
    int choice = 0;
    while (choice != 5) {
        cout << "1. Add equipment" << endl;
        cout << "2. Remove equipment" << endl;
        cout << "3. Filter by employee" << endl;
        cout << "4. Check ladder and drill" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            string employeeName,equipmentName;
            int quantity;
            cout << "Enter employee name: ";
            cin >> employeeName;
            cout << "Enter equipment name: ";
            cin >> equipmentName;
            cout << "Enter quantity: ";
            cin >> quantity;
            program.addEquipment(employeeName, equipmentName, quantity);
            break;
        case 2:
            cout << "Enter employee name: ";
            cin >> employeeName;
            cout << "Enter equipment name: ";
            cin >> equipmentName;
            cout << "Enter quantity: ";
            cin >> quantity;
            program.removeEquipment(employeeName, equipmentName, quantity);
            break;
        case 3: 
            cout << "Enter employee name: ";
            cin >> employeeName;
            program.filterByEmployee(employeeName);
            break;
        case 4:
            program.checkLadderAndDrill();
            break;
        case 5:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    }
    return 0;
}