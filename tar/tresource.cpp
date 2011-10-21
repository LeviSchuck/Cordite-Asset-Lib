#include "include/tar/tresource.h"
#include "include/tar/tfilesession.h"
#include <iostream>
#include "include/tar/tarparts.h"
namespace cordite {
  namespace io {
    TResource::TResource(const std::string &tarname,
	const tar_info info,
	const unsigned long &seekpos):
	_info(info),
	_seekpos(seekpos),
	_tarname(tarname){
      type = cordite::io::RT_COMPRESSED;//Not really, but close.
      
    }
    TResource::~TResource(){
    }
    FileSession* TResource::session(){
      TFileSession* nfile = 0;
      nfile = new TFileSession(_tarname, _seekpos, _info.size);
      if(nfile->getSize() > 0)
	return nfile;
      else{
	delete nfile;
	return 0;
      }
    }
    

  };
};
