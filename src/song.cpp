#include "song.h"

#include <taglib/tag.h>
#include <taglib/tstring.h>
#include <taglib/fileref.h>

#include <QDebug>

Song::Song(const QString& title, const QString& artist, const QString& album)
{
    this->title = title;
    this->artist = artist;
    this->album = album;
}


Song Song::fromMp3(const QString & filename)
{
    TagLib::FileRef f(filename.toLatin1());
    TagLib::Tag * tag = f.tag();
    if(tag == NULL) {
        qWarning() << "Empty Mp3 Tag" << filename;
        return Song();
    }

    const QString & title = QString::fromStdWString(f.tag()->title().toWString());
    const QString & artist = QString::fromStdWString(f.tag()->artist().toWString());
    const QString & album = QString::fromStdWString(f.tag()->album().toWString());

    return  Song(title, artist, album);
}


