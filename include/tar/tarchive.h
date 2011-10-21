#ifndef TARCHIVE_H
#define TARCHIVE_H
#include <string>
#include "include/archive.h"

namespace cordite {
  namespace io {
    class TArchive: public Archive{
    protected:
    public:
      TArchive(const std::string& path);
      virtual ~TArchive();
    };
  };
};

#endif // ZARCHIVE_H
