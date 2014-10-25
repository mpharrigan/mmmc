#include "music_model.h"
#include <iostream>

MusicModel::MusicModel(QObject* parent): QAbstractTableModel(parent)
{
    library = new Library;
}

void MusicModel::setLibrary(Library * library)
{
    //delete this->library;
    beginResetModel();
    std::cout<<"Setting library "<<library->songs->size()<<std::endl;
    this->library = library;
    endResetModel();

}


int MusicModel::rowCount(const QModelIndex& parent) const
{
    return library->songs->size();
}


int MusicModel::columnCount(const QModelIndex& parent) const
{
    return 3;
}

QVariant MusicModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole) {
        Song s = library->songs->at(index.row());
        switch(index.column()) {
        case 0:
            return QString::fromStdString(s.album);
            break;
        case 1:
            return QString::fromStdString(s.artist);
            break;
        case 2:
            return QString::fromStdString(s.title);
            break;
        default:
            return QString("Uh oh!");
        }
    }
    return QVariant();
}


Qt::ItemFlags MusicModel::flags(const QModelIndex& index) const
{
    return QAbstractItemModel::flags(index);
}

QVariant MusicModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  
    if(role == Qt::DisplayRole) {
        if(orientation == Qt::Horizontal) {
            switch(section) {
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
{

}

#include "music_model.moc"

