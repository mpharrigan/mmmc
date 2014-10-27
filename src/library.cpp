
#include "library.h"
#include "song.h"
#include <QDir>
#include <QDebug>

#include <vector>

Library::Library()
{
    songs = new std::vector<Song>();
}

Library::Library(std::vector<Song> * songs) {
    this->songs = songs;
}


Library * Library::fromDirectory(const QString& dir)
{
    QDir qdir(dir);
    qdir.setFilter(QDir::Files);
    QStringList nameFilters;
    nameFilters << "*.mp3";
    qdir.setNameFilters(nameFilters);

    QStringList filenames = qdir.entryList();
    std::vector<Song> * songs = new std::vector<Song>(filenames.size());

    for(int i = 0; i < filenames.size(); ++i) {
        QString filename = filenames.at(i);
        Song song = Song::fromMp3(qdir.absoluteFilePath(filename));
        qDebug() << "Made song" << song.title << song.artist << song.album;
        songs->at(i) = song;
    }

    Library * library = new Library(songs);
    return library;
}


Library *  Library::walkFilesystem(const QString& base)
{

}
