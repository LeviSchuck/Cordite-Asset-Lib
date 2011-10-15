#include <boost/filesystem.hpp>

#include "include/real/rresource.h"
#include "include/real/rfilesession.h"

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