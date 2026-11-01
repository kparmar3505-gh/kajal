
#include <iostream>
using namespace std;

// Function to partition the array
int partition(float arr[], int low, int high)
{
    float pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Recursive Quick Sort function
void quickSort(float arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);

        quickSort(arr, pi + 1, high);
    }
}

// Function to display the array
void display(float arr[], int n)
{
    cout << "\nSorted Student Percentages:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "%  ";
    }

    cout << endl;
}

// Main function
int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    float arr[100];

    cout << "\nEnter student percentages:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "\nOriginal Percentages:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "%  ";
    }

    // Apply Quick Sort
    quickSort(arr, 0, n - 1);

    // Display sorted percentages
    display(arr, n);

    return 0;
}
