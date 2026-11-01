
#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    float cgpa;
};

// Selection Sort in descending order
void selectionSort(Student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (s[j].cgpa > s[maxIndex].cgpa)
            {
                maxIndex = j;
            }
        }

        Student temp = s[i];
        s[i] = s[maxIndex];
        s[maxIndex] = temp;
    }

    cout << "\nMerit List using Selection Sort:\n";
    cout << "Roll No\tName\tCGPA\n";

    for (int i = 0; i < n; i++)
    {
        cout << s[i].rollNo << "\t"
             << s[i].name << "\t"
             << s[i].cgpa << endl;
    }
}

// Insertion Sort in descending order
void insertionSort(Student s[], int n)
{
    int shifts = 0;

    for (int i = 1; i < n; i++)
    {
        Student key = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].cgpa < key.cgpa)
        {
            s[j + 1] = s[j];
            j--;
            shifts++;
        }

        s[j + 1] = key;
    }

    cout << "\nMerit List using Insertion Sort:\n";
    cout << "Roll No\tName\tCGPA\n";

    for (int i = 0; i < n; i++)
    {
        cout << s[i].rollNo << "\t"
             << s[i].name << "\t"
             << s[i].cgpa << endl;
    }

    cout << "\nTotal number of shifts: " << shifts << endl;
}

// Display top 5 students
void displayTop5(Student s[], int n)
{
    cout << "\n----- TOP 5 STUDENTS -----\n";
    cout << "Roll No\tName\tCGPA\n";

    int limit = (n < 5) ? n : 5;

    for (int i = 0; i < limit; i++)
    {
        cout << s[i].rollNo << "\t"
             << s[i].name << "\t"
             << s[i].cgpa << endl;
    }
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];

    cout << "\nEnter student details:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Enter Roll Number: ";
        cin >> s[i].rollNo;

        cout << "Enter Name: ";
        cin >> ws;
        getline(cin, s[i].name);

        cout << "Enter CGPA: ";
        cin >> s[i].cgpa;
    }

    // Selection Sort
    selectionSort(s, n);

    // Insertion Sort
    insertionSort(s, n);

    // Display Top 5
    displayTop5(s, n);

    return 0;
}
