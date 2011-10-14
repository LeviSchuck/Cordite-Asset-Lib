#ifndef ARCHIVE_H
#define ARCHIVE_H
#include <map>
#include <string>
#include "resource.h"
namespace cordite {
  namespace io {
    class Archive{
    protected:
      std::map<std::string, Resource> contents;
    public:
      //Resource* getResource(const std::string fname) const;
      Resource& operator[] (const std::string fname) const;
    }; 
  };
};


#endif // ARCHIVE_H
