#ifndef RARCHIVE_H
#define RARCHIVE_H
#include <string>
#include "include/archive.h"

namespace cordite {
  namespace io {
    class RArchive: public Archive{
    protected:
      void traverse(const std::string& path);
      
    public:
      RArchive(const std::string& path);
      virtual ~RArchive();
    };
  };
};

#endif // RARCHIVE_H
