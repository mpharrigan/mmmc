

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>
#include "music_model.h"
#include "song.h"

class MainWidget :  public QWidget {
    Q_OBJECT


public:
    MainWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);
    virtual QSize sizeHint() const;
    void play(const QString & filename);
    void play(const Song & song);
    MusicModel * tableModel;

private slots:
    void updatePos(qint64 value);
    void updateMax(qint64 value);
    void doubleClickRow(const QModelIndex & index);

private:
    QSlider * slider;
    QPushButton * playButton;

};

#endif // MAINWIDGET_H
