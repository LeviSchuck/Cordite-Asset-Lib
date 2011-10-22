#ifndef ZRESOURCE_H
#define ZRESOURCE_H
#include "include/resource.h"
#include <string>
namespace cordite {
  namespace io {
    class ZArchive;
    class ZResource: public Resource {
      friend class ZArchive;
      ZResource(std::string& filepath);
    public:
      virtual ~ZResource();
      FileSession* session();
    };
  };
};


#endif // ZRESOURCE_H
