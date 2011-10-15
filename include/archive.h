#ifndef ARCHIVE_H
#define ARCHIVE_H
#include <map>
#include <string>
#include <set>
#include "resource.h"
namespace cordite {
  namespace io {
    class Archive{
    protected:
      std::map<std::string, Resource*> contents;
      std::set<std::string> fnames;
    public:
      //Resource* getResource(const std::string fname) const;
      Resource* operator[] (const std::string fname);
      virtual ~Archive();
    }; 
  };
};


#endif // ARCHIVE_H
