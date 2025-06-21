#include <iostream>
#include <vector>
#include <cstdlib>  // For system, exit

using namespace std;

// Function declarations
void calculateGPA();
void calculateCGPA();
void showMethod();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    system("cls"); // Clear console (Windows only)
    int choice;
    cout << "-------------------------------------------------------------\n";
    cout << "                  GPA & CGPA Calculator (By Sahil Shah)\n";
    cout << "-------------------------------------------------------------\n";
    cout << "1. Calculate GPA (Grade Point Average)\n";
    cout << "2. Calculate CGPA (Cumulative Grade Point Average)\n";
    cout << "3. View Method Used\n";
    cout << "4. Exit\n";
    cout << "-------------------------------------------------------------\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            calculateGPA();
            break;
        case 2:
            calculateCGPA();
            break;
        case 3:
            showMethod();
            break;
        case 4:
            exit(EXIT_SUCCESS);
        default:
            cout << "\nInvalid input. Try again.\n";
            system("pause");
            menu();
    }
}

void calculateGPA() {
    system("cls");
    int n;
    cout << "--- GPA Calculation ---\n";
    cout << "Enter number of subjects: ";
    cin >> n;

    vector<float> credits(n);
    vector<float> points(n);
    float totalPoints = 0, totalCredits = 0;

    for (int i = 0; i < n; ++i) {
        cout << "\nSubject " << i + 1 << ":\n";
        cout << "Credit: ";
        cin >> credits[i];
        cout << "Grade Point: ";
        cin >> points[i];

        totalPoints += credits[i] * points[i];
        totalCredits += credits[i];
    }

    float gpa = totalPoints / totalCredits;
    cout << "\nTotal GPA: " << gpa << "\n";

    cout << "\n1. Calculate Again\n2. Main Menu\n3. Exit\nChoose option: ";
    int option;
    cin >> option;

    if (option == 1) calculateGPA();
    else if (option == 2) menu();
    else exit(EXIT_SUCCESS);
}

void calculateCGPA() {
    system("cls");
    int sem;
    cout << "--- CGPA Calculation ---\n";
    cout << "Enter number of semesters: ";
    cin >> sem;

    vector<float> gpas(sem);
    float totalGPA = 0;

    for (int i = 0; i < sem; ++i) {
        cout << "Enter GPA for Semester " << i + 1 << ": ";
        cin >> gpas[i];
        totalGPA += gpas[i];
    }

    float cgpa = totalGPA / sem;
    cout << "\nTotal CGPA: " << cgpa << "\n";

    cout << "\n1. Calculate Again\n2. Main Menu\n3. Exit\nChoose option: ";
    int option;
    cin >> option;

    if (option == 1) calculateCGPA();
    else if (option == 2) menu();
    else exit(EXIT_SUCCESS);
}

void showMethod() {
    system("cls");
    cout << "--- Method for Calculating GPA & CGPA ---\n";
    cout << "GPA  = (Sum of Credit × Grade Point) / Total Credits\n";
    cout << "CGPA = (Sum of All Semester GPAs) / Number of Semesters\n";

    cout << "\n1. Main Menu\n2. Exit\nChoose option: ";
    int option;
    cin >> option;

    if (option == 1) menu();
    else exit(EXIT_SUCCESS);
}
