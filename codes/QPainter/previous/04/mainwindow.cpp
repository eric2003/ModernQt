#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBoxShape->addItem( tr("Ploygon"), RenderArea::Polygon );
    ui->comboBoxShape->addItem( tr("Rectangle"), RenderArea::Rect );
    ui->comboBoxShape->addItem( tr("Rounded Rectangle"), RenderArea::RoundedRect );
    ui->comboBoxShape->addItem( tr("Ellipse"), RenderArea::Ellipse );
    ui->comboBoxShape->addItem( tr("Pie"), RenderArea::Pie );
    ui->comboBoxShape->addItem( tr("Chord"), RenderArea::Chord );
    ui->comboBoxShape->addItem( tr("Path"), RenderArea::Path );
    ui->comboBoxShape->addItem( tr("Line"), RenderArea::Line );
    ui->comboBoxShape->addItem( tr("Polyline"), RenderArea::Polyline );
    ui->comboBoxShape->addItem( tr("Arc"), RenderArea::Arc );
    ui->comboBoxShape->addItem( tr("Points"), RenderArea::Points );
    ui->comboBoxShape->addItem( tr("Text"), RenderArea::Text );
    ui->comboBoxShape->addItem( tr("Pixmap"), RenderArea::Pixmap );

    ui->spinBoxPenWidth->setRange( 0, 20 );
    ui->spinBoxPenWidth->setSpecialValueText( tr("0 (cosmetic pen)") );

    ui->comboBoxPenStyle->addItem( tr("Solid"), static_cast<int>(Qt::SolidLine) );
    ui->comboBoxPenStyle->addItem( tr("Dash"), static_cast<int>(Qt::DashLine) );
    ui->comboBoxPenStyle->addItem( tr("Dot"), static_cast<int>(Qt::DotLine) );
    ui->comboBoxPenStyle->addItem( tr("Dash Dot"), static_cast<int>(Qt::DashDotLine) );
    ui->comboBoxPenStyle->addItem( tr("Dash Dot Dot"), static_cast<int>(Qt::DashDotDotLine) );
    ui->comboBoxPenStyle->addItem( tr("None"), static_cast<int>(Qt::NoPen) );

    ui->comboBoxPenCap->addItem( tr("Flat"), Qt::FlatCap );
    ui->comboBoxPenCap->addItem( tr("Square"), Qt::SquareCap );
    ui->comboBoxPenCap->addItem( tr("Round"), Qt::RoundCap );

    ui->comboBoxPenJoin->addItem( tr("Miter"), Qt::MiterJoin );
    ui->comboBoxPenJoin->addItem( tr("Bevel"), Qt::BevelJoin );
    ui->comboBoxPenJoin->addItem( tr("Round"), Qt::RoundJoin );

    ui->comboBoxBrush->addItem( tr("Linear Gradient"), static_cast<int>( Qt::LinearGradientPattern ) );
    ui->comboBoxBrush->addItem( tr("Radial Gradient"), static_cast<int>( Qt::RadialGradientPattern ) );
    ui->comboBoxBrush->addItem( tr("Conical Gradient"), static_cast<int>( Qt::ConicalGradientPattern ) );
    ui->comboBoxBrush->addItem( tr("Texture"), static_cast<int>( Qt::TexturePattern ) );
    ui->comboBoxBrush->addItem( tr("Solid"), static_cast<int>( Qt::SolidPattern ) );
    ui->comboBoxBrush->addItem( tr("Horizontal"), static_cast<int>( Qt::HorPattern ) );
    ui->comboBoxBrush->addItem( tr("Vertical"), static_cast<int>( Qt::VerPattern ) );
    ui->comboBoxBrush->addItem( tr("Cross"), static_cast<int>( Qt::CrossPattern ) );
    ui->comboBoxBrush->addItem( tr("Backward Diagonal"), static_cast<int>( Qt::BDiagPattern ) );
    ui->comboBoxBrush->addItem( tr("Forward Diagonal"), static_cast<int>( Qt::FDiagPattern ) );
    ui->comboBoxBrush->addItem( tr("Diagonal Cross"), static_cast<int>( Qt::DiagCrossPattern ) );
    ui->comboBoxBrush->addItem( tr("Dense 1"), static_cast<int>( Qt::Dense1Pattern ) );
    ui->comboBoxBrush->addItem( tr("Dense 2"), static_cast<int>( Qt::Dense2Pattern ) );
    ui->comboBoxBrush->addItem( tr("Dense 3"), static_cast<int>( Qt::Dense3Pattern ) );
    ui->comboBoxBrush->addItem( tr("Dense 4"), static_cast<int>( Qt::Dense4Pattern ) );
    ui->comboBoxBrush->addItem( tr("Dense 5"), static_cast<int>( Qt::Dense5Pattern ) );
    ui->comboBoxBrush->addItem( tr("Dense 6"), static_cast<int>( Qt::Dense6Pattern ) );
    ui->comboBoxBrush->addItem( tr("Dense 7"), static_cast<int>( Qt::Dense7Pattern ) );
    ui->comboBoxBrush->addItem( tr("None"), static_cast<int>( Qt::NoBrush ) );

    this->connect(ui->comboBoxShape, &QComboBox::activated, this, &MainWindow::shapeChanged );
    this->connect(ui->spinBoxPenWidth, &QSpinBox::valueChanged, this, &MainWindow::penChanged );
    this->connect(ui->comboBoxPenStyle, &QComboBox::activated, this, &MainWindow::penChanged );
    this->connect(ui->comboBoxPenCap, &QComboBox::activated, this, &MainWindow::penChanged );
    this->connect(ui->comboBoxPenJoin, &QComboBox::activated, this, &MainWindow::penChanged );
    this->connect(ui->comboBoxBrush, &QComboBox::activated, this, &MainWindow::brushChanged );
    this->connect(ui->checkBoxAntialiasing, &QAbstractButton::toggled, ui->renderArea, &RenderArea::setAntialiased );
    this->connect(ui->checkBoxTransformations, &QAbstractButton::toggled, ui->renderArea, &RenderArea::setTransformed );

    this->shapeChanged();
    this->penChanged();
    this->brushChanged();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::shapeChanged()
{
    RenderArea::Shape shape = RenderArea::Shape( ui->comboBoxShape->itemData( ui->comboBoxShape->currentIndex(),Qt::UserRole).toInt() );
    ui->renderArea->setShape( shape );
}

