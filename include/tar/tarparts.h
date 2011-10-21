#ifndef TAR_PARTS_H
#define TAR_PARTS_H
#include <string>
#include <cstdio>
#include <cstring>
struct tar_header { //POSIX with ustar
  char filename[100];
  char mode[8];//0777
  char uid[8];//I won't use this
  char gid[8];//nor this.
  char size[12];
  char time[12];
  char checksum[8];
  char flagtype;
  char linkname[100];
  //begin ustar stuff
  char indicator[6];//ustar
  char version[2];//ustar version 00
  char username[32];//
  char groupname[32];//
  char deviceMajor[8];
  char deviceMinor[8];
  char filenamePrefix[155];
};
enum typeflag {
  TF_REGULAR = '0',
  TF_AREGULAR = '\0',
  TF_LINK = '1',
  TF_SYMBOLIC,
  TF_CHARACTER,
  TF_BLOCK,
  TF_DIRECTORY,
  TF_FIFO,
  TF_CONTINUOUS
};
class tar_info {
public:
  std::string filename;
  unsigned int size;
  unsigned int time;
  unsigned int checksum;
  typeflag type;
  tar_info(tar_header& h){
    filename = h.filename;
    size = time = checksum = 0;
    sscanf(h.size, "%o %o %o",&size, &time, &checksum);
    type = (typeflag)h.flagtype;
  }
  tar_info(){}
  ~tar_info(){}
};

#endif