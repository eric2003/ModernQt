#ifndef DRAGABLEFORM_H
#define DRAGABLEFORM_H

#include <QFrame>

namespace Ui {
class DragableForm;
}

class DragableForm : public QFrame
{
    Q_OBJECT

public:
    explicit DragableForm(QWidget *parent = nullptr);
    ~DragableForm();

private:
    Ui::DragableForm *ui;


    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dropEvent(QDropEvent *event) override;
};


#endif // DRAGABLEFORM_H
