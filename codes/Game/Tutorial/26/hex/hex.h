#ifndef HEX_H
#define HEX_H

#include <QGraphicsPolygonItem>

class Hex : public QGraphicsPolygonItem
{
public:
    // constructors
    Hex();
public:
    // getters
    int getAttackOf(int side);
    // setters
    void setAttackOf(int side, int attack);
    void setOwner(QString player);
private:
    QString owner;
    int side0Attack;
    int side1Attack;
    int side2Attack;
    int side3Attack;
    int side4Attack;
    int side5Attack;
};

#endif // HEX_H
