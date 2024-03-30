 #include <QCoreApplication>

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     return a.exec();
// }

//#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    //QApplication app(argc, argv);

    QLabel label("Hello, World!");
    label.show();

    return app.exec();
}
