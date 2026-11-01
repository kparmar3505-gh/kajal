
#include <iostream>
#include <string>
using namespace std;

// Structure of a node
struct Node
{
    int rollNo;
    string name;
    Node* prev;
    Node* next;
};

// Head and tail pointers
Node* head = NULL;
Node* tail = NULL;

// Function to insert student in sorted order
void insertStudent(int roll, string studentName)
{
    Node* newNode = new Node();

    newNode->rollNo = roll;
    newNode->name = studentName;
    newNode->prev = NULL;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    Node* temp = head;

    // Find correct position
    while (temp != NULL && temp->rollNo < roll)
    {
        temp = temp->next;
    }

    // Check duplicate roll number
    if (temp != NULL && temp->rollNo == roll)
    {
        cout << "Roll number already exists!\n";
        delete newNode;
        return;
    }

    // Insert at beginning
    if (temp == head)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    else if (temp == NULL)
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // Insert in middle
    else
    {
        newNode->next = temp;
        newNode->prev = temp->prev;

        temp->prev->next = newNode;
        temp->prev = newNode;
    }

    cout << "Student inserted successfully!\n";
}

// Function to delete student by roll number
void deleteStudent(int roll)
{
    Node* temp = head;

    while (temp != NULL && temp->rollNo != roll)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Student not found!\n";
        return;
    }

    if (temp == head)
        head = temp->next;

    if (temp == tail)
        tail = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;

    cout << "Student deleted successfully!\n";
}

// Display students in forward direction
void displayForward()
{
    Node* temp = head;

    if (head == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    cout << "\nStudents in Forward Order:\n";

    while (temp != NULL)
    {
        cout << "Roll No: " << temp->rollNo
             << "  Name: " << temp->name << endl;

        temp = temp->next;
    }
}

// Display students in backward direction
void displayBackward()
{
    Node* temp = tail;

    if (tail == NULL)
    {
        cout << "List is empty!\n";
        return;
    }

    cout << "\nStudents in Reverse Order:\n";

    while (temp != NULL)
    {
        cout << "Roll No: " << temp->rollNo
             << "  Name: " << temp->name << endl;

        temp = temp->prev;
    }
}

// Main function
int main()
{
    int choice, roll;
    string name;

    do
    {
        cout << "\n===== STUDENT RECORD SYSTEM =====\n";
        cout << "1. Insert Student\n";
        cout << "2. Delete Student\n";
        cout << "3. Display Forward\n";
        cout << "4. Display Backward\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> roll;

                cout << "Enter Student Name: ";
                cin >> ws;
                getline(cin, name);

                insertStudent(roll, name);
                break;

            case 2:
                cout << "Enter Roll Number to delete: ";
                cin >> roll;

                deleteStudent(roll);
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    // Free remaining nodes
    while (head != NULL)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
