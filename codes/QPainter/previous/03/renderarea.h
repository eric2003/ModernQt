#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QPen>
#include <QBrush>
#include <QPixmap>


namespace Ui {
class RenderArea;
}

class RenderArea : public QWidget
{
    Q_OBJECT

public:
    enum Shape { Line, Points, Polyline, Polygon, Rect, RoundedRect, Ellipse, Arc,
               Chord, Pie, Path, Text, Pixmap };
    explicit RenderArea(QWidget *parent = nullptr);
    ~RenderArea();
public slots:
    void setShape( RenderArea::Shape shape );
    void setPen( const QPen &pen );
    void setBrush( const QBrush &brush );
    void setAntialiased( bool antialiased );
    void setTransformed( bool transformed );
protected:
    void paintEvent( QPaintEvent *event ) override;
private:
    Shape shape;
    QPen pen;
    QBrush brush;
    bool antialiased;
    bool transformed;
    QPixmap pixmap;
    Ui::RenderArea *ui;
};

#endif // RENDERAREA_H
