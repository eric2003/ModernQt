#ifndef REDTOWER_H
#define REDTOWER_H

#include "tower.h"

class RedTower : public Tower
{
public:
    RedTower();
public:
    void fire();
public slots:
    void acquireTarget();
};

#endif // REDTOWER_H
