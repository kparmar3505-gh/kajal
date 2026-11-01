
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_map>
#include <cctype>
#include <cmath>
using namespace std;

// Function to check operator precedence
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to convert infix into tokens
vector<string> tokenize(string exp)
{
    vector<string> tokens;

    for (int i = 0; i < exp.length();)
    {
        if (isspace(exp[i]))
        {
            i++;
        }
        else if (isdigit(exp[i]) || exp[i] == '.')
        {
            string num = "";

            while (i < exp.length() &&
                  (isdigit(exp[i]) || exp[i] == '.'))
            {
                num += exp[i++];
            }

            tokens.push_back(num);
        }
        else if (isalpha(exp[i]))
        {
            string var = "";

            while (i < exp.length() && isalnum(exp[i]))
            {
                var += exp[i++];
            }

            tokens.push_back(var);
        }
        else
        {
            tokens.push_back(string(1, exp[i]));
            i++;
        }
    }

    return tokens;
}

// Function to convert infix to postfix
vector<string> infixToPostfix(vector<string> tokens)
{
    stack<char> st;
    vector<string> postfix;

    for (string token : tokens)
    {
        if (isalnum(token[0]) || token[0] == '.')
        {
            postfix.push_back(token);
        }
        else if (token == "(")
        {
            st.push('(');
        }
        else if (token == ")")
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix.push_back(string(1, st.top()));
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else
        {
            char op = token[0];

            while (!st.empty() && st.top() != '(' &&
                  (precedence(st.top()) > precedence(op) ||
                  (precedence(st.top()) == precedence(op) &&
                   op != '^')))
            {
                postfix.push_back(string(1, st.top()));
                st.pop();
            }

            st.push(op);
        }
    }

    while (!st.empty())
    {
        postfix.push_back(string(1, st.top()));
        st.pop();
    }

    return postfix;
}

// Function to evaluate postfix expression
double evaluatePostfix(vector<string> postfix,
                       unordered_map<string, double> values)
{
    stack<double> st;

    for (string token : postfix)
    {
        if (isdigit(token[0]) || token[0] == '.')
        {
            st.push(stod(token));
        }
        else if (isalpha(token[0]))
        {
            st.push(values[token]);
        }
        else
        {
            double b = st.top();
            st.pop();

            double a = st.top();
            st.pop();

            switch (token[0])
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

                case '^':
                    st.push(pow(a, b));
                    break;
            }
        }
    }

    return st.top();
}

// Main function
int main()
{
    string exp;

    cout << "Enter infix expression: ";
    getline(cin, exp);

    vector<string> tokens = tokenize(exp);

    vector<string> postfix = infixToPostfix(tokens);

    cout << "\nPostfix Expression: ";

    for (string token : postfix)
    {
        cout << token << " ";
    }

    // Take variable values from user
    unordered_map<string, double> values;

    for (string token : postfix)
    {
        if (isalpha(token[0]) && values.find(token) == values.end())
        {
            cout << "\nEnter value of " << token << ": ";
            cin >> values[token];
        }
    }

    // Evaluate postfix expression
    double result = evaluatePostfix(postfix, values);

    cout << "\nFinal Result: " << result << endl;

    return 0;
}
