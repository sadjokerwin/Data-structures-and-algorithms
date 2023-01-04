#include "BoxNode.h"
BoxNode::BoxNode()
{
    mName = "null";
    mSouvenirs = {};
    mSubBoxes = {};
}
BoxNode::BoxNode(const string &name, vector<string> &souvenirs, vector<BoxNode *> &subBoxes)
{
    mName = name;
    mSouvenirs = souvenirs;
    mSubBoxes = subBoxes;
}
void BoxNode::print()
{
    cout << "Name of the box: " << mName << endl;
    if (!mSouvenirs.empty())
        for (int i = 0; i < mSouvenirs.size(); i++)
        {
            cout << mSouvenirs[i] << " ";
        }
    else
        cout << "There are no souvenirs";
    cout << endl;
    if (!mSubBoxes.empty())
    {
        for (int i = 0; i < mSubBoxes.size(); i++)
        {
            cout << mSubBoxes[i]->mName << " ";
        }
    }
    else
        cout << "There are no smaller boxes inside this boxes";
    cout << endl <<endl;
}
void BoxNode::setName(const string &name)
{
    mName = name;
}
string BoxNode::getName() const
{
    return mName;
}
void BoxNode::addSouvenir(const string &souvenir)
{
    mSouvenirs.push_back(souvenir);
}
void BoxNode::addSubBox(BoxNode *&subBox)
{
    BoxNode *toBeAdded = new BoxNode();
    toBeAdded = subBox;
    toBeAdded->mName = subBox->mName;
    mSubBoxes.push_back(toBeAdded);
}