#include "QueueHelpers.h"
template <typename T>
void printAll(queue<T> Q)
{
    while (!Q.empty())
    {
        cout << Q.front() << endl;
        Q.pop();
    }
}
template <typename T>
void printSome(queue<T> Q, size_t numOfPrintedElems)
{
    for (int i = 0; i < numOfPrintedElems; i++)
    {
        cout << Q.front() << endl;
        Q.pop();
    }
}
template <typename T>
void clear(queue<T> &Q)
{
    while (!Q.empty())
        Q.pop();
}