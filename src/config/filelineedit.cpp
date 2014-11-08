#include "filelineedit.h"

#include <QHBoxLayout>
#include <QDebug>
#include <QLabel>


FileLineEdit::FileLineEdit(const QString & label,
                           const QString & default_val,
                           QWidget * parent): QWidget(parent) {
    savedValue = new QString(default_val);
    lineEdit = new QLineEdit(default_val, parent);
    connect(lineEdit, SIGNAL(editingFinished()),
            this, SLOT(editingFinished()));

    browseButton = new QPushButton("Browse", parent);
    QLabel * labelLabel = new QLabel(label);

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(labelLabel);
    layout->addWidget(lineEdit);
    layout->addWidget(browseButton);

    setLayout(layout);
}

void FileLineEdit::editingFinished() {
    qDebug() << "Editing finished";

    if (lineEdit->text() != savedValue) {
        delete savedValue;
        savedValue = new QString(lineEdit->text());
        qDebug() << "Detected that value is different";
        emit configChanged(QVariant(lineEdit->text()));
    }

}

void FileLineEdit::changeConfig(const QVariant & val) {
    qDebug() << "Changing config on FileLineEdit" << val;
    delete savedValue;
    savedValue = new QString(val.toString());
    lineEdit->setText(val.toString());

}


#include "filelineedit.moc"
