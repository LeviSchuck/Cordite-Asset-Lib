#include "include/zlib/zfilesession.h"
#include <iostream>
using namespace std;
namespace cordite {
  namespace io {
    ZFileSession::ZFileSession(const std::string& path){
      
    }
    ZFileSession::~ZFileSession(){

    }
    long unsigned int ZFileSession::getPos(){

      return 0;
    }
    long unsigned int ZFileSession::getSize(){

      return 0;
    }
    void ZFileSession::read(
      char* buffer,
      const long unsigned int sizeToRead){

    }
    bool ZFileSession::seek(
      const long Position,
      const bool relative){

    }

  };
};
