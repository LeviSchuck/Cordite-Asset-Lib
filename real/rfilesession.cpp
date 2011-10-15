#include "include/real/rfilesession.h"
#include <iostream>
using namespace std;
namespace cordite {
  namespace io {
    RFileSession::RFileSession(const std::string& path){
      reader.open(path.c_str());
      size = 0;
    }
    RFileSession::~RFileSession(){
      if(reader.is_open()){
	reader.close();
	cout << "Closing the file\n";
      }else{
	cout << "Reports not open\n";
      }
    }
    long unsigned int RFileSession::getPos(){
      if(reader.is_open())
	return reader.tellg();
      return 0;
    }
    long unsigned int RFileSession::getSize(){
      if(reader.is_open()){
	unsigned long oldpos = reader.tellg();
	if(size == 0){
	  reader.seekg (0, ios::end);
	  size = reader.tellg();
	  reader.seekg(oldpos);
	}
	return size;
      }
      return 0;
    }
    void RFileSession::read(
      char* buffer,
      const long unsigned int sizeToRead){
      if(reader.is_open()){
	reader.read(buffer,sizeToRead);
      }else{
	throw;
      }
    }
    bool RFileSession::seek(
      const long Position,
      const bool relative){
      if(!reader.is_open())
	throw;
      long newpos = Position;
      if(!relative){
	if(Position > getSize()){
	  throw;
	}
      }else{
	newpos = Position + getPos();
	if(newpos < 0 || newpos > getSize()){
	  throw;
	}
      }
      reader.seekg(newpos);
    }

  };
};