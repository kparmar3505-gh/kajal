
#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// Creating a Stack
class BrowserHistory
{
    string history[MAX];
    int top;

public:

    // Constructor
    BrowserHistory()
    {
        top = -1;
    }

    // Visit a new page (Push)
    void visitPage(string url)
    {
        if (top == MAX - 1)
        {
            cout << "History is full!\n";
        }
        else
        {
            top++;
            history[top] = url;

            cout << "Page visited successfully!\n";
        }
    }

    // Go back to previous page (Pop)
    void goBack()
    {
        if (top == -1)
        {
            cout << "No previous page available!\n";
        }
        else
        {
            cout << "Going back from: "
                 << history[top] << endl;

            top--;
        }
    }

    // Display current page
    void currentPage()
    {
        if (top == -1)
        {
            cout << "No page is currently open!\n";
        }
        else
        {
            cout << "Current Page: "
                 << history[top] << endl;
        }
    }

    // Display complete browsing history
    void displayHistory()
    {
        if (top == -1)
        {
            cout << "Browsing history is empty!\n";
        }
        else
        {
            cout << "\nBrowsing History:\n";

            for (int i = top; i >= 0; i--)
            {
                cout << history[i] << endl;
            }
        }
    }
};

// Main Function
int main()
{
    BrowserHistory browser;

    int choice;
    string url;

    do
    {
        cout << "\n===== BROWSER HISTORY SYSTEM =====\n";
        cout << "1. Visit New Page\n";
        cout << "2. Go Back\n";
        cout << "3. Display Current Page\n";
        cout << "4. Display Browsing History\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter URL: ";
                cin >> url;

                browser.visitPage(url);
                break;

            case 2:
                browser.goBack();
                break;

            case 3:
                browser.currentPage();
                break;

            case 4:
                browser.displayHistory();
                break;

            case 5:
                cout << "Exiting Browser History System...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
