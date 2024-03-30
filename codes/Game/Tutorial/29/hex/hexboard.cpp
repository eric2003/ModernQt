#include "hexboard.h"
#include "hex.h"
#include "game.h"

extern Game *game;

HexBoard::HexBoard() {}

QList<Hex *> HexBoard::getHexes()
{
    return this->hexes;

}

void HexBoard::placeHexes(int x, int y, int cols, int rows)
{
    int X_SHIFT = 82;
    int Y_SHIFT = 41;
    for ( size_t i = 0; i < cols; ++ i )
    {
        int coef = 0;
        if( i%2 ==0 ) {
            coef = 0;
        } else {
            coef = 1;
        }
        this->createHexColumn(x+X_SHIFT*i,y+coef*Y_SHIFT,rows);
    }
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

        // set owner to NOONE initially
        hex->setOwner(QString("NOONE"));
    }
}
