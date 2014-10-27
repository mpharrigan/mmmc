#ifndef mmmc_H
#define mmmc_H

#include <QMainWindow>
#include <QLabel>
#include "mainwidget.h"
#include "library.h"

class mmmc : public QMainWindow
{
    Q_OBJECT
public:
    mmmc();
    virtual ~mmmc();
private slots:
    void open();
    void loadDirectory();
private:
    MainWidget * mainWidget;
    void createMenus();
};

#endif // mmmc_H
