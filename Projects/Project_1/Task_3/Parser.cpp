#include "Parser.h"
void Parser::setInputStream(const string &fileName)
{
    input.open(fileName, ios::in);
}
string Parser::getWord()
{
    string workStr;
    input >> workStr;
    return workStr;
}
void Parser::getSouvenirs( BoxList &boxes, const string &parent)
{
    size_t numOfSouvenirs;
    string str;
    str = getWord();
    numOfSouvenirs = stoi(str);

    for (int i = 0; i < numOfSouvenirs; i++)
    {
        str = getWord();
        boxes.addSouvenir(parent, str);
    }
}
void Parser::getSubBoxes(BoxList &boxes, const string &parent)
{
    size_t numOfBoxes;
    string str;

    str = getWord();
    numOfBoxes = stoi(str);
    for (int i = 0; i < numOfBoxes; i++)
    {
        str = getWord();

        boxes.addSubBox(str, parent);
    }
    getline(input, str);
}
void Parser::parseLines( BoxList &boxes)
{
    input.seekg(0);
    size_t boxesSize = boxes.getSize();
    string workStr;
    getline(input, workStr);
    for (int i = 0; i < boxesSize; i++)
    {
        workStr = getWord();
        getSouvenirs(boxes, workStr);
        getSubBoxes(boxes, workStr);
    }
}
void Parser::parseInitialBoxes(BoxList &boxes)
{
    string numStr, workStr;
    vector<string> words;
    getline(input, numStr);
    int numOfBoxes = stoi(numStr);
    for (int i = 0; i < numOfBoxes; i++)
    {
        input >> workStr;
        words.push_back(workStr);
        boxes.addBox(workStr);
        getline(input, workStr);
    }
}
Parser::~Parser()
{
    input.close();
}
