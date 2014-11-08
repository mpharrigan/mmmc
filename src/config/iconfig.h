#ifndef ICONFIG_H
#define ICONFIG_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QVariant>

class Config : public QObject {

    Q_OBJECT

public:
    Config(const QString & config_key, QWidget * widget, const QVariant & defval);
    QWidget * getWidget();

private:
    QWidget * widget;
    QString config_key;

private slots:
    void changeConfig(const QVariant & val);

signals:
    void configChanged(const QVariant & val);

};


#endif // ICONFIG_H
