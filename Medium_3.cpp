#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    static int count;
public:
    Employee(string n) : name(n) {
        count++;
    }
    virtual double salary() = 0; // Pure virtual function
    static int getCount() {
        return count;
    }
};

int Employee::count = 0;

class Manager : public Employee {
private:
    double baseSalary;
public:
    Manager(string n, double base) : Employee(n), baseSalary(base) {}
    double salary() override {
        return baseSalary * 1.5;
    }
};

class Worker : public Employee {
private:
    double hourlyWage;
    int hoursWorked;
public:
    Worker(string n, double wage, int hours) : Employee(n), hourlyWage(wage), hoursWorked(hours) {}
    double salary() override {
        return hourlyWage * hoursWorked;
    }
};

int main() {
    Employee* employees[2];
    employees[0] = new Manager("Alice", 5000);
    employees[1] = new Worker("Bob", 20, 160);

    for (int i = 0; i < 2; ++i) {
        cout << "Salary: " << employees[i]->salary() << endl;
    }

    for (int i = 0; i < 2; ++i) {
        delete employees[i];
    }

    cout << "Total number of employees: " << Employee::getCount() << endl;

    return 0;
}
