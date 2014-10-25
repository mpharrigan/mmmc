

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSlider>
#include <QPushButton>

class MainWidget :  public QWidget
{
    Q_OBJECT
public:
  MainWidget(QWidget * parent = 0, Qt::WindowFlags f = 0);
    virtual QSize sizeHint() const;
    void play(const QString & filename);
    
private slots:
  void updatePos(qint64 value);
  void updateMax(qint64 value);

private:
  QSlider * slider;
  QPushButton * playButton;
};

#endif // MAINWIDGET_H
