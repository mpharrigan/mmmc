#ifndef mmmc_H
#define mmmc_H

#include <QMainWindow>
#include <QLabel>

class mmmc : public QMainWindow
{
    Q_OBJECT
public:
    mmmc();
    virtual ~mmmc();
private slots:
    void open();
    void updatePos(qint64);
private:
    void createMenus();
};

#endif // mmmc_H
