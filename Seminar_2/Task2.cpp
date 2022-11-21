#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
bool removeStars(const char *s)
{
    stack<char> stek;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ')')
        {
            if (stek.empty())
            {
                return 0;
            }
            else
            {
                stek.pop();
            }
        }
        else
        {
            stek.push(s[i]);
        }
    }
    return stek.empty();
}
int main()
{
    cout << removeStars("))()");
    // cout << removeStars("aa*");
}
