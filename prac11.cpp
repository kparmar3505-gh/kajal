
#include <iostream>
#include <stack>
using namespace std;

// Function to check matching brackets
bool isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return true;

    if (open == '{' && close == '}')
        return true;

    if (open == '[' && close == ']')
        return true;

    return false;
}

// Function to check balanced parentheses
bool checkParentheses(string exp)
{
    stack<char> st;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // If opening bracket, push into stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }

        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.empty())
            {
                return false;
            }

            char top = st.top();
            st.pop();

            if (!isMatching(top, ch))
            {
                return false;
            }
        }
    }

    // Check whether stack is empty
    return st.empty();
}

// Main function
int main()
{
    string exp;

    cout << "Enter an expression: ";
    getline(cin, exp);

    if (checkParentheses(exp))
    {
        cout << "Parentheses are Balanced!";
    }
    else
    {
        cout << "Parentheses are Not Balanced!";
    }

    return 0;
}
