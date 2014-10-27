#ifndef FILELINEEDIT_H
#define FILELINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class FileLineEdit : public QWidget
{
    Q_OBJECT

public:
    FileLineEdit(const QString&, QWidget* parent = 0);

private:
    QLineEdit * lineEdit;
    QPushButton * browseButton;
};

#endif // FILELINEEDIT_H
