#include<iostream>
using namespace std;

struct Student
{
    int rollno;
    string name;
    float cgpa;
};

int main()
{
    Student s[100];
    int n=0 , choice;

    do
    {
        cout<<"-----Student Informatio System-----\n";
        cout<<"1.Insert Student.\n";
        cout<<"2.delete student.\n";
        cout<<"3.search student.\n";
        cout<<"4.display student.\n";
        cout<<"5.exit.\n";

        cout<<"enter your choice:";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                int pos;
                cout<<"enter position(1 to "<<n+1<<"):";
                cin>>pos;
                
                if(pos<1 || pos>n+1)
                {
                    cout<<"invalid position.\n";
                }

                for(int i=n ; i>=pos ; i--)
                {
                    s[i] = s[i-1];
                }

                    cout<<"enter roll number:";
                    cin>>s[pos-1].rollno;
                    cout<<"enter name:";
                    cin>>s[pos-1].name;
                    cout<<"enter cgpa:";
                    cin>>s[pos-1].cgpa;
                    n++;
                    cout<<"student inserted successfully.\n";
                    break;
            }

            case 2:
            {
                int roll , index=-1;
                cout<<"enter roll no to be deleted:";
                cin>>roll;

                for(int i=0 ; i<n ; i++)
                {
                    if(s[i].rollno == roll)
                    {
                        index=i;
                        break;
                    }
                }

                if(index == -1)
                {
                    cout<<"student not found.\n";
                }
                else
                {
                    for(int i=index ; i< n-1 ; i++)
                    {
                        s[i] = s[i+1];
                    }
                    n--;
                    cout<<"student deleted successfully.\n";
                }
                break;
            }
        
            case 3:
            {
                int roll;
                bool found=false;

                cout<<"enter roll no to be searched:";
                cin>>roll;

                for(int i=0 ; i<n ; i++)
                {
                    if(s[i].rollno == roll)
                    {
                        cout<<"roll no:"<<s[i].rollno;
                        cout<<"name:"<<s[i].name;
                        cout<<"cgpa:"<<s[i].cgpa<<endl;
                        found=true;
                        break;
                    }
                }

                if(found == false)
                {
                    cout<<"student not found.\n";
                }
                break;
            }

            case 4:
            {
                if(n==0)
                {
                    cout<<"student record is empty.\n";
                }
                else
                {
                    for(int i=0 ; i<n ; i++)
                    {
                        cout<<"student roll no:"<<s[i].rollno;
                        cout<<"name:"<<s[i].name;
                        cout<<"cgpa:"<<s[i].cgpa<<endl;
                    }
                }
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
    }while(choice!=5);
    return 0;

}