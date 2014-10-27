#include "filelineedit.h"

#include <QHBoxLayout>


FileLineEdit::FileLineEdit(const QString& value, QWidget* parent): QWidget(parent)
{
    lineEdit = new QLineEdit(value, parent);
    browseButton = new QPushButton("Browse", parent);

    QHBoxLayout * layout = new QHBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(browseButton);

    setLayout(layout);
}


#include "filelineedit.moc"
