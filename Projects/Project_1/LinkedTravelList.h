#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "TravelListNode.h"
// #include "TravelListNode.cpp"

using namespace std;
class LinkedTravelList
{
private:
    void free();
    void copy(const LinkedTravelList &other);

    TravelListNode *mHead;
    TravelListNode *mTail;
    size_t mNumOfElements;
    friend struct TravelListNode;

public:
    LinkedTravelList();
    LinkedTravelList(const LinkedTravelList &other);
    void print();

    void pushBack(const string name);
    ~LinkedTravelList();
};