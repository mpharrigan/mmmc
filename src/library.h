#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>
#include "song.h"

class Library
{
public:
    Library();
    static Library walkFilesystem(std::string base);
    static Library fromDirectory(std::string dir);

    std::vector<Song> *  songs;

};

#endif // LIBRARY_H
