#ifndef BROWNTOWER_H
#define BROWNTOWER_H

#include "tower.h"

class BrownTower : public Tower
{
public:
    BrownTower();
public:
    void fire();
public slots:
    void acquireTarget();
};

#endif // BROWNTOWER_H
