#include "settingsdialog.h"
#include "filelineedit.h"

#include <QHBoxLayout>
#include <QVBoxLayout>

SettingsDialog::SettingsDialog(QWidget* parent, Qt::WindowFlags f): QDialog(parent, f)
{

    FileLineEdit * fl1 = new FileLineEdit("Fl1", this);
    FileLineEdit * fl2 = new FileLineEdit("Fl2", this);

    QVBoxLayout * layout = new QVBoxLayout;
    layout->addWidget(fl1);
    layout->addWidget(fl2);

    setLayout(layout);
}


#include "settingsdialog.moc"
