#include "include/sqlite/sfilesession.h"
#include <iostream>
using namespace std;
namespace cordite {
  namespace io {
    SFileSession::SFileSession(const std::string& path){
      
    }
    SFileSession::~SFileSession(){

    }
    long unsigned int SFileSession::getPos(){

      return 0;
    }
    long unsigned int SFileSession::getSize(){

      return 0;
    }
    void SFileSession::read(
      char* buffer,
      const long unsigned int sizeToRead){

    }
    bool SFileSession::seek(
      const long Position,
      const bool relative){

    }

  };
};