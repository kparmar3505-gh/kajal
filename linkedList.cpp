#include<iostream>  
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
class linkedList
{
    public:
    Node *head;

    linkedList()
    { 
        head = NULL;    
    }
    void add(int value)
    {
        Node *n1 = new Node(value);
        if(head == NULL)
        {
            head = n1;
        }
        else
        {
            Node *temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n1;
        }
    }
    void display()
    {
        Node *temp = head;
        if(head= NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        while(temp != NULL)
        {
            cout<<temp->data<<"\t->\t";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }
};

int main()
{
    linkedList l1;
    l1.add(5);
    l1.add(10);
    l1.add(15);
    l1.display();
    return 0;
}