#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QList>
#include "iconfig.h"

class SettingsDialog : public QDialog {
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget * parent = 0, Qt::WindowFlags f = 0);

private:
    QList<Config * > makeConfigs();
};

#endif // SETTINGSDIALOG_H
