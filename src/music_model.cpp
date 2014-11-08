#include "music_model.h"

#include <QDebug>

MusicModel::MusicModel(QObject * parent): QAbstractTableModel(parent) {
    library = new Library;
}

void MusicModel::setLibrary(Library * library) {
    beginResetModel();
    qDebug() << "Setting library" << library->songs->size();
    this->library = library;
    endResetModel();
}

Song MusicModel::getSong(const QModelIndex & index) {
    return library->songs->at(index.row());
}


int MusicModel::rowCount(const QModelIndex & parent) const {
    return library->songs->size();
}

int MusicModel::columnCount(const QModelIndex & parent) const {
    return 3;
}

QVariant MusicModel::data(const QModelIndex & index, int role) const {
    switch (role) {
        case Qt::DisplayRole:
            Song s = library->songs->at(index.row());
            switch (index.column()) {
                case 0:
                    return s.album;
                case 1:
                    return s.artist;
                case 2:
                    return s.title;
                default:
                    return QString("Uh oh!");
            }
    }
    return QVariant();
}


Qt::ItemFlags MusicModel::flags(const QModelIndex & index) const {
    return QAbstractItemModel::flags(index);
}

QVariant MusicModel::headerData(int section, Qt::Orientation orientation, int role) const {

    if (role == Qt::DisplayRole) {
        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0:
                    return QString("Album");
                    break;
                case 1:
                    return QString("Artist");
                    break;
                case 2:
                    return QString("Title");
                    break;
                default:
                    return "Uh oh!";
            }
        }
    }
    return QVariant();
}

MusicModel::~MusicModel()
{ }

#include "music_model.moc"

