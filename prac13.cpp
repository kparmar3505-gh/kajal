
#include <iostream>
using namespace std;

#define MAX 100

class AdmissionQueue
{
    int queue[MAX];
    int front, rear;

public:
    AdmissionQueue()
    {
        front = -1;
        rear = -1;
    }

    // Add student token number
    void enqueue(int token)
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is Full!\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = token;

        cout << "Student " << token << " added to queue.\n";
    }

    // Remove student from queue
    void dequeue()
    {
        if (front == -1)
        {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Student " << queue[front]
             << " is processed.\n";

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    // Display front and rear token numbers
    void displayFrontRear()
    {
        if (front == -1)
        {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Front Token: " << queue[front] << endl;
        cout << "Rear Token: " << queue[rear] << endl;
    }

    // Display complete queue
    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty!\n";
            return;
        }

        cout << "Admission Queue: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    AdmissionQueue q;
    int choice, token;

    do
    {
        cout << "\n--- Student Admission Queue ---\n";
        cout << "1. Enqueue Student\n";
        cout << "2. Dequeue Student\n";
        cout << "3. Display Front and Rear\n";
        cout << "4. Display Complete Queue\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Student Token Number: ";
                cin >> token;
                q.enqueue(token);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.displayFrontRear();
                break;

            case 4:
                q.display();
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
