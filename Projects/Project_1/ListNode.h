#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class ListNode
{
private:
    string mName;
    ListNode *mNext;
    vector<ListNode*> mShortcuts;
    
    void free();
    void copy(const ListNode& head);

    ListNode *mHead;
    ListNode *mTail;
    size_t mNumOfElements;

public:
    ListNode();
    ListNode(const ListNode &other);
    ListNode(const string name, ListNode *&next, const vector<ListNode *> shortcuts, ListNode *&head, ListNode *&tail, size_t numOfElements);

    void pushBack(const ListNode &element);
    ~ListNode();
};