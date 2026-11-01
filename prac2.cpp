#include<iostream>
using namespace std;

struct Node
{
    char attendance;
    Node *next;
};

Node *head = NULL;
  
void insertAttendance(char status)
{
    Node *newNode = new Node;
    newNode->attendance = status;
    newNode->next = NULL;
 
    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout<<"attendance recorded successfully.\n";
}

void updateAttendance(int day,char status)
{
    Node *temp = head;
    int count = 1;
    while(temp->next != NULL && count<day)
    {
        temp = temp->next;
        count++;
    }
    if(count == day)
    {
        temp->attendance = status;
        cout<<"attendance updated successfully.\n";
    }
    else
    {
        cout<<"invalid day.\n";
    }
}

void countAttendance()
{
    Node *temp = head;
    int present = 0, absent =0;
    while(temp->next != NULL)
    {
        if(temp->attendance == 'p' || temp->attendance == 'P')
        {
            present++;
        }
        else
        {
            absent++;
        }
        temp = temp->next;
    }
    cout<<"present days:"<<present<<endl;
    cout<<"absent days:"<<absent<<endl;
}

void displayAttendance()
{
    Node *temp = head;
    int day = 1;
    if(head == NULL)
    {
        cout<<"attendance record is empty.\n";
        return;
    }
    cout<<"attendance record:\n";
    while(temp->next != NULL)
    {
        cout<<"day"<<day<<":"<<temp->attendance<<endl;
        temp = temp->next;
        day++;
    }
}

int main()
{
    int choice , day;
    char status;

    do
    {
        cout<<"-----attendance managemanet-----\n";
        cout<<"1.insert attendance.\n";
        cout<<"2.update attendance.\n";
        cout<<"3.count attendance.\n";
        cout<<"4.display attendance.\n";
        cout<<"5.exit.\n";

        cout<<"enter your choice:";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                cout<<"enter attendance status(P/A):";
                cin>>status;
                insertAttendance(status);
                break;
            }

            case 2:
            {
                cout<<"enter day to be upated:";
                cin>>day;
                cout<<"enter nre attendance status(P/A):";
                cin>>status;
                updateAttendance(day,status);
                break;
            }

            case 3:
            {
                countAttendance();
                break;
            }

            case 4:
            {
                displayAttendance();
                break;
            }

            case 5:
            {
                cout<<"program ended!\n";
                break;
            }

            default:
            {
                cout<<"invalid choice!\n";
                break;
            }

        }

    }while(choice != 5);
    return 0;
}