void MainWindow::penChanged()
{
    int width = ui->spinBoxPenWidth->value();
    Qt::PenStyle style = Qt::PenStyle( ui->comboBoxPenStyle->itemData( ui->comboBoxPenStyle->currentIndex(), Qt::UserRole).toInt() );
    Qt::PenCapStyle cap = Qt::PenCapStyle( ui->comboBoxPenCap->itemData( ui->comboBoxPenCap->currentIndex(), Qt::UserRole).toInt() );
    Qt::PenJoinStyle join = Qt::PenJoinStyle( ui->comboBoxPenStyle->itemData( ui->comboBoxPenStyle->currentIndex(), Qt::UserRole).toInt() );
    ui->renderArea->setPen( QPen( Qt::blue, width, style, cap, join ) );

}

void MainWindow::brushChanged()
{
    Qt::BrushStyle style = Qt::BrushStyle( ui->comboBoxBrush->itemData( ui->comboBoxBrush->currentIndex(), Qt::UserRole).toInt() );
    //qDebug() << "haha";
    //qDebug() << "style = " << style;
    if ( style == Qt::LinearGradientPattern )
    {
        QLinearGradient linearGradient( 0, 0, 100, 100 );
        linearGradient.setColorAt( 0.0, Qt::white );
        linearGradient.setColorAt( 0.2, Qt::green );
        linearGradient.setColorAt( 1.0, Qt::black );
        ui->renderArea->setBrush( linearGradient );
        //qDebug() << "style == Qt::LinearGradientPattern";
    }
    else if ( style == Qt::RadialGradientPattern )
    {
        QRadialGradient radialGradient( 50, 50, 50, 70, 70 );
        radialGradient.setColorAt( 0.0, Qt::white );
        radialGradient.setColorAt( 0.2, Qt::green );
        radialGradient.setColorAt( 1.0, Qt::black );
        ui->renderArea->setBrush( radialGradient );
    }
    else if ( style == Qt::ConicalGradientPattern )
    {
        QConicalGradient conicalGradient( 50, 50, 150 );
        conicalGradient.setColorAt( 0.0, Qt::white );
        conicalGradient.setColorAt( 0.2, Qt::green );
        conicalGradient.setColorAt( 1.0, Qt::black );
        ui->renderArea->setBrush( conicalGradient );
    }
    else if ( style == Qt::TexturePattern )
    {
        ui->renderArea->setBrush( QBrush( QPixmap("../images/boat.png") ) );
    }
    else
    {
        ui->renderArea->setBrush( QBrush( Qt::green, style ) );
    }

}

