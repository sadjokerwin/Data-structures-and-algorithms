#include "Parser.h"
#include "Parser.cpp"

#include <fstream>

int main()
{
    BoxList boxes;
    Parser parser;
    parser.setInputStream("boxesList.txt");
    parser.parseInitialBoxes(boxes);
    parser.parseLines(boxes);
    boxes.printList();

    return 0;
}
