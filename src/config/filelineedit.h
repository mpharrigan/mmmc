#ifndef FILELINEEDIT_H
#define FILELINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class FileLineEdit : public QWidget
{
    Q_OBJECT

public:
    FileLineEdit(const QString & label, const QString & default_val = "", QWidget* parent = 0);
    
private slots:
        void editingFinished();

private:
    QLineEdit * lineEdit;
    QPushButton * browseButton;
    
    QString * savedValue;

public slots:
    void changeConfig(const QVariant &);
    
signals:
    void configChanged(const QVariant &);
};

#endif // FILELINEEDIT_H
