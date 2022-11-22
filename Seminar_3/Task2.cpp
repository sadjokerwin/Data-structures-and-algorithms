#include <iostream>
#include <queue>
using namespace std;
struct coord
{
    int x;
    int y;
    coord()
    {
        x = 0;
        y = 0;
    }
    coord(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};
struct movesTillNow
{
    coord posNow;
    int moves;
    movesTillNow(coord coords, int moves)
    {
        posNow = coords;
        this->moves = moves;
    }
};
void clean(bool **matrix, int boardSize)
{
    for (int i = 0; i < boardSize; i++)
    {
        delete matrix[i];
    }
    delete matrix;
}
bool isValidMove(coord &current, int nextX, int nextY, bool **matrix, int boardSize)
{
    if (nextX >= 0 && nextY >= 0 && nextX <= boardSize && nextY <= boardSize)
        return matrix[nextX][nextY] == 0;
    else
        return 0;
}
void pushAndMarkField(movesTillNow current, int nextX, int nextY, bool **matrix, queue<movesTillNow> &workQueue, int boardSize)
{
    if (isValidMove(current.posNow, nextX, nextY, matrix, boardSize))
    {
        matrix[nextX][nextY] = true;
        current.posNow.x = nextX;
        current.posNow.y = nextY;
        current.moves += 1;
        workQueue.push(current);
    }
}
int func(coord &start, coord &finish, int boardSize)
{
    queue<movesTillNow> workQueue;
    movesTillNow begin(start, 0);
    bool **matrix = new bool *[boardSize+1];
    for (int i = 0; i <= boardSize; i++)
    {
        matrix[i] = new bool[boardSize+1];
        for (int j = 0; j <= boardSize; j++)
            matrix[i][j] = false;
    }
    workQueue.push(begin);
    matrix[0][0] = true;
    while (true)
    {
        movesTillNow current = workQueue.front();
        if (current.posNow.x == finish.x && current.posNow.y == finish.y)
        {
            return current.moves; 
        }
        else
        {
            workQueue.pop();
            pushAndMarkField(current, current.posNow.x + 2, current.posNow.y + 1, matrix, workQueue, boardSize);
            pushAndMarkField(current, current.posNow.x + 2, current.posNow.y - 1, matrix, workQueue, boardSize);
            pushAndMarkField(current, current.posNow.x - 2, current.posNow.y + 1, matrix, workQueue, boardSize);
            pushAndMarkField(current, current.posNow.x - 2, current.posNow.y - 1, matrix, workQueue, boardSize);
            pushAndMarkField(current, current.posNow.x + 1, current.posNow.y + 2, matrix, workQueue, boardSize);
            pushAndMarkField(current, current.posNow.x + 1, current.posNow.y - 2, matrix, workQueue, boardSize);
            pushAndMarkField(current, current.posNow.x - 1, current.posNow.y + 2, matrix, workQueue, boardSize);
            pushAndMarkField(current, current.posNow.x - 1, current.posNow.y - 2, matrix, workQueue, boardSize);
        }     
       
    }
    clean(matrix, boardSize);
    return 0;
}
int main()
{
    coord Start(0, 0);
    coord Finish(6, 3);
    cout<<func(Start, Finish, 7);
}