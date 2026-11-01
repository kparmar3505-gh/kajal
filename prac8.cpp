
#include <iostream>
using namespace std;

// Function for Selection Sort
void selectionSort(float arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        float temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "\nSorted Array using Selection Sort:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function for Bubble Sort
void bubbleSort(float arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted Array using Bubble Sort:\n";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to display top five scores
void displayTopFive(float arr[], int n)
{
    cout << "\nTop Five Student Scores:\n";

    int count = (n < 5) ? n : 5;

    for (int i = n - 1; i >= n - count; i--)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// Main Function
int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0 || n > 100)
    {
        cout << "Invalid number of students!";
        return 0;
    }

    float arr[100];
    float arr2[100];

    cout << "\nEnter student percentages:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << ": ";
        cin >> arr[i];

        arr2[i] = arr[i];
    }

    // Apply Selection Sort
    selectionSort(arr, n);

    // Apply Bubble Sort
    bubbleSort(arr2, n);

    // Display Top Five Scores
    displayTopFive(arr2, n);

    return 0;
}
