#include "iconfig.h"

#include <QDebug>
#include <QSettings>

Config::Config(const QString & config_key, QWidget * widget, const QVariant & defval): QObject() {
    this->widget = widget;
    this->config_key = config_key;
    
    
    connect(widget, SIGNAL(configChanged(QVariant)),
            this, SLOT(changeConfig(QVariant)));
    connect(this, SIGNAL(configChanged(QVariant)),
            widget, SLOT(changeConfig(QVariant)));
    
    QSettings settings;
    QVariant defvarval = settings.value(config_key, defval);
    emit configChanged(defvarval);
}

QWidget * Config::getWidget() {
    return widget;
}

void Config::changeConfig(const QVariant & val) {
    qDebug() << "Handled config changed" << val;
    QSettings settings;
    settings.setValue(config_key, val);
}


#include "iconfig.moc"