#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <queue>
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
    vector<bool> isCityVisited;

public:
    LinkedTravelList();
    LinkedTravelList(const LinkedTravelList &other);
    void print();
    void pushBack(const string name);

    TravelListNode *findCityPointer(const string &cityName);
    void addSkipStation(const string &beginCity, const string &endCity);

    string front();
    string back();

    TravelListNode* frontIter();
  

    int findPathBetweenTwoCities(const string &beginCity, const string &endCity, queue<string> &Q);

    ~LinkedTravelList();
};