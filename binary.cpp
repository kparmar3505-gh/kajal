//BINARY SEARCH
#include<iostream>
using namespace std;

int binarySearch(int A[] , int low , int high)
{
    int key , mid;
    cout<<"enter element to be searched : ";
    cin>>key;
    while(low<=high)
    {
        mid = low + (high-low)/2;
        if(A[mid]==key)
        {
            return mid;     
        }
        if(A[mid]<key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int A[] = {5, 10, 7, 4, 1, 6, 3, 2, 9, 8};
    int result = -1 , temp;
    for(int i=0;i<=9;i++)
    {
        for(int j=i+1 ; j<=9 ; j++)
        {
            if(A[i]>A[j])
            {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    cout<<"sorted array is : ";
    for(int i=0;i<=9;i++)
    {
        cout<<A[i]<<"\t";
    }
    result = binarySearch(A , 0 , 9);
    if(result == -1)
    {
        cout<<"element not found"<<endl;
    }
    else
    {
        cout<<"element found at index : "<<result<<endl;
    }
    return 0;
}