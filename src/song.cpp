#include "song.h"

#include <taglib/tag.h>
#include <taglib/tstring.h>
#include <taglib/fileref.h>
#include <string>
#include <iostream>



#define ARTISTLEN 1024

Song::Song(const std::string & filename)
{
  TagLib::FileRef f(filename.c_str());
  TagLib::String artist = f.tag()->artist();
  std::cout << artist << std::endl;
  

}


