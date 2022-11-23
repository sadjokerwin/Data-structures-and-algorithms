#include <iostream>
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int>& source, int k)
{
    vector<int> result;
    if(k>source.size())
        throw "Window is bigger than the original array!";
    int counterLast = k-1;
    int counterFirst = 0;
    int maxInWindow;
    while(counterLast != source.size())
    {
        maxInWindow = INT_MIN;
        for (int i = counterFirst; i <= counterLast; i++)
        {
            if(source[i]>maxInWindow)
                maxInWindow = source[i];
        }
        result.push_back(maxInWindow);
        counterFirst++;
        counterLast++;
    }
    return result;
}
int main()
{
    vector<int> ex = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> result = maxSlidingWindow(ex, 3);
    for (auto elem : result)
    {
        cout << elem << " ";
    }
}