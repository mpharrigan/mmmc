#ifndef mmmc_H
#define mmmc_H

#include <QMainWindow>
#include <QLabel>
#include "mainwidget.h"
#include "library.h"
#include "config/settingsdialog.h"

class mmmc : public QMainWindow
{
    Q_OBJECT
public:
    mmmc();
    virtual ~mmmc();
private slots:
    void open();
    void loadDirectory();
    void showSettings();
private:
    MainWidget * mainWidget;
    SettingsDialog * settingsDialog;
    void createMenus();
};

#endif // mmmc_H
