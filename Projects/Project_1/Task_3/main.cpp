#include "Parser.h"
#include "Parser.cpp"

int main()
{
    BoxList boxes;
    Parser parser;
    parser.setInputStream("boxesList.txt");
    parser.parseInitialBoxes(boxes);
    parser.parseLines(boxes);
    
    size_t counter = 0;
    while (boxes.pointlessBoxes())
    {
        counter++;
        boxes.removeAllPointlessBoxes();
    }

    boxes.printList();
    return 0;
}
