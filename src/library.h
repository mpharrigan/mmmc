#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "song.h"

#include <QString>

class Library {
public:
    Library();
    Library(std::vector< Song > * songs);
    static Library * walkFilesystem(const QString & base);
    static Library * fromDirectory(const QString & dir);

    std::vector<Song> * songs;

};

#endif // LIBRARY_H
