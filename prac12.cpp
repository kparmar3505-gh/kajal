
#include <iostream>
#include <stack>
#include <string>
#include <map>
#include <vector>
#include <cctype>
using namespace std;

// Function to check operator precedence
int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;

    return 0;
}

// Function to display stack
void displayStack(stack<char> st)
{
    vector<char> temp;

    while (!st.empty())
    {
        temp.push_back(st.top());
        st.pop();
    }

    cout << "Stack: ";

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        cout << temp[i] << " ";
    }

    cout << endl;
}

// Function to convert infix to postfix
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }

        cout << "After processing " << ch << ": ";
        displayStack(st);
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
double evaluatePostfix(string postfix, map<char, double> values)
{
    stack<double> st;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (isalpha(ch))
        {
            st.push(values[ch]);
        }
        else
        {
            double b = st.top();
            st.pop();

            double a = st.top();
            st.pop();

            switch (ch)
            {
                case '+':
                    st.push(a + b);
                    break;

                case '-':
                    st.push(a - b);
                    break;

                case '*':
                    st.push(a * b);
                    break;

                case '/':
                    if (b == 0)
                    {
                        cout << "Division by zero error!";
                        return 0;
                    }
                    st.push(a / b);
                    break;
            }
        }

        // Display evaluation stack
        stack<double> temp = st;

        cout << "Stack after processing " << ch << ": ";

        vector<double> arr;

        while (!temp.empty())
        {
            arr.push_back(temp.top());
            temp.pop();
        }

        for (int j = arr.size() - 1; j >= 0; j--)
        {
            cout << arr[j] << " ";
        }

        cout << endl;
    }

    return st.top();
}

// Main function
int main()
{
    string infix;

    cout << "===== COLLEGE BILLING SYSTEM =====\n";

    cout << "\nEnter fee formula in infix form: ";
    getline(cin, infix);

    // Convert infix to postfix
    cout << "\n--- INFIX TO POSTFIX CONVERSION ---\n";

    string postfix = infixToPostfix(infix);

    cout << "\nPostfix Expression: " << postfix << endl;

    // Input fee details
    map<char, double> values;

    cout << "\nEnter Tuition Fee: ";
    cin >> values['T'];

    cout << "Enter Hostel Fee: ";
    cin >> values['H'];

    cout << "Enter Exam Fee: ";
    cin >> values['E'];

    cout << "Enter Scholarship: ";
    cin >> values['S'];

    // Evaluate postfix expression
    cout << "\n--- POSTFIX EVALUATION ---\n";

    double total = evaluatePostfix(postfix, values);

    cout << "\nFinal Payable Fees: Rs. " << total << endl;

    return 0;
}
