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
    QString getOwner();
    bool getIsPlaced();
    // setters
    void setAttackOf(int side, int attack);
    void setOwner(QString player);
    void setIsPlaced(bool b);
    void displaySideAttacks();
    void createLines();
    void findNeighbors();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QList<QGraphicsLineItem *> lines;
    QList<Hex *> neighbors;
    bool isPlaced;
    QString owner;
    int side0Attack;
    int side1Attack;
    int side2Attack;
    int side3Attack;
    int side4Attack;
    int side5Attack;
    QList<QGraphicsTextItem *> attackTexts;
};

#endif // HEX_H
