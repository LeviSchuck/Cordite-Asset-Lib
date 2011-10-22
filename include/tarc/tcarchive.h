#ifndef TCARCHIVE_H
#define TCARCHIVE_H
#include <string>
#include "include/archive.h"

namespace cordite {
  namespace io {
    class TCArchive: public Archive{
    protected:
    public:
      TCArchive(const std::string& path);
      virtual ~TCArchive();
    };
  };
};

#endif // TCARCHIVE_H
