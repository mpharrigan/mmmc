#include "settingsdialog.h"
#include "filelineedit.h"
#include "iconfig.h"


#include <QVBoxLayout>
#include <QList>

SettingsDialog::SettingsDialog(QWidget* parent, Qt::WindowFlags f): QDialog(parent, f)
{
    QList<Config * > configs = makeConfigs();    
    QVBoxLayout * layout = new QVBoxLayout;
    
    for (QList<Config * >::const_iterator ci = configs.constBegin(); ci != configs.constEnd(); ++ci){
        layout->addWidget((*ci)->getWidget());
    }
    setLayout(layout);
    setWindowTitle("Settings");
}

QList<Config * > SettingsDialog::makeConfigs() {
    // Library directory config
    FileLineEdit * fl1 = new FileLineEdit("Library Directory", "", this);
    Config * c1 = new Config("library/directory", fl1, "~/Music/");
    
    //Config 2
    FileLineEdit * fl2 = new FileLineEdit("fl2", "", this);
    Config * c2 = new Config("fl2_key", fl2, "fl2");
    
    // Make list
    QList<Config * > list;
    list << c1 << c2;
    return list;
}


#include "settingsdialog.moc"
