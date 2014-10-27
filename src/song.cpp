#include "song.h"

#include <taglib/tag.h>
#include <taglib/tstring.h>
#include <taglib/fileref.h>

#include <QDebug>
#include <QFileInfo>
#include <QDir>

Song::Song(const QString& title, const QString& artist, const QString& album)
{
    this->title = title;
    this->artist = artist;
    this->album = album;
    filename = "";
}


Song Song::fromMp3(const QString & filename)
{
    TagLib::FileRef f(filename.toLatin1());
    TagLib::Tag * tag = f.tag();
    if(tag == NULL) {
        qWarning() << "Empty Mp3 Tag" << filename;
	
	// Use filename for title and dirname for album.
	QFileInfo qfil(filename);
	Song s(qfil.fileName(), "", qfil.dir().dirName());
	s.filename = filename;
        return s;
    }

    const QString & title = QString::fromStdWString(f.tag()->title().toWString());
    const QString & artist = QString::fromStdWString(f.tag()->artist().toWString());
    const QString & album = QString::fromStdWString(f.tag()->album().toWString());

    Song s(title, artist, album);
    s.filename = filename;
    return s;
}


