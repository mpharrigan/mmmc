#ifndef mmmc_H
#define mmmc_H

#include <QtGui/QMainWindow>
#include <QtGui/QLabel>

class mmmc : public QMainWindow
{
    Q_OBJECT
public:
    mmmc();
    virtual ~mmmc();
private slots:
    void open();
private:
    void createMenus();
};

#endif // mmmc_H
