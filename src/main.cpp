#include <QApplication>
#include "mmmc.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    mmmc foo;
    foo.show();
    return app.exec();
}
