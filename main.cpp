#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include "Employee.h"

void outputBinaryFile(std::string fileName, int numOfEntries)
{
    std::ifstream fin(fileName, std::ios::binary);
    Employee temp;
    for (int i = 0; i < numOfEntries; i++)
    {
        fin.read((char*)&temp, sizeof(Employee));
        std::cout << temp << '\n';
    }
}

int main()
{
    std::string binFileName;
    int numOfEntries;

    std::cout << "Enter name of the file: ";
    std::cin >> binFileName;
    std::cout << "Enter number of entries: ";
    std::cin >> numOfEntries;
    std::string commandLineRequest;
    LPSTR lpwCommandLineRequest;

    commandLineRequest = "Creator.exe";
    commandLineRequest += " " + binFileName + " " + std::to_string(numOfEntries);
    // std::wstring wCommandLineRequest = std::wstring(commandLineRequest.begin(), commandLineRequest.end());
    lpwCommandLineRequest = &commandLineRequest[0];

    STARTUPINFOA si;
    PROCESS_INFORMATION piApp;

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    CreateProcessA(NULL, lpwCommandLineRequest, NULL, NULL, FALSE,
    CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp);

    WaitForSingleObject(piApp.hProcess, INFINITE);

    CloseHandle(piApp.hProcess);

    outputBinaryFile(binFileName, numOfEntries);

    std::string txtFileName;
    int hourlySalary;

    std::cout << "Enter text report file: ";
    std::cin >> txtFileName;
    std::cout << "Enter hourly salary: ";
    std::cin >> hourlySalary;

    commandLineRequest = "Reporter.exe";
    commandLineRequest += " " + binFileName + " " + txtFileName + " " + std::to_string(hourlySalary);
    lpwCommandLineRequest = &commandLineRequest[0];

    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    CreateProcessA(NULL, lpwCommandLineRequest, NULL, NULL, FALSE,
    CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp);

    WaitForSingleObject(piApp.hProcess, INFINITE);

    CloseHandle(piApp.hProcess);

    
    
}   