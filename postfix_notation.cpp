#include "postfix_notation.hpp"

bool is_operator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}

int perform_operation(int op1, int op2, char op)
{
    int ans;
    switch (op)
    {
    case '+':
        ans = op2 + op1;
        break;
    case '-':
        ans = op2 - op1;
        break;
    case '*':
        ans = op2 * op1;
        break;
    case '/':
        ans = op2 / op1;
        break;
    }
    return ans;
}

int evaluate_postfix(string exp)
{
    char buffer[15];
    int i, op1, op2, len, j, x;
    stack<int> s;
    j = 0;
    len = exp.length();
    for (i = 0; i < len; i++)
    {

        if (exp[i] >= '0' && exp[i] <= '9')
        {
            buffer[j++] = exp[i];
        }
        else if (exp[i] == ' ')
        {
            if (j > 0)
            {
                buffer[j] = '\0';
                x = atoi(buffer);
                s.push(x);
                j = 0;
            }
        }

        else if (is_operator(exp[i]))
        {
            op1 = s.top();
            s.pop();
            op2 = s.top();
            s.pop();
            s.push(perform_operation(op1, op2, exp[i]));
        }
    }
    return s.top();
}
