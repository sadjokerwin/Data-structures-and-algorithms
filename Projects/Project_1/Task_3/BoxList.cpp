#include "BoxList.h"
size_t BoxList::getSize()
{
    return mList.size();
}
void BoxList::addBox(const string &boxName)
{
    BoxNode *newBox = new BoxNode();
    newBox->setName(boxName);
    mList.push_back(newBox);
}
void BoxList::addSubBox(const string &boxName, const string &parent)
{
    for (int i = 0; i < mList.size(); i++)
    {
        if (mList[i]->getName() == parent)
        {
            for (int k = 0; k < mList.size(); k++)
            {
                if (mList[k]->getName() == boxName)
                {
                    mList[i]->addSubBox(mList[k]);
                    break;
                }
            }
        }
    }
}
void BoxList::addSouvenir(const string &boxName, const string &souvenir)
{
    for (int i = 0; i < mList.size(); i++)
    {
        if (mList[i]->getName() == boxName)
        {
            mList[i]->addSouvenir(souvenir);
            break;
        }
    }
}
bool BoxList::pointlessBoxes() const
{
    int counter = 0;
    for (int i = 0; i < mList.size(); i++)
    {
        if (mList[i] == nullptr)
        {
        }
        else if(mList[i]->hasBoxGotPointlessBoxes())
        {
            counter++;
        }

    }
    return counter != 0;
}
void BoxList::printList()
{
    for (int i = 0; i < mList.size(); i++)
    {
        if (mList[i] != nullptr)
            mList[i]->print();
    }
}
void BoxList::removeAllPointlessBoxes()
{
    for (int i = 0; i < mList.size(); i++)
    {
        if (mList[i] != nullptr)
        {
            removeAPointlessBox(mList[i]);
        }
    }
}
void BoxList::removeAPointlessBox(BoxNode *&box)
{
    if (box->hasBoxGotPointlessBoxes() && box != nullptr)
    {
        if (box->mSouvenirs.empty() && box->mSubBoxes.empty())
        {
            for (int k = 0; k < mList.size(); k++)
            {
                if (mList[k] != nullptr)
                {
                    if (box->mName == mList[k]->mName)
                    {
                        delete mList[k];
                        mList[k] = nullptr;
                        return;
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < box->mSubBoxes.size(); i++)
            {
                if (box->mSubBoxes[i]->isBoxPointless())
                {
                    if (box->mSubBoxes[i]->mSubBoxes.empty())
                    {
                        for (int k = 0; k < mList.size(); k++)
                        {
                            if (mList[k] != nullptr)
                            {
                                if (box->mSubBoxes[i]->mName == mList[k]->mName)
                                {
                                    mList[k] = nullptr;
                                }
                            }
                            else
                            {
                                box->mSubBoxes[i] = nullptr;
                                return;
                            }
                        }
                        delete box->mSubBoxes[i];
                        return;

                    }
                    else
                    {

                        for (int k = 0; k < mList.size(); k++)
                        {
                            if (mList[k] != nullptr)
                            {
                                if (box->mSubBoxes[i]->mName == mList[k]->mName)
                                {

                                    mList[k] = nullptr;
                                }
                            }
                        }
                        BoxNode *toBeDeleted;
                        toBeDeleted = box->mSubBoxes[i];
                        for (int k = 0; k < box->mSubBoxes[i]->mSubBoxes.size(); k++)
                        {
                            box->mSubBoxes.push_back(box->mSubBoxes[i]->mSubBoxes[k]);
                        }
                        delete toBeDeleted;

                        box->mSubBoxes.erase(box->mSubBoxes.begin() + i);
                        return;
                    }
                }
            }
        }
    }
}