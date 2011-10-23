#include "include/tarc/tcresource.h"
#include "include/tarc/tcfilesession.h"
#include <iostream>

namespace cordite {
  namespace io {
    TCResource::TCResource(archive_info& ai){
      type = cordite::io::RT_COMPRESSED;
      _ai = ai;
      /*std::cout << _ai.info.filename << "\t" <<
      _ai.info.size << "\t" << _ai.offset << "\t" <<
      _ai.path << "\n";*/
    }
    TCResource::~TCResource(){
    }
    FileSession* TCResource::session(){
      TCFileSession* nfile = 0;
      nfile = new TCFileSession(_ai);
      return nfile;
    }
    

  };
};
