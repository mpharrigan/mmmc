
#ifndef SONG_H
#define SONG_H

#include <QString>

class Song
{
public:
    Song(const QString & title = "", const QString & artist = "", const QString & album = "");
    static Song fromMp3(const QString & filename);
    QString artist;
    QString album;
    QString title;
private:

};

#endif // SONG_H
