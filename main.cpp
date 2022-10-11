#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

struct Employee
{
    int num;
    char name[10];
    double hours;
};

istream& operator>>(istream& fin, Employee& emp)
{
    return fin >> emp.num >> emp.name >> emp.hours;
}

void Creator(const char *fileName, int numOfEmployees)
{
    ofstream fout(fileName, ios::binary);
    Employee temp;
    for (int i = 0; i < numOfEmployees; i++)
    {
        cin >> temp;
        fout.write((char*)&temp, sizeof(Employee));
    }
    
}

int main()
{
    Creator("input.bin", 2);
    ifstream fin("input.bin", ios::binary);
    Employee temp;
    fin.read((char*)&temp, sizeof(Employee));
    cout << temp.num << temp.name << temp.hours;
}