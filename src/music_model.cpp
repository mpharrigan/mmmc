#include "music_model.h"


MusicModel::MusicModel(QObject* parent): QAbstractTableModel(parent)
{}


int MusicModel::rowCount(const QModelIndex& parent) const
{
    return 2;
}


int MusicModel::columnCount(const QModelIndex& parent) const
{
    return 3;
}

QVariant MusicModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole) {
        return QString("Row%1, Column%2").arg(index.row() + 1).arg(index.column()+1);
    }
    return QVariant();
}


Qt::ItemFlags MusicModel::flags(const QModelIndex& index) const
{
    return QAbstractItemModel::flags(index);
}

QVariant MusicModel::headerData(const QModelIndex& index, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

MusicModel::~MusicModel()
{

}

#include "music_model.moc"

