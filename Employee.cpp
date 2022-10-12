#include <iostream>
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