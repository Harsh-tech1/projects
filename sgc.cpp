#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
void getStudentDetails(string &name, int &rollNo);
void inputMarks(float marks[], int size);
float calculateTotal(float marks[], int size);
float calculatePercentage(float total, int size);
char calculateGrade(float percentage);
bool isPass(float marks[], int size);
float highestMark(float marks[], int size);
float lowestMark(float marks[], int size);
void displayResult(string name, int rollNo, float marks[], int size);

int main()
{
    char choice;

    do
    {
        string name;
        int rollNo;
        float marks[5];

        cout << "\n=============================================\n";
        cout << "      STUDENT GRADE MANAGEMENT SYSTEM\n";
        cout << "=============================================\n\n";

        getStudentDetails(name, rollNo);
        inputMarks(marks, 5);

        displayResult(name, rollNo, marks, 5);

        cout << "\nDo you want to calculate another student's result? (Y/N): ";
        cin >> choice;

    } while(choice == 'Y' || choice == 'y');

    cout << "\nThank you for using the Student Grade Management System!\n";

    return 0;
}

// Get student details
void getStudentDetails(string &name, int &rollNo)
{
    cin.ignore();

    cout << "Enter Student Name : ";
    getline(cin, name);

    cout << "Enter Roll Number  : ";
    cin >> rollNo;
}

// Input Marks
void inputMarks(float marks[], int size)
{
    cout << "\nEnter Marks (0 - 100)\n";

    for(int i = 0; i < size; i++)
    {
        do
        {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];

            if(marks[i] < 0 || marks[i] > 100)
                cout << "Invalid Marks! Please enter between 0 and 100.\n";

        } while(marks[i] < 0 || marks[i] > 100);
    }
}

// Calculate Total
float calculateTotal(float marks[], int size)
{
    float total = 0;

    for(int i = 0; i < size; i++)
        total += marks[i];

    return total;
}

// Calculate Percentage
float calculatePercentage(float total, int size)
{
    return total / size;
}

// Calculate Grade
char calculateGrade(float percentage)
{
    if(percentage >= 90)
        return 'A';
    else if(percentage >= 80)
        return 'B';
    else if(percentage >= 70)
        return 'C';
    else if(percentage >= 60)
        return 'D';
    else
        return 'F';
}

// Pass or Fail
bool isPass(float marks[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(marks[i] < 33)
            return false;
    }

    return true;
}

// Highest Mark
float highestMark(float marks[], int size)
{
    float highest = marks[0];

    for(int i = 1; i < size; i++)
    {
        if(marks[i] > highest)
            highest = marks[i];
    }

    return highest;
}

// Lowest Mark
float lowestMark(float marks[], int size)
{
    float lowest = marks[0];

    for(int i = 1; i < size; i++)
    {
        if(marks[i] < lowest)
            lowest = marks[i];
    }

    return lowest;
}

// Display Result
void displayResult(string name, int rollNo, float marks[], int size)
{
    float total = calculateTotal(marks, size);
    float percentage = calculatePercentage(total, size);
    char grade = calculateGrade(percentage);

    cout << "\n=============================================\n";
    cout << "              RESULT SUMMARY\n";
    cout << "=============================================\n";

    cout << "Student Name : " << name << endl;
    cout << "Roll Number  : " << rollNo << endl;

    cout << "\nSubject-wise Marks\n";
    cout << "-----------------------------\n";

    for(int i = 0; i < size; i++)
    {
        cout << "Subject " << i + 1 << " : " << marks[i] << endl;
    }

    cout << "-----------------------------\n";
    cout << fixed << setprecision(2);

    cout << "Total Marks : " << total << " / 500\n";
    cout << "Percentage  : " << percentage << "%\n";
    cout << "Grade       : " << grade << endl;
    cout << "Highest     : " << highestMark(marks, size) << endl;
    cout << "Lowest      : " << lowestMark(marks, size) << endl;
    cout << "Status      : ";

    if(isPass(marks, size))
        cout << "PASS";
    else
        cout << "FAIL";

    cout << "\n=============================================\n";
}