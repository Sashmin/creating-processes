#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <fstream>

struct Employee
{
    int num;
    char name[10];
    double hours;
};

std::istream& operator>>(std::istream& fin, Employee& emp)
{
    return fin >> emp.num >> emp.name >> emp.hours;
}

std::ostream& operator<<(std::ostream& fout, const Employee& emp)
{
    return fout << emp.num << " " << emp.name << " " << emp.hours;
}

#endif