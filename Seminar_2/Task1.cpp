#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
char *removeStars(const char *s)
{
    stack<char> stek;
    char *string = new char[strlen(s)];
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '*')
        {
            if (stek.empty())
            {
                throw "Empty stack";
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
    int counter = stek.size();
    string[counter] = '\0';
    while (!stek.empty())
    {
        counter--;
        string[counter] = stek.top();
        
        stek.pop();
    }
    return string;
}
int main()
{
    cout << removeStars("thi*s i*s exampl*e");
    // cout << removeStars("aa*");
}
