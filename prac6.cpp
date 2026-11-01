
#include <iostream>
#include <string>
using namespace std;

// Structure to store student details
struct Student
{
    int rollNo;
    string name;
    string division;
};

// Function to sort students by roll number
void sortStudents(Student s[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j].rollNo > s[j + 1].rollNo)
            {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

// Linear Search by Name
void linearSearch(Student s[], int n, string searchName)
{
    int comparisons = 0;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        comparisons++;

        if (s[i].name == searchName)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << s[i].rollNo << endl;
            cout << "Name: " << s[i].name << endl;
            cout << "Division: " << s[i].division << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nStudent not found!\n";
    }

    cout << "Number of comparisons: "
         << comparisons << endl;
}

// Binary Search by Roll Number
void binarySearch(Student s[], int n, int searchRoll)
{
    int low = 0;
    int high = n - 1;
    int comparisons = 0;
    bool found = false;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        comparisons++;

        if (s[mid].rollNo == searchRoll)
        {
            cout << "\nStudent Found!\n";
            cout << "Roll Number: " << s[mid].rollNo << endl;
            cout << "Name: " << s[mid].name << endl;
            cout << "Division: " << s[mid].division << endl;

            found = true;
            break;
        }
        else if (searchRoll < s[mid].rollNo)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (!found)
    {
        cout << "\nStudent not found!\n";
    }

    cout << "Number of comparisons: "
         << comparisons << endl;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];

    // Input student details
    cout << "\nEnter student details:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "\nStudent " << i + 1 << endl;

        cout << "Enter Roll Number: ";
        cin >> s[i].rollNo;

        cout << "Enter Name: ";
        cin >> ws;
        getline(cin, s[i].name);

        cout << "Enter Division: ";
        getline(cin, s[i].division);
    }

    // Sort students by roll number
    sortStudents(s, n);

    int choice;

    do
    {
        cout << "\n===== STUDENT SEARCH SYSTEM =====\n";
        cout << "1. Linear Search by Name\n";
        cout << "2. Binary Search by Roll Number\n";
        cout << "3. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                string searchName;

                cout << "Enter student name to search: ";
                cin >> ws;
                getline(cin, searchName);

                linearSearch(s, n, searchName);
                break;
            }

            case 2:
            {
                int searchRoll;

                cout << "Enter roll number to search: ";
                cin >> searchRoll;

                binarySearch(s, n, searchRoll);
                break;
            }

            case 3:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
