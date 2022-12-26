#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
struct TravelListNode
{
    string mName;
    TravelListNode *mNext;
    // vector<ListNode *> mShortcuts;
    TravelListNode(const string &name = "null", TravelListNode *next = nullptr) : mName {name}, mNext {next} {}
};
