#pragma once
#include "BoxNode.h"
class BoxList
{
    private:
        vector<BoxNode> mList;

    public:
        size_t getSize();

        void addBox(const string &boxName);
        void addSubBox(const string &boxName, const string &parent = "null");
        void addSouvenir(const string &boxName, const string &souvenir);

        void printList();
};