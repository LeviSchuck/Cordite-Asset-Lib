#ifndef TCRESOURCE_H
#define TCRESOURCE_H
#include "include/resource.h"
#include <string>
#include "tarparts.h"
namespace cordite {
  namespace io {
    class TCArchive;
    class TCResource: public Resource {
      friend class TCArchive;
      TCResource(archive_info& ai);
      archive_info _ai;
    public:
      virtual ~TCResource();
      FileSession* session();
    };
  };
};


#endif // TCRESOURCE_H
