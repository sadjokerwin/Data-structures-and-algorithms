#include <iostream>
#include <stack>
using namespace std;
void printStack(stack<int> a)
{
    while (!a.empty())
    {
        cout << a.top() << " ";
        a.pop();
    }
}
void sort(stack<int> &original)
{
    int min = INT_MAX;
    stack<int> result;
    printStack(original);
    cout << endl;
    while (!original.empty())
    {
        int toPush = original.top();
        original.pop();
        if (result.empty())
        {

            result.push(toPush);
        }
        else if (toPush >= result.top())
        {
            result.push(toPush);
        }
        else
        {
            min = toPush;
            while (result.top() > min)
            {
                original.push(result.top());
                result.pop();
                if (result.empty())
                    break;
            }
            result.push(toPush);
        }
    }

    original = result;
}
int main()
{
    stack<int> a;
    a.push(-6);
    a.push(10);
    a.push(11);
    a.push(5);
    a.push(3);
    a.push(2);
    a.push(-3);

    sort(a);
    printStack(a);
}