#pragma once
#include "BoxNode.h"
#include "BoxNode.cpp"
#include "BoxList.h"
#include "BoxList.cpp"
#include <fstream>
class Parser
{
private:
    ifstream input;

public:
    void setInputStream(const string &fileName);
    string getWord();
    void getSouvenirs(BoxList &boxes, const string &parent);
    void getSubBoxes(BoxList &boxes, const string &parent);
    void parseLines(BoxList &boxes);
    void parseInitialBoxes( BoxList &boxes);
    ~Parser();
};