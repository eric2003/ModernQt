#ifndef GREENTOWER_H
#define GREENTOWER_H

#include "tower.h"

class GreenTower : public Tower
{
public:
    GreenTower();
public:
    void fire();
public slots:
    void acquireTarget();
};

#endif // GREENTOWER_H
