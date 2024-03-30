#include "hexboard.h"
#include "hex.h"
#include "game.h"

extern Game *game;

HexBoard::HexBoard() {}

QList<Hex *> HexBoard::getHexes()
{
    return this->hexes;

}

void HexBoard::placeHexes()
{
    this->createHexColumn(100,100,5);

}

void HexBoard::createHexColumn(int x, int y, int numOfRows)
{
    // create a colume of Hexes at the specified location with the specified
    // number of rows

    for ( size_t i = 0; i < numOfRows;  ++ i )
    {
        Hex *hex = new Hex();
        hex->setPos(x, y+82*i);
        this->hexes.append(hex);
        game->scene->addItem(hex);
    }
}
