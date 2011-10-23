#include "include/tarc/tarparts.h"
#include "include/tarc/tcfilesession.h"
#include <iostream>

using namespace std;
namespace cordite {
  namespace io {
    TCFileSession::TCFileSession(const archive_info& ai): _ai(ai){
      file = gzopen(ai.path.c_str(),"rb");
      gzseek(file,_ai.offset,SEEK_SET);
    }
    TCFileSession::~TCFileSession(){
      gzclose(file);
    }
    long unsigned int TCFileSession::getPos(){
      return gztell(file) - _ai.offset;
    }
    long unsigned int TCFileSession::getSize(){
      return _ai.info.size;
    }
    void TCFileSession::read(
      char *buffer,
      const long unsigned int sizeToRead){
      gzread(file,buffer,sizeToRead);
    }
    bool TCFileSession::seek(
      const long Position,
      const bool relative){
      long newPos = gztell(file) - _ai.offset;
      if(!relative){
	if(Position > _ai.info.size)
	  throw;
	if(Position < 0)
	  throw;
	newPos += Position;
      }else{
	newPos += Position;
	if(newPos < _ai.offset)
	  throw;
	if(newPos > _ai.offset + _ai.info.size)
	  throw;
      }
      return gzseek(file,newPos,SEEK_SET) == newPos;
    }

  };
};
