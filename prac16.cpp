
#include <iostream>
using namespace std;

#define MAX 5

class Deque
{
    int arr[MAX];
    int front, rear;

public:
    Deque()
    {
        front = -1;
        rear = -1;
    }

    // Insert emergency case at front
    void insertFront(int id)
    {
        if ((front == 0 && rear == MAX - 1) ||
            (front == rear + 1))
        {
            cout << "Deque is Full!\n";
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (front == 0)
        {
            front = MAX - 1;
        }
        else
        {
            front--;
        }

        arr[front] = id;

        cout << "Emergency case added at front.\n";
        display();
    }

    // Insert normal case at rear
    void insertRear(int id)
    {
        if ((front == 0 && rear == MAX - 1) ||
            (front == rear + 1))
        {
            cout << "Deque is Full!\n";
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else if (rear == MAX - 1)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }

        arr[rear] = id;

        cout << "Normal case added at rear.\n";
        display();
    }

    // Serve student from front
    void deleteFront()
    {
        if (front == -1)
        {
            cout << "Deque is Empty!\n";
            return;
        }

        cout << "Student ID " << arr[front]
             << " has been served.\n";

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        display();
    }

    // Display deque
    void display()
    {
        if (front == -1)
        {
            cout << "Deque is Empty!\n";
            return;
        }

        cout << "Current Deque: ";

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main()
{
    Deque d;
    int choice, id;

    do
    {
        cout << "\n--- Student Service Desk ---\n";
        cout << "1. Add Emergency Case (Front)\n";
        cout << "2. Add Normal Case (Rear)\n";
        cout << "3. Serve Student (Front)\n";
        cout << "4. Display Deque\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                d.insertFront(id);
                break;

            case 2:
                cout << "Enter Student ID: ";
                cin >> id;
                d.insertRear(id);
                break;

            case 3:
                d.deleteFront();
                break;

            case 4:
                d.display();
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
