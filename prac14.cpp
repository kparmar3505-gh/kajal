
#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
    int queue[MAX];
    int front, rear;

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    // Insert student ID
    void enqueue(int id)
    {
        if ((rear + 1) % MAX == front)
        {
            cout << "Circular Queue is Full!\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX;
        }

        queue[rear] = id;

        cout << "Student ID " << id
             << " added successfully.\n";
    }

    // Delete student ID
    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Circular Queue is Empty!\n";
            return;
        }

        cout << "Bus pass issued to Student ID: "
             << queue[front] << endl;

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    // Check whether queue is full
    void isFull()
    {
        if ((rear + 1) % MAX == front)
            cout << "Queue is Full.\n";
        else
            cout << "Queue is Not Full.\n";
    }

    // Check whether queue is empty
    void isEmpty()
    {
        if (front == -1 || front > rear)
            cout << "Queue is Empty.\n";
        else
            cout << "Queue is Not Empty.\n";
    }

    // Display circular queue
    void display()
    {
        if (front == -1 || front > rear)
        {
            cout << "Circular Queue is Empty!\n";
            return;
        }

        cout << "Student IDs in Queue: ";

        int i = front;

        while (true)
        {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice, id;

    do
    {
        cout << "\n--- Bus Pass Distribution ---\n";
        cout << "1. Insert Student ID\n";
        cout << "2. Issue Bus Pass (Delete)\n";
        cout << "3. Check Queue Full\n";
        cout << "4. Check Queue Empty\n";
        cout << "5. Display Queue\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                q.enqueue(id);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.isFull();
                break;

            case 4:
                q.isEmpty();
                break;

            case 5:
                q.display();
                break;

            case 6:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}
