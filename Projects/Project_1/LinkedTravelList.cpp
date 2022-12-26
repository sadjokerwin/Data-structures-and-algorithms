#include "LinkedTravelList.h"
void LinkedTravelList::free()
{
    while (mHead)
    {
        TravelListNode* toDelete = mHead;
        mHead = mHead->mNext;
        delete toDelete;
    }
    mNumOfElements = 0;
}
void LinkedTravelList::copy(const LinkedTravelList &other)
{

    TravelListNode *iterator = other.mHead;
    while (iterator)
    {
        pushBack(iterator->mName);
        // cout << "ok";
        iterator = iterator->mNext;
    }
    cout << "copy";
    mNumOfElements = other.mNumOfElements;
}
LinkedTravelList::LinkedTravelList()
{
    mHead = mTail = nullptr;
    mNumOfElements = 0;
}
LinkedTravelList::LinkedTravelList(const LinkedTravelList &other)
{
    mHead = nullptr;
    mTail = nullptr;
    copy(other);
}
void LinkedTravelList::print()
{
    TravelListNode *iter = mHead;
    while(iter)
    {
        cout << iter->mName << endl;
        iter = iter->mNext;
    }
}

void LinkedTravelList::pushBack(const string name)
{
    TravelListNode *toBeAdded = new TravelListNode(name);
    if (mNumOfElements == 0)
    {
        
        mHead = mTail = toBeAdded;
    }
    else
    {
       
        mTail->mNext = toBeAdded;
        mTail = toBeAdded;
    }
    mNumOfElements++;
}
LinkedTravelList::~LinkedTravelList()
{
    free();
}