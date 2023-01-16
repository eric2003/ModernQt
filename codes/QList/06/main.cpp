#include <QApplication>

class Book {
public:
    Book( const QString & author, const QString title );
    QString getAuthor() const;
    QString getTitle() const;
private:
    QString author;
    QString title;
};

Book::Book( const QString & author, const QString title )
{
    this->author = author;
    this->title = title;
}

QString Book::getAuthor() const
{
    return this->author;
}

QString Book::getTitle() const
{
    return this->title;
}

bool compareByTitle( const Book & b1, const Book & b2 ) {
    return b1.getTitle() < b2.getTitle();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextStream out( stdout );
    QList<Book> books = {
        Book{"Jack London", "The Call of the Wild"},
        Book{"Leo Tolstoy", "War and Peace"},
        Book{"Gustave Flaubert", "Sentimental education"},
        Book{"Guy de Maupassant", "Une vie"},
        Book{"William Shakespeare", "Hamlet"}
    };

    std::sort( books.begin(), books.end(), compareByTitle );

    for ( const Book& book : books )
    {
        out << book.getAuthor() << ":" << book.getTitle() << Qt::endl;
    }
    return a.exec();
}
