#ifndef WIDGET_H
#define WIDGET_H

#include <QWindow>
class QExposeEvent;
class QResizeEvent;

class Widget : public QWindow
{
    Q_OBJECT

public:
    Widget(QWindow *parent = nullptr);
    ~Widget();
protected:
    void exposeEvent( QExposeEvent * ) override;
    void resizeEvent( QResizeEvent * resizeEvent ) override;
private:
    QScopedPointer<QBackingStore> m_backingStore;
};
#endif // WIDGET_H
