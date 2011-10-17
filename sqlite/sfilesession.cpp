#include "include/sqlite/sfilesession.h"
#include <iostream>
#include <sqlite3.h>
using namespace std;
namespace cordite {
  namespace io {
    SFileSession::SFileSession(){
      pos = 0;
      b = 0;
      size = 0;
      db = 0;
    }
    SFileSession::~SFileSession(){
      if(b){
	sqlite3_blob_close(b);
	sqlite3_close(db);
      }
    }
    long unsigned int SFileSession::getPos(){
      return pos;
    }
    long unsigned int SFileSession::getSize(){
      if(size != 0)
	return size;
      if(b){
	size = sqlite3_blob_bytes(b);
	return size;
      }
      return 0;
    }
    void SFileSession::read(
      char* buffer,
      const long unsigned int sizeToRead){
      if(!b)
	return;
      sqlite3_blob_read(b,buffer,sizeToRead,pos);
      pos+= sizeToRead;
    }
    bool SFileSession::seek(
      const long Position,
      const bool relative){
      unsigned long int oldpos = pos;
      if(relative)
	pos += Position;
      else
	pos = Position;
      if(pos > getSize()){
	pos = oldpos;
	return false;
      }
      return true;
    }

  };
};