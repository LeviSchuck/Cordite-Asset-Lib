#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>

#include "include/real/rresource.h"
#include "include/real/rfilesession.h"
#include <iostream>
namespace fs = boost::filesystem;
namespace cordite {
  namespace io {
    RResource::RResource(std::string& filepath){
      type = cordite::io::RT_REAL;
      fs::path p(filepath);
      if(!fs::exists(p))
	return;
      fname = p.filename();
      fullpath = filepath;
      //std::cout << "Preserving " << fullpath << " as " << fname << "\n";
    }
    RResource::~RResource(){
    }
    FileSession* RResource::session(){
      RFileSession* nfile;
      nfile = new RFileSession(fullpath);
      if(nfile->getSize() == 0){
	delete nfile;
	return 0;
      }
      return nfile;
    }
    

  };
};