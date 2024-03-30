#ifndef HEXBOARD_H
#define HEXBOARD_H

#include <QList>

class Hex;

class HexBoard
{
public:
    // constructors
    HexBoard();
public:
    // getters/setters
    QList<Hex*> getHexes();
    // public methods
    void placeHexes();
private:
    void createHexColumn(int x, int y, int numOfRows);
    QList<Hex *> hexes;
};

#endif // HEXBOARD_H
