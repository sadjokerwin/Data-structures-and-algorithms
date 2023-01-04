#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class BoxNode
{
private:
    

public:
    string mName;
    vector<string> mSouvenirs;
    vector<BoxNode *> mSubBoxes;
    BoxNode();
    BoxNode(const string& name , vector<string> &souvenirs, vector<BoxNode *> &subBoxes);

    void print();

    void setName(const string &name);
    string getName() const;

    void addSouvenir(const string &souvenir);
    void addSubBox(BoxNode *&subBox);

    bool isBoxPointless() const;
    bool hasBoxGotPointlessBoxes() const;

};