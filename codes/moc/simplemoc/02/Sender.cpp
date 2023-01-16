#include "Sender.h"

Sender::Sender( QObject *parent )
:QObject{ parent }
{
}

void Sender::Increase()
{
    this->data ++;
    emit this->DataChanged( this->data );
}