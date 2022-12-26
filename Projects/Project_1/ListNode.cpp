#include "ListNode.h"
void ListNode::free()
{
    while (mHead)
    {
        ListNode *toDelete = mHead;
        mHead = mHead->mNext;
        delete toDelete;
    }
    mNumOfElements = 0;
}
void ListNode::copy(const ListNode &other)
{
    ListNode *iterator = other.mHead;
    while (iterator)
    {

        ListNode *curr = new ListNode();
    }
}
ListNode::ListNode()
{
    mName = "null";
    mNext = nullptr;
    mShortcuts[0] = nullptr;
    mShortcuts.shrink_to_fit();
    mHead = nullptr;
    mTail = nullptr;
    mNumOfElements = 0;
}
ListNode::ListNode(const ListNode &other)
{
    mName = other.mName;
    mNext = other.mNext;
    mShortcuts = other.mShortcuts;
    mHead = other.mHead;
    mTail = other.mTail;
    mNumOfElements = other.mNumOfElements;
}
ListNode::ListNode(const string name, ListNode *&next, const vector<ListNode *> shortcuts, ListNode *&head, ListNode *&tail, size_t numOfElements)
{
    mName = name;
    mNext = next;
    mShortcuts = shortcuts;
}

void ListNode::pushBack(const ListNode &element)
{
    ListNode *toBeAdded = new ListNode(element);
    mNumOfElements++;
    if (!mNumOfElements)
    {
        mHead = toBeAdded;
        mTail = toBeAdded;
    }
    else
    {
        toBeAdded->mNext = nullptr;
        mTail->mNext = toBeAdded;
        mTail = toBeAdded;
    }
}
ListNode::~ListNode()
{
    free();
}