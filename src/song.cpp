#include "song.h"

#include <taglib/tag.h>
#include <taglib/tstring.h>
#include <taglib/fileref.h>
#include <string>
#include <iostream>

#define NOTFOUND ""

Song::Song(const std::string& title, const std::string& artist, const std::string& album)
{

    this->title = title;
    this->artist = artist;
    this->album = album;
}


Song Song::fromMp3(const std::string& filename)
{
    TagLib::FileRef f(filename.c_str());
    TagLib::Tag * tag = f.tag();
    if(tag == NULL) {
        std::cerr<<"Empty Mp3 Tag\n";
        return Song();
    }

    const std::string & title = f.tag()->title().to8Bit();
    const std::string & artist = f.tag()->artist().to8Bit();
    const std::string & album = f.tag()->album().to8Bit();

    return  Song(title, artist, album);
}


