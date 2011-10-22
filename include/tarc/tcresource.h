#ifndef TCRESOURCE_H
#define TCRESOURCE_H
#include "include/resource.h"
#include <string>
namespace cordite {
  namespace io {
    class TCArchive;
    class TCResource: public Resource {
      friend class TCArchive;
      TCResource(std::string& filepath);
    public:
      virtual ~TCResource();
      FileSession* session();
    };
  };
};


#endif // TCRESOURCE_H
