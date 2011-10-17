#ifndef SRESOURCE_H
#define SRESOURCE_H
#include "include/resource.h"
#include <string>
namespace cordite {
  namespace io {
    class SArchive;
    class SResource: public Resource {
      friend class SArchive;
      SResource(std::string& fname, long int& rowid, std::string& dbpath);
      long int _rowid;
      std::string _dbpath;
    public:
      virtual ~SResource();
      FileSession* session();
    };
  };
};


#endif // SRESOURCE_H
