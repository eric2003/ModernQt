#include "IntSpinDelegate.h"
#include <QSpinBox>

IntSpinDelegate::IntSpinDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget *IntSpinDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox * spinbox = new QSpinBox( parent );
    spinbox->setMinimum( 0 );
    spinbox->setMaximum( 200 );
    return spinbox;
}

void IntSpinDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
}

void IntSpinDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
}

void IntSpinDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
}

