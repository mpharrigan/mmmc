#ifndef music_model_H
#define music_model_H

#include <QAbstractTableModel>

class MusicModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    MusicModel(QObject* parent = 0);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QVariant headerData(const QModelIndex & index, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex & index) const;
    virtual ~MusicModel();
};

#endif // music_model_H
