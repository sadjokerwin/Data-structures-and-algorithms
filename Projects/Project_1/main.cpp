#include "LinkedTravelList.h"
#include "LinkedTravelList.cpp"
#include "TravelListNode.h"

#include "QueueHelpers.cpp"
#include "QueueHelpers.h"

#include <list>

LinkedTravelList *initiateList(const int &numOfStations, list<string> &stations)
{
    list<string>::iterator iter;
    LinkedTravelList *list1 = new LinkedTravelList();
    for (iter = stations.begin(); iter != stations.end(); iter++)
    {
        list1->pushBack(*iter);
    }
    return list1;
}
void printJourneyRoute(LinkedTravelList *stations, list<string> &desiredLocations)
{
    list<string>::iterator iterDesired;
    TravelListNode *iterStations = stations->frontIter();
    iterDesired = desiredLocations.begin();
    size_t pathLength = 0;
    queue<string> workQueue;
    if (*iterDesired != stations->front())
    {
        pathLength = stations->findPathBetweenTwoCities(stations->front(), *iterDesired, workQueue);
        printSome(workQueue, pathLength);
        clear(workQueue);
    }
    while (*iterDesired != desiredLocations.back())
    {
        pathLength = stations->findPathBetweenTwoCities(*--iterDesired, *++iterDesired, workQueue);
        printSome(workQueue, pathLength);
        clear(workQueue);
        iterDesired++;
    }
    if (*iterDesired != stations->back())
    {
        pathLength = stations->findPathBetweenTwoCities(*iterDesired, stations->back(), workQueue);
        printSome(workQueue, pathLength);
        clear(workQueue);
        cout << stations->back();
    }
    else
        cout << stations->back();
}
using namespace std;
int main()
{
    list<string> cityList;
    cityList.push_back("Sofia");
    cityList.push_back("Pazardzhik");
    cityList.push_back("Plovdiv");
    cityList.push_back("Dimitrovgrad");
    cityList.push_back("StaraZagora");
    cityList.push_back("NovaZagora");
    cityList.push_back("Yambol");
    cityList.push_back("Karnobat");
    cityList.push_back("Burgas");

    LinkedTravelList *z = initiateList(9, cityList);

    z->addSkipStation("Sofia", "Plovdiv");
    z->addSkipStation("Plovdiv", "NovaZagora");
    z->addSkipStation("Dimitrovgrad", "NovaZagora");
    z->addSkipStation("StaraZagora", "Yambol");
    z->addSkipStation("NovaZagora", "Burgas");
    queue<string> result;
    list<string> locationList;

    locationList.push_back("Plovdiv");
    locationList.push_back("StaraZagora");
    locationList.push_back("Yambol");

    printJourneyRoute(z, locationList);
    return 0;
}
