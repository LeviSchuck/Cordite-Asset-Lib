#include "include/tarc/tcfilesession.h"
#include <iostream>
using namespace std;
namespace cordite {
  namespace io {
    TCFileSession::TCFileSession(const std::string& path){
      
    }
    TCFileSession::~TCFileSession(){

    }
    long unsigned int TCFileSession::getPos(){

      return 0;
    }
    long unsigned int TCFileSession::getSize(){

      return 0;
    }
    void TCFileSession::read(
      char* buffer,
      const long unsigned int sizeToRead){

    }
    bool TCFileSession::seek(
      const long Position,
      const bool relative){

    }

  };
};
