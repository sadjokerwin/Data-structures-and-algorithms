#include <iostream>
#include <queue>
#include <string>
using namespace std;
void add2Strings(queue<string>& result)
{
    result.push(result.front() + "0");
    result.push(result.front() + "1");
}
void printBinary(const int& n)
{
    queue<string> result;
    int counter = 1;
    result.push("1");
    while(counter<=n)
    {
        add2Strings(result);
        cout << result.front()<<endl;
        result.pop();
        counter++;
    }

}
int main()
{
    int n = 20;
    printBinary(n);
    return 0;
}