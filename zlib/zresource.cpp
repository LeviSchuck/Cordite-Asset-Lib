#include "include/zlib/zresource.h"
#include "include/zlib/zfilesession.h"
#include <iostream>
namespace cordite {
  namespace io {
    ZResource::ZResource(std::string& filepath){
      type = cordite::io::RT_DB;

    }
    ZResource::~ZResource(){
    }
    FileSession* ZResource::session(){
      ZFileSession* nfile = 0;

      return nfile;
    }
    

  };
};
