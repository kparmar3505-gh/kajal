#include<iostream>
using namespace std;
int main()
{
    int n , key , flag = 0;
    cout<<"enter size of array : ";
    cin>>n;
    int A[n];
    cout<<"enter elements of array : ";
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    cout<<"elements of array are : ";
    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<"\t";
    }
    cout<<"enter element to be searched : ";
    cin>>key;
    for(int i=0;i<n;i++)
    {
        if(A[i]==key)
        {
            cout<<"element found at index : "<<i<<endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"element not found"<<endl;
    }
}