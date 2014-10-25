
#ifndef SONG_H
#define SONG_H

#include <string>

class Song
{
public:
  Song(const std::string & title = "", const std::string & artist = "", const std::string & album = "");
  static Song fromMp3(const std::string& filename);
    std::string artist;
  std::string album;
  std::string title;
private:

};

#endif // SONG_H
