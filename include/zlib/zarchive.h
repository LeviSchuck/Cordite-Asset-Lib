#ifndef ZARCHIVE_H
#define ZARCHIVE_H
#include <string>
#include "include/archive.h"

namespace cordite {
  namespace io {
    class ZArchive: public Archive{
    protected:
    public:
      ZArchive(const std::string& path);
      virtual ~ZArchive();
    };
  };
};

#endif // ZARCHIVE_H
