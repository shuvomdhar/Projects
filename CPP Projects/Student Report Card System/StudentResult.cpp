#include <iostream>
#include <map>
using namespace std;

class Student
{
public:
    string name;
    int numSubjects;
    map<string, int> subjectCredits;
    map<string, int> subjectGrades;
    int totalCredits = 0;
    int totalCreditPoints = 0;

    void getInput()
    {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;
        cin.ignore();

        for (int i = 0; i < numSubjects; i++)
        {
            string subject;
            int credit, grade;

            cout << "Enter subject name: ";
            getline(cin, subject);
            cout << "Enter credit for " << subject << ": ";
            cin >> credit;
            cout << "Enter grade point for " << subject << " (0-10): ";
            cin >> grade;
            cin.ignore();

            subjectCredits[subject] = credit;
            subjectGrades[subject] = grade;
            totalCredits += credit;
            totalCreditPoints += credit * grade;
        }
    }

    void displayLetterGrades()
    {
        cout << "\nLetter Grades:\n";
        for (auto &entry : subjectGrades)
        {
            string letterGrade;
            if (entry.second == 10)
                letterGrade = "O";
            else if (entry.second == 9)
                letterGrade = "A+";
            else if (entry.second == 8)
                letterGrade = "A";
            else if (entry.second == 7)
                letterGrade = "B+";
            else if (entry.second == 6)
                letterGrade = "B";
            else if (entry.second == 5)
                letterGrade = "C";
            else if (entry.second == 4)
                letterGrade = "P";
            else
                letterGrade = "F (Fail)";
            cout << entry.first << " : " << letterGrade << "\n";
        }
    }

    void calculateSGPA()
    {
        if (totalCredits == 0)
        {
            cout << "SGPA cannot be calculated as total credits are zero.\n";
            return;
        }
        double sgpa = (double)totalCreditPoints / totalCredits;
        cout << "SGPA of " << name << " is: " << sgpa << "\n";
    }
};

class CGPA
{
public:
    void calculateCGPA()
    {
        int totalSemesters;
        cout << "Enter the number of semesters completed: ";
        cin >> totalSemesters;

        int totalSemCreditPoints = 0;
        int totalSemCredits = 0;

        for (int i = 0; i < totalSemesters; i++)
        {
            int semCredits, semCreditPoints;
            cout << "Enter total credits for semester " << (i + 1) << ": ";
            cin >> semCredits;
            cout << "Enter total credit points for semester " << (i + 1) << ": ";
            cin >> semCreditPoints;
            totalSemCredits += semCredits;
            totalSemCreditPoints += semCreditPoints;
        }

        if (totalSemCredits == 0)
        {
            cout << "CGPA cannot be calculated as total credits are zero.\n";
            return;
        }
        double cgpa = (double)totalSemCreditPoints / totalSemCredits;
        cout << "CGPA is: " << cgpa << "\n";
    }
};

int main()
{
    Student student;
    student.getInput();
    student.displayLetterGrades();
    student.calculateSGPA();

    CGPA cgpa;
    cgpa.calculateCGPA();
    return 0;
}