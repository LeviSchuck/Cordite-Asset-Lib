#include "include/sqlite/sresource.h"
#include "include/sqlite/sfilesession.h"
#include <iostream>
namespace cordite {
  namespace io {
    SResource::SResource(std::string& filepath){
      type = cordite::io::RT_DB;

    }
    SResource::~SResource(){
    }
    FileSession* SResource::session(){
      SFileSession* nfile = 0;

      return nfile;
    }
    

  };
};