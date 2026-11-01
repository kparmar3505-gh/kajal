
#include <iostream>
using namespace std;

#define MAX 100

class Student
{
public:
    int rollNo;
    string name;
    float cgpa;
};

class PriorityQueue
{
    Student q[MAX];
    int size;
    int processed;

public:
    PriorityQueue()
    {
        size = 0;
        processed = 0;
    }

    // Insert student according to CGPA priority
    void insertStudent()
    {
        if (size == MAX)
        {
            cout << "Priority Queue is Full!\n";
            return;
        }

        Student s;

        cout << "Enter Roll Number: ";
        cin >> s.rollNo;

        cout << "Enter Student Name: ";
        cin >> s.name;

        cout << "Enter CGPA: ";
        cin >> s.cgpa;

        int i = size - 1;

        // Arrange students in descending CGPA order
        while (i >= 0 && q[i].cgpa < s.cgpa)
        {
            q[i + 1] = q[i];
            i--;
        }

        q[i + 1] = s;
        size++;

        cout << "Student inserted successfully.\n";

        display();
    }

    // Delete student with highest CGPA
    void deleteStudent()
    {
        if (size == 0)
        {
            cout << "Priority Queue is Empty!\n";
            return;
        }

        cout << "Student Processed:\n";
        cout << "Roll Number: " << q[0].rollNo << endl;
        cout << "Name: " << q[0].name << endl;
        cout << "CGPA: " << q[0].cgpa << endl;

        for (int i = 0; i < size - 1; i++)
        {
            q[i] = q[i + 1];
        }

        size--;
        processed++;

        display();
    }

    // Display priority queue
    void display()
    {
        if (size == 0)
        {
            cout << "Priority Queue is Empty!\n";
            return;
        }

        cout << "\nStudents in Priority Queue:\n";

        for (int i = 0; i < size; i++)
        {
            cout << "Roll No: " << q[i].rollNo
                 << "  Name: " << q[i].name
                 << "  CGPA: " << q[i].cgpa << endl;
        }
    }

    // Count processed students
    void countProcessed()
    {
        cout << "Total Students Processed: "
             << processed << endl;
    }
};

int main()
{
    PriorityQueue pq;
    int choice;

    do
    {
        cout << "\n--- Student Priority Queue ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Process Highest CGPA Student\n";
        cout << "3. Display Queue\n";
        cout << "4. Count Processed Students\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                pq.insertStudent();
                break;

            case 2:
                pq.deleteStudent();
                break;

            case 3:
                pq.display();
                break;

            case 4:
                pq.countProcessed();
                break;

            case 5:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
