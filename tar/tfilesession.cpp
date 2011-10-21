#include "include/tar/tfilesession.h"
#include <iostream>
using namespace std;
namespace cordite {
  namespace io {
    TFileSession::TFileSession(const std::string& path,
	const unsigned long offset,
	const unsigned long size){
      _size = size;
      _offset = offset;
      reader.open(path.c_str());
      reader.seekg(offset);
      pos = reader.tellg();
    }
    TFileSession::~TFileSession(){

    }
    long unsigned int TFileSession::getPos(){
      if(reader.is_open()){
	return (unsigned long)reader.tellg() - _offset;
      }
      return 0;
    }
    long unsigned int TFileSession::getSize(){
      return _size;
    }
    void TFileSession::read(
      char* buffer,
      const long unsigned int sizeToRead){
      if(reader.is_open()){
	reader.read(buffer,sizeToRead);
      }else{
	throw;
      }
      pos+= sizeToRead;
    }
    bool TFileSession::seek(
      const long Position,
      const bool relative){
      long newPos = pos - _offset;
      if(!relative){
	if(Position > _size)
	  throw;
	if(Position < 0)
	  throw;
	newPos += Position;
      }else{
	newPos += Position;
	if(newPos < _offset)
	  throw;
	if(newPos > _offset + _size)
	  throw;
      }
      reader.seekg(newPos);
    }

  };
};
