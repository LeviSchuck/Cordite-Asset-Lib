#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <queue>
#include "include/sqlite/sarchive.h"
#include "include/sqlite/sresource.h"
#include <iostream>
namespace fs = boost::filesystem;
namespace cordite{
  namespace io {
    SArchive::SArchive(const std::string& path){
      //Do archiving;
    }
    
    SArchive::~SArchive(){
      //clean up
    }
    
  };
};