#include "Parser.h"
#include "Parser.cpp"

int main()
{
    BoxList boxes;
    Parser parser;
    parser.setInputStream("boxesList.txt");
    parser.parseInitialBoxes(boxes);
    parser.parseLines(boxes);
    // boxes.printList();
    // boxes.removeAPointlessBox(boxes.mList[0]);
    // boxes.removeAPointlessBox(boxes.mList[0]);
    // boxes.printList();
    // cout<<boolalpha<<boxes.pointlessBoxes();
    // boxes.removeAllPointlessBoxes();
    // cout << boolalpha << boxes.pointlessBoxes();
    // boxes.removeAllPointlessBoxes();
    // cout << boolalpha << boxes.pointlessBoxes();
    size_t counter = 0;
    // while (boxes.pointlessBoxes())
    // {
    //     counter++;
    //     boxes.removeAllPointlessBoxes();
    //     cout << "##########################" << counter << "##########################"<<endl;
    // }
    boxes.removeAllPointlessBoxes();
    // boxes.removeAllPointlessBoxes();
    boxes.removeAllPointlessBoxes();
    cout <<boolalpha<< boxes.pointlessBoxes();
    // boxes.removeAllPointlessBoxes();
    // cout << endl
    //      << endl
    //      << endl
    //      << boxes.mList[0]->mSubBoxes.size() << endl
    //      << endl
    //      << endl
    //      << endl;
    // // cout << "IZTRILO GO E EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE" << endl;

    // boxes.printList();

    // boxes.removeAPointlessBox(boxes.mList[0]);

    return 0;
}
