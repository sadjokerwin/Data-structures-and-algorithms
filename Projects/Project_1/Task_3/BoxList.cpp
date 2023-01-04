#include "BoxList.h"
size_t BoxList::getSize()
{
    return mList.size();
}
void BoxList::addBox(const string &boxName)
{
    BoxNode *newBox = new BoxNode();
    newBox->setName(boxName);
    // newBox->print();
    mList.push_back(*newBox);
    // cout << mList[mList.size()-1].getName();
    // if (mList.size() != 1)
    // {
    //     for (int i = 0; i < mList.size(); i++)
    //     {
    //         if (mList[i].getName() == parent)
    //         {
    //             mList[i].addSubBox(newBox);
    //             break;
    //         }
    //     }
    // }
}
void BoxList::addSubBox(const string &boxName, const string &parent)
{
    for (int i = 0; i < mList.size(); i++)
    {
        if (mList[i].getName() == parent)
        {
            for (int k = 0; k < mList.size(); k++)
            {
                if (mList[k].getName() == boxName)
                {
                    mList[i].addSubBox(mList[k]);
                    break;
                }
            }

        }
    }
    //-----------------------------
    BoxNode *newBox = new BoxNode();
    newBox->setName(boxName);
    // newBox->print();
    // mList.push_back(*newBox);
    if (mList.size() != 1)
    {
        for (int i = 0; i < mList.size(); i++)
        {
            if (mList[i].getName() == parent)
            {
                mList[i].addSubBox(newBox);
                break;
            }
        }
    }
}
void BoxList::addSouvenir(const string &boxName, const string &souvenir)
{
    for (int i = 0; i < mList.size(); i++)
    {
        if (mList[i].getName() == boxName)
        {
            mList[i].addSouvenir(souvenir);
            break;
        }
    }
}
void BoxList::pointlessBoxes() const
{
    for (int i = 0; i < mList.size(); i++)
        cout << boolalpha << mList[i].hasBoxGotPointlessBoxes();
}
void BoxList::printList()
{
    for (int i = 0; i < mList.size(); i++)
        mList[i].print();
}