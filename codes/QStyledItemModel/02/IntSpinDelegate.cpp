#include "IntSpinDelegate.h"
#include <QSpinBox>

IntSpinDelegate::IntSpinDelegate(QObject *parent)
    : QStyledItemDelegate{parent}
{

}

QWidget *IntSpinDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED( option );
    Q_UNUSED( index );
    QSpinBox * editor = new QSpinBox( parent );
    editor->setMinimum( 0 );
    editor->setMaximum( 99 );
    return editor;
}

void IntSpinDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data( index, Qt::EditRole ).toInt();
    QSpinBox * spinBox = static_cast<QSpinBox *>( editor );
    spinBox->setValue( value );
}

void IntSpinDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox * spinBox = static_cast<QSpinBox *>( editor );
    spinBox->interpretText();
    int value = spinBox->value();
    model->setData( index, value, Qt::EditRole );
}

void IntSpinDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED( index );
    editor->setGeometry( option.rect );
}

