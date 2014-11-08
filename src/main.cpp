#include <QApplication>
#include "mmmc.h"

int main(int argc, char ** argv) {
    QApplication app(argc, argv);
    app.setOrganizationName("mpharrigan2");
    app.setOrganizationDomain("github.com/mpharrigan2/mmmc");
    app.setApplicationName("mmmc");

    mmmc foo;
    foo.show();
    return app.exec();
}
