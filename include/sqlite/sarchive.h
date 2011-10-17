#ifndef SARCHIVE_H
#define SARCHIVE_H
#include <string>
#include "include/archive.h"

namespace cordite {
  namespace io {
    class SArchive: public Archive{
    protected:
    public:
      SArchive(const std::string& path);
      virtual ~SArchive();
    };
  };
};

#endif // SARCHIVE_H
