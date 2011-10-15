#ifndef RRESOURCE_H
#define RRESOURCE_H
#include "include/resource.h"
#include <string>
namespace cordite {
  namespace io {
    class RArchive;
    class RResource: public Resource {
      friend class RArchive;
      RResource(std::string& filepath);
    public:
      virtual ~RResource();
      FileSession* session();
    };
  };
};


#endif // RRESOURCE_H
