#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
double calc(const int left, const int right, const char op)
{
    switch (op)
    {
    case '+':
        return left + right;
        break;
    case '-':
        return left - right;
        break;
    case '*':
        return left * right;
        break;
    case '/':
        return left / right;
        break;

    default:
        throw "Invalid operation!";
        break;
    }
}
double func(const char *expr)
{
    stack<int> stek;
    int left, right;
    int iter = 0;
    while (expr[iter] != '\0')
    {
        if (expr[iter] > '0' && expr[iter] < '9')
        {
            stek.push(expr[iter]-'0');
            iter++;
        }
        else if (expr[iter] == '+' || expr[iter] == '-' || expr[iter] == '*' || expr[iter] == '/')
{
            right = stek.top();
            stek.pop();
            left = stek.top();
            stek.pop();
            cout << left << " " << right << endl;
            cout << calc(left, right, expr[iter]) << endl;
            stek.push(calc(left, right, expr[iter]));
            iter++;
        }
    }
    return stek.top();
}
int main()
{
    cout << func("123+-");
    // cout << 6 << endl;
    // return 0;
}
// 123+-
// 3->2->1->
