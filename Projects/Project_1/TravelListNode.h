#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct TravelListNode
{
    string mName;
    TravelListNode *mNext;
    TravelListNode *mSkip;
    size_t numberInTheList;
    TravelListNode(const string &name = "null", TravelListNode *next = nullptr, TravelListNode *skip = nullptr, const size_t &num = 0) : mName{name}, mNext{next}, mSkip{skip}, numberInTheList{num} {}

public:
    void print()
    {
        cout << mName;
    }
    TravelListNode *next()
    {
        if (mNext != nullptr)
            return mNext;
        else
            return nullptr;
    }
};
