
#include <iostream>
using namespace std;

// Structure for linked list node
struct Node
{
    int marks;
    Node* next;
};

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    // Creating an array
    int* arr = new int[n];

    // Creating linked list
    Node* head = NULL;
    Node* tail = NULL;

    // Inserting marks in both structures
    cout << "\nEnter IA marks of students:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> arr[i];

        // Create new node
        Node* newNode = new Node();

        newNode->marks = arr[i];
        newNode->next = NULL;

        // Insert node into linked list
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Display array representation
    cout << "\n--- ARRAY REPRESENTATION ---\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Index: " << i
             << "  Marks: " << arr[i]
             << "  Address: " << &arr[i] << endl;
    }

    // Display linked list representation
    cout << "\n--- LINKED LIST REPRESENTATION ---\n";

    Node* temp = head;

    while (temp != NULL)
    {
        cout << "Marks: " << temp->marks
             << "  Node Address: " << temp
             << "  Next Address: " << temp->next << endl;

        temp = temp->next;
    }

    // Count students scoring more than 80
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 80)
        {
            count++;
        }
    }

    cout << "\nNumber of students scoring above 80: "
         << count << endl;

    // Free allocated memory
    delete[] arr;

    temp = head;

    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}
