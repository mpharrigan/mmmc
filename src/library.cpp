
#include "library.h"
#include "song.h"
#include <QDir>

#include <iostream>
#include <vector>

Library::Library()
{
    songs = new std::vector<Song>();
}

Library::Library(std::vector<Song> * songs){
  this->songs = songs;
}


Library * Library::fromDirectory(std::string dir)
{
    QDir qdir(QString::fromStdString(dir));
    qdir.setFilter(QDir::Files);
    QStringList nameFilters;
    nameFilters << "*.mp3";
    qdir.setNameFilters(nameFilters);

    QStringList filenames = qdir.entryList();
    QString filename;
    Song song;
    std::vector<Song> * songs = new std::vector<Song>(filenames.size());

    for(int i = 0; i < filenames.size(); ++i) {
        filename = filenames.at(i);
        song = Song::fromMp3(qdir.absoluteFilePath(filename).toStdString());
        std::cout<<"Song obj:\t" << song.title << '\t' << song.artist << '\t' << song.album <<std::endl;
        songs->at(i) = song;
    }

    Library * library = new Library(songs);
    library->songs = songs;
    return library;
}


Library *  Library::walkFilesystem(std::string base)
{

}
