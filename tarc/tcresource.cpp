#include "include/tarc/tcresource.h"
#include "include/tarc/tcfilesession.h"
#include <iostream>
namespace cordite {
  namespace io {
    TCResource::TCResource(std::string& filepath){
      type = cordite::io::RT_COMPRESSED;

    }
    TCResource::~TCResource(){
    }
    FileSession* TCResource::session(){
      TCFileSession* nfile = 0;

      return nfile;
    }
    

  };
};
