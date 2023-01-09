#include "LinkedTravelList.h"
void LinkedTravelList::free()
{
    while (mHead)
    {
        TravelListNode *toDelete = mHead;
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
    for (int i = 0; i < mNumOfElements; i++)
        isCityVisited[mNumOfElements - 1] == 0;
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
    while (iter)
    {
        cout << iter->mName << " " << iter->numberInTheList << " ";
        if (iter->mSkip != nullptr)
            cout << iter->mSkip->mName << endl;
        else
            cout << endl;
        iter = iter->mNext;
    }
}
TravelListNode *LinkedTravelList::findCityPointer(const string &cityName)
{
    TravelListNode *iter = mHead;
    while (iter)
    {
        if (iter->mName == cityName)
        {
            return iter;
        }
        iter = iter->mNext;
    }
    return iter;
}
void LinkedTravelList::addSkipStation(const string &beginCity, const string &endCity)
{
    TravelListNode *iter = new TravelListNode();
    iter = mHead;
    while (iter)
    {
        if (iter->mName == beginCity)
        {
            iter->mSkip = findCityPointer(endCity);
            return;
        }
        iter = iter->mNext;
    }
}
void LinkedTravelList::pushBack(const string name)
{
    TravelListNode *toBeAdded = new TravelListNode(name);
    if (mNumOfElements == 0)
    {
        toBeAdded->numberInTheList = ++mNumOfElements;
        mHead = mTail = toBeAdded;
        isCityVisited.push_back(false);
    }
    else
    {
        toBeAdded->numberInTheList = ++mNumOfElements;
        mTail->mNext = toBeAdded;
        mTail = toBeAdded;
        isCityVisited.push_back(false);
    }
}
string LinkedTravelList::front()
{
    return mHead->mName;
}
string LinkedTravelList::back()
{
    return mTail->mName;
}
TravelListNode *LinkedTravelList::frontIter()
{
return mHead;
}
int LinkedTravelList::findPathBetweenTwoCities(const string &beginCity, const string &endCity, queue<string> &Q)
{
    if (findCityPointer(beginCity)->numberInTheList < findCityPointer(endCity)->numberInTheList && isCityVisited[findCityPointer(beginCity)->numberInTheList - 1] == 0)
    {
        Q.push(beginCity);
        isCityVisited[findCityPointer(beginCity)->numberInTheList - 1] = true;
    }
    if (findCityPointer(beginCity)->numberInTheList > findCityPointer(endCity)->numberInTheList)
    {
        return 10000;
    }
    else if (findCityPointer(beginCity)->mNext->mName == endCity)
    {
        return 1;
    }
    else if (findCityPointer(beginCity)->mSkip != nullptr && findCityPointer(beginCity)->mSkip->mName == endCity)
    {
        return 1;
    }
    else
    {
        if (findCityPointer(beginCity)->mSkip != nullptr)
            return min(findPathBetweenTwoCities(findCityPointer(beginCity)->mNext->mName, endCity, Q), findPathBetweenTwoCities(findCityPointer(beginCity)->mSkip->mName, endCity, Q)) + 1;
        else
            return findPathBetweenTwoCities(findCityPointer(beginCity)->mNext->mName, endCity, Q) + 1;
    }
}
LinkedTravelList::~LinkedTravelList()
{
    free();
}